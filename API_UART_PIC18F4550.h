/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef API_UART_PIC18F4550_H
#define	API_UART_PIC18F4550_H

#include <xc.h> // include processor files - each processor file is guarded.  

#include <stdio.h>

void UART_Init(unsigned long baud_rate);
void UART_Write(char data);
char UART_Read();

void UART_Write_Text(char *text);


#endif	/* API_UART_PIC18F4550_H */

