/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef CONFIGURATION_H
#define	CONFIGURATION_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdio.h>

// #define _XTAL_FREQ 8000000UL

//////////////////////// I2C PCA9536 DEVICE CONSTANTS  /////////////////////////

// DEVICE ADDRESS FOR PCA9536
#define PCA9536_ADDRESS     0x41

// REGISTERS ADDRESS (TO USE IN messageBuf[2])
#define INPUT_PORT_REG      0x00
#define OUTPUT_PORT_REG     0x01 
#define POL_INVERSION_REG   0x02
#define CONFIGURATION_REG   0x03

// CONFIGURATION REGISTER COMMANDS 
#define ALL_OUTPUTS         0x00
#define ALL_INPUTS          0xFF

#define ALL_PULLUPS         0xFF

// REGISTER COMMANDS FOR OUTPUTS
#define ALL_OUTPUTS_HIGH    0xFF
#define ALL_OUTPUTS_LOW     0x00
#define IO0_HIGH            0x01
#define IO1_HIGH            0x02
#define IO2_HIGH            0x04
#define IO3_HIGH            0x08


#define channel_AN0         0x00
#define channel_AN1         0x01
#define channel_AN4         0x04
#define channel_AN5         0x05
#define channel_AN12        0x0C


//////////////////////// I2C MCP23017 DEVICE CONSTANTS  ////////////////////////


// DEVICE ADDRESS FOR MCP23017 (A0 = 1)
#define MCP23017_ADDRESS    0x21

// registers
#define MCP23017_IODIRA     0x00    // I/O direction register A
#define MCP23017_IPOLA      0x02    // Input polarity port register A
#define MCP23017_GPINTENA   0x04    // Interrupt-on-change pins A
#define MCP23017_DEFVALA    0x06    // Default value register A
#define MCP23017_INTCONA    0x08    // Interrupt-on-change control register A
#define MCP23017_IOCONA     0x0A    // I/O expander configuration register A
#define MCP23017_GPPUA      0x0C    // GPIO pull-up resistor register A
#define MCP23017_INTFA      0x0E    // Interrupt flag register A
#define MCP23017_INTCAPA    0x10    // Interrupt captured value for port register A
#define MCP23017_GPIOA      0x12    // General purpose I/O port register A
#define MCP23017_OLATA      0x14    // Output latch register 0 A

#define MCP23017_IODIRB     0x01    // I/O direction register B
#define MCP23017_IPOLB      0x03    // Input polarity port register B
#define MCP23017_GPINTENB   0x05    // Interrupt-on-change pins B
#define MCP23017_DEFVALB    0x07    // Default value register B
#define MCP23017_INTCONB    0x09    // Interrupt-on-change control register B
#define MCP23017_IOCONB     0x0B    // I/O expander configuration register B
#define MCP23017_GPPUB      0x0D    // GPIO pull-up resistor register B
#define MCP23017_INTFB      0x0F    // Interrupt flag register B
#define MCP23017_INTCAPB    0x11    // Interrupt captured value for port register B
#define MCP23017_GPIOB      0x13    // General purpose I/O port register B
#define MCP23017_OLATB      0x15    // Output latch register 0 B




//////////////////////// I2C MCP23008 DEVICE CONSTANTS  ////////////////////////

// DEVICE ADDRESS FOR MCP23008
#define MCP23008_ADDRESS    0x20

// registers
#define MCP23008_IODIR      0x00
#define MCP23008_IPOL       0x01
#define MCP23008_GPINTEN    0x02
#define MCP23008_DEFVAL     0x03
#define MCP23008_INTCON     0x04
#define MCP23008_IOCON      0x05
#define MCP23008_GPPU       0x06
#define MCP23008_INTF       0x07
#define MCP23008_INTCAP     0x08
#define MCP23008_GPIO       0x09
#define MCP23008_OLAT       0x0A


#define channel_AN0         0x00
#define channel_AN1         0x01
#define channel_AN4         0x04
#define channel_AN5         0x05
#define channel_AN12        0x0C

#endif	/* CONFIGURATION_H */

