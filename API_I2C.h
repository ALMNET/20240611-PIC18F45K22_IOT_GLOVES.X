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
#include <stdio.h>

// #define CONFIG_DATA_12BIT_RESOLUTION 0x60
#define I2C_RW_BIT 0x01

#define I2C_MASTER_MODE

#define TRIS_SCL    TRISCbits.TRISC3
#define TRIS_SDA    TRISCbits.TRISC4

#define I2C_100KHZ 0x80
#define I2C_400KHZ 0x00

#define I2C_MASTER_MODE
//#define I2C_SLAVE_MODE

#ifdef I2C_MASTER_MODE
void I2C_Init_Master(unsigned char sp_i2c);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_Restart(void);
void I2C_Ack(void);
void I2C_Nack(void);
unsigned char I2C_Read(void);
short I2C_Write(char data);
#endif

#ifdef I2C_SLAVE_MODE
void I2C_Init_Slave(unsigned char add_slave);
unsigned char I2C_Read_Slave(void);
void I2C_Write_Slave(char dato_i2c);
void I2C_Error_Data(void);
short I2C_Write_Mode(void);
short I2C_Read_Mode(void);
short I2C_Error_Read(void);
#endif

#endif	/* API_I2C_H */

