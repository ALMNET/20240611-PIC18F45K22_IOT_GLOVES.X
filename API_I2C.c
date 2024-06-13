/*
 * File:   API_I2C.c
 * Author: arman
 *
 * Created on June 12, 2024, 7:51 PM
 */


#include <xc.h>
#include "API_I2C.h"

































void I2C1_Initialize_Bare_Metal(void)
{
    /* I2C Master Mode: Clock = F_OSC / (4 * (SSP1ADD + 1)) */
    SSP1CON1bits.SSPM3 = 1;
    
    /* Set the boud rate devider to obtain the I2C clock at 100000 Hz*/
    SSP1ADD  = 0x9F;
}

static void I2C1_interruptFlagPolling(void)
{
    /* Polling Interrupt Flag */
    
    while (!PIR1bits.SSP1IF)
    {
        ;
    }

    /* Clear Interrupt Flag */
    PIR1bits.SSP1IF = 0;
}

static void I2C1_open(void)
{
    /* Clear IRQ */
    PIR1bits.SSP1IF = 0;

    /* I2C Master Open */
    SSP1CON1bits.SSPEN = 1;
}

static void I2C1_close(void)
{
    /* Disable I2C1 */
    SSP1CON1bits.SSPEN = 0;
}

static void I2C1_startCondition(void)
{
    /* START Condition*/
    SSP1CON2bits.SEN = 1;
    
    I2C1_interruptFlagPolling();
}

static void I2C1_stopCondition(void)
{
    /* STOP Condition */
    SSP1CON2bits.PEN = 1;
    
    I2C1_interruptFlagPolling();
}

static void I2C1_sendData(uint8_t byte)
{
    SSP1BUF  = byte;
    I2C1_interruptFlagPolling();
}

static uint8_t I2C1_getAckstatBit(void)
{
    /* Return ACKSTAT bit */
    return SSP1CON2bits.ACKSTAT;
}

void I2C1_write1ByteRegister(uint8_t address, uint8_t reg, uint8_t data)
{
    /* Shift the 7 bit address and add a 0 bit to indicate write operation */
    uint8_t writeAddress = (uint8_t)((address << 1) & ~I2C_RW_BIT);
    
    I2C1_open();
    I2C1_startCondition();
    
    I2C1_sendData(writeAddress);
    if (I2C1_getAckstatBit())
    {
        return ;
    }
    
    I2C1_sendData(reg);
    if (I2C1_getAckstatBit())
    {
        return ;
    }
    
    I2C1_sendData(data);
    if (I2C1_getAckstatBit())
    {
        return ;
    }
    
    I2C1_stopCondition();
    I2C1_close();
}

// The I2C1_writeNBytes function executes all the steps to write N bytes to the client:
uint8_t I2C1_writeNBytes(uint8_t address, uint8_t reg, uint8_t* data, size_t len)
{
 /* Shift the 7 bit address and add a 0 bit to indicate write operation */
 uint8_t writeAddress = (uint8_t)((address << 1) & (~I2C_RW_BIT));
 uint8_t dataSentSuccessful = 1;

 I2C1_open();
 I2C1_startCondition();

 I2C1_sendData(writeAddress);
 if (I2C1_getAckstatBit())
 {
 /* Handle error */
 dataSentSuccessful = 0;
 }

 I2C1_sendData(reg);
 if (I2C1_getAckstatBit())
 {
 /* Handle error */
 dataSentSuccessful = 0;
 }
 for(uint8_t i = 0; i < len; i++)
 {
 I2C1_sendData(*data++);
 if (I2C1_getAckstatBit())
 {
 /* Handle error */
 dataSentSuccessful = 0;
 }
 }

 I2C1_stopCondition();
 I2C1_close();
 return dataSentSuccessful;
}