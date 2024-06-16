/*
 * File:   API_ADC_PIC18F4550.c
 * Author: arman
 *
 * Created on June 15, 2024, 9:33 PM
 */


#include "API_ADC_PIC18F4550.h"

void ADC_Init()
{
    // Configure ADC
    ADCON1bits.VCFG1 = 0;    // VSS as reference voltage
    ADCON1bits.VCFG0 = 0;    // VDD as reference voltage
    
    // Set analog channels (example: AN0 to AN3 as analog)
    ADCON1bits.PCFG = 0b1100; // AN0-AN3 are analog, others are digital
    
    // Configure the ADC clock (Fosc/16, for example)
    ADCON2bits.ADCS = 0b010;
    
    // Configure the acquisition time (2 TAD)
    ADCON2bits.ACQT = 0b001;
    
    // Right justified result
    ADCON2bits.ADFM = 1;
    
    // Turn on the ADC module
    ADCON0bits.ADON = 1;
}

uint16_t ADC_Read(unsigned char channel)
{
    if(channel > 13) // Check if the channel number is valid
        return 0;
    
    // Select the ADC channel
    ADCON0bits.CHS = channel;
    
    // Wait for the acquisition time
    __delay_us(10);
    
    // Start the conversion
    ADCON0bits.GO_DONE = 1;
    
    // Wait for the conversion to complete
    while(ADCON0bits.GO_DONE);
    
    // Return the result (10-bit ADC result)
    return (uint16_t)((ADRESH << 8) + ADRESL);
}

