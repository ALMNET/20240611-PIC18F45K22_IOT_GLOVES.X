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

#ifndef _XTAL_FREQ
#define _XTAL_FREQ 8000000
#endif

////////////////////////////////////////////

#define TXCHECK			0x00    // Return 0x0F to indicate the communications is working
#define INSTRUCT_READ_TEMP		0x01    // Read ADC Channel 1 and return ADCH

#define INSTRUCT_SET_HEATER		0x0A    // Write the received integer to OCR1C, return 0x0B

#define START_INSTRUCTION	0x53
#define STOP_INSTRUCTION	0xAA


#endif	/* CONFIGURATION_H */

