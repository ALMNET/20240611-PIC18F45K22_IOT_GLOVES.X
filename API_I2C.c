/*
 * File:   API_I2C.c
 * Author: arman
 *
 * Created on June 12, 2024, 7:51 PM
 */

#include <xc.h>
#include "API_I2C.h"

#if defined(_18LF45K22)

void I2C1_Initialize_Bare_Metal(void)
{
	/* I2C Master Mode: Clock = F_OSC / (4 * (SSP1ADD + 1)) */
	SSP1CON1bits.SSPM3 = 1;

	/* Set the boud rate devider to obtain the I2C clock at 100000 Hz*/
	SSP1ADD = 0x9F;
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

static void i2c_restart() {
    // Send restart condition
    SSPCON2bits.RSEN = 1;
    while(SSPCON2bits.RSEN); // Wait until restart sequence is completed
}

static void I2C1_stopCondition(void)
{
	/* STOP Condition */
	SSP1CON2bits.PEN = 1;

	I2C1_interruptFlagPolling();
}

static void I2C1_sendData(uint8_t byte)
{
	SSP1BUF = byte;
    // while(SSP1STATbits.BF);
	I2C1_interruptFlagPolling();
}

static uint8_t I2C1_getAckstatBit(void)
{
	/* Return ACKSTAT bit */
	return SSP1CON2bits.ACKSTAT;
}


static void I2C1_sendAcknowledge(void)
{
	/* Send ACK bit to client */
	SSP1CON2bits.ACKDT = 0;
	SSP1CON2bits.ACKEN = 1;
    while(SSP1CON2bits.ACKEN);
}


static void I2C1_sendNotAcknowledge(void)
{
 /* Send NACK bit to client */
 SSP1CON2bits.ACKDT = 1;
 SSP1CON2bits.ACKEN = 1;
 while(SSP1CON2bits.ACKEN);
 // I2C1_interruptFlagPolling();
}

static uint8_t I2C1_readData(void)
{    
    
    /* Start receiving mode */
	SSP1CON2bits.RCEN = 1;
    // Wait until the data is received
    while (!SSP1STATbits.BF);
    
	uint8_t data = (uint8_t)SSP1BUF;
	SSP1CON2bits.RCEN = 0;
	return data;
}

uint8_t I2C1_read1ByteRegister(uint8_t address, uint8_t reg)
{
	/* Shift the 7-bit address and add a 0 bit to indicate a write operation */
	uint8_t writeAddress = (uint8_t)((0xFF & (address << 1)) & ~I2C_RW_BIT);
	uint8_t readAddress = (uint8_t)((0xFF & (address << 1)) | I2C_RW_BIT);
	uint8_t dataRead;
	uint8_t dataOperationSuccessful = 1;

	I2C1_open();
	I2C1_startCondition();

	I2C1_sendData(writeAddress);
	if (I2C1_getAckstatBit())
	{
		/* Error occurred */
		dataOperationSuccessful = 0;
	}
    

	I2C1_sendData(reg);
	if (I2C1_getAckstatBit())
	{
		/* Error occurred */
		dataOperationSuccessful = 0;
	}
	
    // I2C1_startCondition();
    i2c_restart();
    

	I2C1_sendData(readAddress);
    printf("sendData(readAddress) -> Ok\n");
    
	if (I2C1_getAckstatBit())
	{
		/* Error occurred */
		dataOperationSuccessful = 0;
	}
    
	dataRead = I2C1_readData();
    
	/* Send NACK bit to stop receiving mode */
	I2C1_sendNotAcknowledge();
    
	I2C1_stopCondition();
	I2C1_close();
   

	return dataRead;
}

uint16_t I2C1_read2ByteRegister(uint8_t address, uint8_t reg)
{
	/* Shift the 7-bit address and add a 0 bit to indicate a write operation */
	uint8_t writeAddress = (uint8_t)((address << 1) & ~I2C_RW_BIT);
	uint8_t readAddress = (uint8_t)((address << 1) | I2C_RW_BIT);
	uint8_t dataRead[2];
	uint8_t dataOperationSuccessful = 1;

	I2C1_open();
	I2C1_startCondition();

	I2C1_sendData(writeAddress);
	if (I2C1_getAckstatBit())
	{
		/* Error occurred */
		dataOperationSuccessful = 0;
	}

	I2C1_sendData(reg);
	if (I2C1_getAckstatBit())
	{
		/* Error occurred */
		dataOperationSuccessful = 0;
	}
	I2C1_startCondition();

	I2C1_sendData(readAddress);
	if (I2C1_getAckstatBit())
	{
		/* Error occurred */
		dataOperationSuccessful = 0;
	}
	I2C1_setReceiveMode();

	dataRead[0] = I2C1_readData();
	/* Send ACK bit to receive byte of data */
	I2C1_sendAcknowledge();

	I2C1_setReceiveMode();
	dataRead[1] = I2C1_readData();
	/* Send NACK bit to stop receiving mode */
	I2C1_sendNotAcknowledge();

	I2C1_stopCondition();
	I2C1_close();

	return (uint16_t)((dataRead[0] << 8) | (dataRead[1]));
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
		return;
	}

	I2C1_sendData(reg);
	if (I2C1_getAckstatBit())
	{
		return;
	}

	I2C1_sendData(data);
	if (I2C1_getAckstatBit())
	{
		return;
	}

	I2C1_stopCondition();
	I2C1_close();
}

