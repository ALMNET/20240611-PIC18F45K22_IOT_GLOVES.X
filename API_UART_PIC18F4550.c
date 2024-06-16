/*
 * File:   newmain.c
 * Author: arman
 *
 * Created on June 15, 2024, 11:15 PM
 */

#include "API_UART_PIC18F4550.h"
#include "configuration.h"

void UART_Init(unsigned long baud_rate) 
{
//    TRISCbits.TRISC6 = 0; // Set TX pin as output
//    TRISCbits.TRISC7 = 1; // Set RX pin as input
//    
//    // Baud rate calculation
//    uint8_t baudRateValue = (_XTAL_FREQ / (16 * baud_rate)) - 1;
//    
//    SPBRG = (uint8_t)baudRateValue;  // Load the baud rate value into the SPBRG register
//    TXSTAbits.BRGH = 1;       // Set the BRGH (High-Speed Baud Rate Select bit) to low for 16-bit baud rate generator
//    
//    // Enable serial port (TX and RX)
//    TXSTAbits.SYNC = 0;         // Asynchronous mode
//    RCSTAbits.SPEN = 1;         // Enable serial port
//    TXSTAbits.TXEN = 1;         // Enable transmission
//    RCSTAbits.CREN = 1;         // Enable reception
//    TXSTAbits.TX9 = 0;          //8 BITS
    
     unsigned char valor = (unsigned char)((_XTAL_FREQ/(baud_rate*16)) -1);
    TXSTAbits.BRGH = 1;     //ALTA VELOCIDAD
    
    if(valor>255)
    {
        valor = (unsigned char)((_XTAL_FREQ/(baud_rate*64)) -1);
        TXSTAbits.BRGH = 1;     //ALTA VELOCIDAD
    }
    
    TRISCbits.TRISC7 = 1;   //RX input
    TRISCbits.TRISC6 = 0;   //TX output 
    
    TXSTAbits.SYNC = 0;     //UART
    TXSTAbits.TX9 = 0;      //8 BITS
   
    SPBRG = valor;            //9600 a 20MHZ
    RCSTAbits.SPEN = 1;     //UART on    
    TXSTAbits.TXEN = 1;    //TX on
    RCSTAbits.CREN = 1;     //RX on
}

void UART_Write(char data) {
    TXREG = data; // Transmit data
    while(!TXSTAbits.TRMT); // Wait until the transmit buffer is empty
}

char UART_Read() {
    while(!PIR1bits.RCIF); // Wait until the receive buffer is full
    return RCREG; // Read the received data
}

void UART_Write_Text(char *text) {
    while(*text) {
        UART_Write(*text);
        text++;
    }
}

int getch(void)
{
    return (int)(UART_Read());
}

void putch(char txData)
{
    UART_Write(txData);
}
