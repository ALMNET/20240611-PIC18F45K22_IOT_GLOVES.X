/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef API_I2C_H
#define	API_I2C_H

#include <xc.h> // include processor files - each processor file is guarded.  

#include <xc.h>
#include <stdint.h>

// #define CONFIG_DATA_12BIT_RESOLUTION 0x60
#define I2C_RW_BIT 0x01


// The I2C1_Initialize function selects the I2C Host mode and sets the I2C clock frequency to 100 kHz:
void I2C1_Initialize_Bare_Metal(void);

// The I2C1_interruptFlagPolling function waits for the SSP1IF flag to be triggered by the hardware and clears it
static void I2C1_interruptFlagPolling(void);

// The I2C1_open function, opens the I2C bus for read/write communication with a client on the bus. Resets the I2C
// interrupt flag SSP1IF, indicating the host is ready for the next data byte to send/receive. Enables the SSP1 module:
static void I2C1_open(void);

// The I2C1_close function disables the SSP1 module:
static void I2C1_close(void);

// The I2C1_startCondition function sends the Start condition by setting the SEN bit and waits for the SSP1IF flag
// to be triggered:
static void I2C1_startCondition(void);

// The I2C1_stopCondition function sends the Stop condition and waits for the SSP1IF flag to be triggered:
static void I2C1_stopCondition(void);

// The I2C1_sendData function loads in SSP1BUF the argument value and waits for the SSP1IF flag to be triggered:
static void I2C1_sendData(uint8_t byte);

// The I2C1_setReceiveMode function sets the receive enable bit in SSP1CON2, which starts the clock signal so
// that the client can transmit data:
static void I2C1_setReceiveMode(void);

// The I2C1_readData function loads the value from the SSP1BUF into and variable and waits for the SSP1IF flag to
// be triggered:
static uint8_t I2C1_readData(void);

// The I2C1_getAckstatBit function returns the ACKSTAT bit from the SSP1CON2 register. This is used to see if
// the Client responded with an ACK or NACK:
static uint8_t I2C1_getAckstatBit(void);

// The I2C1_sendAcknowledge function sets the acknowledge bit and sends the ACK to the client device:
static void I2C1_sendAcknowledge(void);

// The I2C1_sendNotAcknowledge function clears the acknowledge bit and sends the NACK to the client device:
static void I2C1_sendNotAcknowledge(void);


// The I2C1_write1ByteRegister function executes all the steps to write one byte to the client:
void I2C1_write1ByteRegister(uint8_t address, uint8_t reg, uint8_t data);

// The I2C1_writeNBytes function executes all the steps to write N bytes to the client:
uint8_t I2C1_writeNBytes(uint8_t address, uint8_t reg, uint8_t* data, size_t len);




#endif	/* API_I2C_H */