// The I2C1_writeNBytes function executes all the steps to write N bytes to the client:
uint8_t I2C1_writeNBytes(uint8_t address, uint8_t reg, uint8_t *data, size_t len)
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
	for (uint8_t i = 0; i < len; i++)
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

#else

void I2C1_Initialize_Bare_Metal(void)
{
	/* I2C Master Mode: Clock = F_OSC / (4 * (SSP1ADD + 1)) */
	SSPCON1bits.SSPM3 = 1;

	/* Set the boud rate devider to obtain the I2C clock at 100000 Hz*/
	SSPADD = 0x9F;
}

static void I2C1_interruptFlagPolling(void)
{
	/* Polling Interrupt Flag */

	while (!PIR1bits.SSPIF)
	{
		;
	}

	/* Clear Interrupt Flag */
	PIR1bits.SSPIF = 0;
}

static void I2C1_open(void)
{
	/* Clear IRQ */
	PIR1bits.SSPIF = 0;

	/* I2C Master Open */
	SSPCON1bits.SSPEN = 1;
}

static void I2C1_close(void)
{
	/* Disable I2C1 */
	SSPCON1bits.SSPEN = 0;
}

static void I2C1_startCondition(void)
{
	/* START Condition*/
	SSPCON2bits.SEN = 1;

	I2C1_interruptFlagPolling();
}

static void i2c_restart() {
    // Send restart condition
    SSPCON2bits.RSEN = 1;
    while(SSPCON2bits.RSEN); // Wait until restart sequence is completed
}

static void I2C1_stopCondition(void)
{
	/* STOP Condition */
	SSPCON2bits.PEN = 1;

	I2C1_interruptFlagPolling();
}

static void I2C1_sendData(uint8_t byte)
{
	SSPBUF = byte;
    // while(SSP1STATbits.BF);
	I2C1_interruptFlagPolling();
}

static uint8_t I2C1_getAckstatBit(void)
{
	/* Return ACKSTAT bit */
	return SSPCON2bits.ACKSTAT;
}


static void I2C1_sendAcknowledge(void)
{
	/* Send ACK bit to client */
	SSPCON2bits.ACKDT = 0;
	SSPCON2bits.ACKEN = 1;
    while(SSPCON2bits.ACKEN);
}


static void I2C1_sendNotAcknowledge(void)
{
 /* Send NACK bit to client */
 SSPCON2bits.ACKDT = 1;
 SSPCON2bits.ACKEN = 1;
 while(SSPCON2bits.ACKEN);
 // I2C1_interruptFlagPolling();
}

