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
#include <stdio.h>      // Allows to use printf functions
#include <stdbool.h>    // Allows to use boolean variables

#ifndef _XTAL_FREQ
#define _XTAL_FREQ 20000000
#endif


#ifdef _18F4550
// PIC18F2550 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1L
#pragma config PLLDIV = 1       // PLL Prescaler Selection bits (No prescale (4 MHz oscillator input drives PLL directly))
#pragma config CPUDIV = OSC1_PLL2// System Clock Postscaler Selection bits ([Primary Oscillator Src: /1][96 MHz PLL Src: /2])
#pragma config USBDIV = 1       // USB Clock Selection bit (used in Full-Speed USB mode only; UCFG:FSEN = 1) (USB clock source comes directly from the primary oscillator block with no postscale)

// CONFIG1H
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator (HS))
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

// CONFIG2L
#pragma config PWRT = OFF        // Power-up Timer Enable bit (PWRT enabled)
#pragma config BOR = OFF        // Brown-out Reset Enable bits (Brown-out Reset disabled in hardware and software)
#pragma config BORV = 3         // Brown-out Reset Voltage bits (Minimum setting 2.05V)
#pragma config VREGEN = OFF     // USB Voltage Regulator Enable bit (USB voltage regulator disabled)

// CONFIG2H
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
#pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits (1:32768)

// CONFIG3H
#pragma config CCP2MX = ON      // CCP2 MUX bit (CCP2 input/output is multiplexed with RC1)
#pragma config PBADEN = ON      // PORTB A/D Enable bit (PORTB<4:0> pins are configured as analog input channels on Reset)
#pragma config LPT1OSC = OFF    // Low-Power Timer 1 Oscillator Enable bit (Timer1 configured for higher power operation)
#pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)

// CONFIG4L
#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
#pragma config LVP = OFF        // Single-Supply ICSP Enable bit (Single-Supply ICSP disabled)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection bit (Block 0 (000800-001FFFh) is not code-protected)
#pragma config CP1 = OFF        // Code Protection bit (Block 1 (002000-003FFFh) is not code-protected)
#pragma config CP2 = OFF        // Code Protection bit (Block 2 (004000-005FFFh) is not code-protected)
#pragma config CP3 = OFF        // Code Protection bit (Block 3 (006000-007FFFh) is not code-protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot block (000000-0007FFh) is not code-protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM is not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection bit (Block 0 (000800-001FFFh) is not write-protected)
#pragma config WRT1 = OFF       // Write Protection bit (Block 1 (002000-003FFFh) is not write-protected)
#pragma config WRT2 = OFF       // Write Protection bit (Block 2 (004000-005FFFh) is not write-protected)
#pragma config WRT3 = OFF       // Write Protection bit (Block 3 (006000-007FFFh) is not write-protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) are not write-protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot block (000000-0007FFh) is not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM is not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection bit (Block 0 (000800-001FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection bit (Block 1 (002000-003FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR2 = OFF      // Table Read Protection bit (Block 2 (004000-005FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR3 = OFF      // Table Read Protection bit (Block 3 (006000-007FFFh) is not protected from table reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot block (000000-0007FFh) is not protected from table reads executed in other blocks)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

////////////////////////////////////////////

// get/set RB4 aliases
#define BUTTON_UP_TRIS                 TRISBbits.TRISB4
#define BUTTON_UP_LAT                  LATBbits.LATB4
#define BUTTON_UP_PORT                 PORTBbits.RB4
#define BUTTON_UP_WPU                  WPUBbits.WPUB4
#define BUTTON_UP_OD                   ODCONBbits.
#define BUTTON_UP_ANS                  ANSELBbits.ANSB4
#define BUTTON_UP_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define BUTTON_UP_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define BUTTON_UP_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define BUTTON_UP_GetValue()           PORTBbits.RB4
#define BUTTON_UP_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define BUTTON_UP_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define BUTTON_UP_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define BUTTON_UP_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define BUTTON_UP_SetPushPull()        do { ODCONBbits. = 0; } while(0)
#define BUTTON_UP_SetOpenDrain()       do { ODCONBbits. = 1; } while(0)

// get/set RB5 aliases
#define BUTTON_DOWN_TRIS                 TRISBbits.TRISB5
#define BUTTON_DOWN_LAT                  LATBbits.LATB5
#define BUTTON_DOWN_PORT                 PORTBbits.RB5
#define BUTTON_DOWN_WPU                  WPUBbits.WPUB5
#define BUTTON_DOWN_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define BUTTON_DOWN_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define BUTTON_DOWN_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define BUTTON_DOWN_GetValue()           PORTBbits.RB5
#define BUTTON_DOWN_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define BUTTON_DOWN_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define BUTTON_DOWN_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define BUTTON_DOWN_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define BUTTON_DOWN_SetPushPull()        do { ODCONBbits. = 0; } while(0)
#define BUTTON_DOWN_SetOpenDrain()       do { ODCONBbits. = 1; } while(0)


// get/set RE1 aliases
#define HEATER_TRIS                 TRISEbits.TRISE1
#define HEATER_LAT                  LATEbits.LATE1
#define HEATER_PORT                 PORTEbits.RE1
#define HEATER_WPU                  WPUEbits.
#define HEATER_OD                   ODCONEbits.
#define HEATER_ANS                  ANSELEbits.ANSE1
#define HEATER_SetHigh()            do { LATEbits.LATE1 = 1; } while(0)
#define HEATER_SetLow()             do { LATEbits.LATE1 = 0; } while(0)
#define HEATER_Toggle()             do { LATEbits.LATE1 = ~LATEbits.LATE1; } while(0)
#define HEATER_GetValue()           PORTEbits.RE1
#define HEATER_SetDigitalInput()    do { TRISEbits.TRISE1 = 1; } while(0)
#define HEATER_SetDigitalOutput()   do { TRISEbits.TRISE1 = 0; } while(0)
#define HEATER_SetPullup()          do { WPUEbits. = 1; } while(0)
#define HEATER_ResetPullup()        do { WPUEbits. = 0; } while(0)
#define HEATER_SetPushPull()        do { ODCONEbits. = 0; } while(0)
#define HEATER_SetOpenDrain()       do { ODCONEbits. = 1; } while(0)

#endif

#define TXCHECK			0x00    // Return 0x0F to indicate the communications is working
#define INSTRUCT_READ_TEMP		0x01    // Read ADC Channel 1 and return ADCH

#define INSTRUCT_SET_HEATER		0x0A    // Write the received integer to OCR1C, return 0x0B

#define START_INSTRUCTION	0x53
#define STOP_INSTRUCTION	0xAA

#endif	/* CONFIGURATION_H */

