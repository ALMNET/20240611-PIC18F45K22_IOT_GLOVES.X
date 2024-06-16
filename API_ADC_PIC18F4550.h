/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef API_ADC_PIC18F4550_H
#define	API_ADC_PIC18F4550_H

#include <xc.h> // include processor files - each processor file is guarded.  

#include <stdint.h>

#include "configuration.h"

void ADC_Init();
uint16_t ADC_Read(unsigned char channel);


#endif	/* API_ADC_PIC18F4550_H */