static uint8_t I2C1_readData(void)
{    
    
    /* Start receiving mode */
	SSPCON2bits.RCEN = 1;
    // Wait until the data is received
    while (!SSPSTATbits.BF);
    
	uint8_t data = (uint8_t)SSPBUF;
	SSPCON2bits.RCEN = 0;
	return data;
}

uint8_t I2C1_read1ByteRegister(uint8_t address, uint8_t reg)
{
	/* Shift the 7-bit address and add a 0 bit to indicate a write operation */
	uint8_t writeAddress = (uint8_t)((0xFF & (address << 1)) & ~I2C_RW_BIT);
	uint8_t readAddress = (uint8_t)((0xFF & (address << 1)) | I2C_RW_BIT);
	uint8_t dataRead;
	uint8_t dataOperationSuccessful = 1;

	I2C1_open();
	I2C1_startCondition();

	I2C1_sendData(writeAddress);
	if (I2C1_getAckstatBit())
	{
		/* Error occurred */
		dataOperationSuccessful = 0;
	}
    

	I2C1_sendData(reg);
	if (I2C1_getAckstatBit())
	{
		/* Error occurred */
		dataOperationSuccessful = 0;
	}
	
    // I2C1_startCondition();
    i2c_restart();
    

	I2C1_sendData(readAddress);
    printf("sendData(readAddress) -> Ok\n");
    
	if (I2C1_getAckstatBit())
	{
		/* Error occurred */
		dataOperationSuccessful = 0;
	}
    
	dataRead = I2C1_readData();
    
	/* Send NACK bit to stop receiving mode */
	I2C1_sendNotAcknowledge();
    
	I2C1_stopCondition();
	I2C1_close();
   

	return dataRead;
}

uint16_t I2C1_read2ByteRegister(uint8_t address, uint8_t reg)
{
	/* Shift the 7-bit address and add a 0 bit to indicate a write operation */
	uint8_t writeAddress = (uint8_t)((address << 1) & ~I2C_RW_BIT);
	uint8_t readAddress = (uint8_t)((address << 1) | I2C_RW_BIT);
	uint8_t dataRead[2];
	uint8_t dataOperationSuccessful = 1;

	I2C1_open();
	I2C1_startCondition();

	I2C1_sendData(writeAddress);
	if (I2C1_getAckstatBit())
	{
		/* Error occurred */
		dataOperationSuccessful = 0;
	}

	I2C1_sendData(reg);
	if (I2C1_getAckstatBit())
	{
		/* Error occurred */
		dataOperationSuccessful = 0;
	}
	I2C1_startCondition();

	I2C1_sendData(readAddress);
	if (I2C1_getAckstatBit())
	{
		/* Error occurred */
		dataOperationSuccessful = 0;
	}
	I2C1_setReceiveMode();

	dataRead[0] = I2C1_readData();
	/* Send ACK bit to receive byte of data */
	I2C1_sendAcknowledge();

	I2C1_setReceiveMode();
	dataRead[1] = I2C1_readData();
	/* Send NACK bit to stop receiving mode */
	I2C1_sendNotAcknowledge();

	I2C1_stopCondition();
	I2C1_close();

	return (uint16_t)((dataRead[0] << 8) | (dataRead[1]));
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
		return;
	}

	I2C1_sendData(reg);
	if (I2C1_getAckstatBit())
	{
		return;
	}

	I2C1_sendData(data);
	if (I2C1_getAckstatBit())
	{
		return;
	}

	I2C1_stopCondition();
	I2C1_close();
}

// The I2C1_writeNBytes function executes all the steps to write N bytes to the client:
uint8_t I2C1_writeNBytes(uint8_t address, uint8_t reg, uint8_t *data, size_t len)
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
	for (uint8_t i = 0; i < len; i++)
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

#endif