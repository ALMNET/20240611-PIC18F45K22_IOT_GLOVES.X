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

void UART_Init();
void UART_init_baud(const long int baudRate);
char UART_Read(void);
void UART_Write(char dato);
void UART_printf(unsigned char *cadena);
void putch(char dato);


#endif	/* API_UART_PIC18F4550_H */

