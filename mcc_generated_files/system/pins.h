/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  3.1.0
*/

/*
© [2024] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#ifndef PINS_H
#define PINS_H

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA0 aliases
#define TEMP_SENSOR_TRIS                 TRISAbits.TRISA0
#define TEMP_SENSOR_LAT                  LATAbits.LATA0
#define TEMP_SENSOR_PORT                 PORTAbits.RA0
#define TEMP_SENSOR_WPU                  WPUAbits.
#define TEMP_SENSOR_OD                   ODCONAbits.
#define TEMP_SENSOR_ANS                  ANSELAbits.ANSA0
#define TEMP_SENSOR_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define TEMP_SENSOR_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define TEMP_SENSOR_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define TEMP_SENSOR_GetValue()           PORTAbits.RA0
#define TEMP_SENSOR_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define TEMP_SENSOR_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define TEMP_SENSOR_SetPullup()          do { WPUAbits. = 1; } while(0)
#define TEMP_SENSOR_ResetPullup()        do { WPUAbits. = 0; } while(0)
#define TEMP_SENSOR_SetPushPull()        do { ODCONAbits. = 0; } while(0)
#define TEMP_SENSOR_SetOpenDrain()       do { ODCONAbits. = 1; } while(0)
#define TEMP_SENSOR_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define TEMP_SENSOR_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set RB1 aliases
#define BUTTON_UP_TRIS                 TRISBbits.TRISB1
#define BUTTON_UP_LAT                  LATBbits.LATB1
#define BUTTON_UP_PORT                 PORTBbits.RB1
#define BUTTON_UP_WPU                  WPUBbits.WPUB1
#define BUTTON_UP_OD                   ODCONBbits.
#define BUTTON_UP_ANS                  ANSELBbits.ANSB1
#define BUTTON_UP_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define BUTTON_UP_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define BUTTON_UP_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define BUTTON_UP_GetValue()           PORTBbits.RB1
#define BUTTON_UP_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define BUTTON_UP_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define BUTTON_UP_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define BUTTON_UP_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define BUTTON_UP_SetPushPull()        do { ODCONBbits. = 0; } while(0)
#define BUTTON_UP_SetOpenDrain()       do { ODCONBbits. = 1; } while(0)
#define BUTTON_UP_SetAnalogMode()      do { ANSELBbits.ANSB1 = 1; } while(0)
#define BUTTON_UP_SetDigitalMode()     do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set RB2 aliases
#define BUTTON_DOWN_TRIS                 TRISBbits.TRISB2
#define BUTTON_DOWN_LAT                  LATBbits.LATB2
#define BUTTON_DOWN_PORT                 PORTBbits.RB2
#define BUTTON_DOWN_WPU                  WPUBbits.WPUB2
#define BUTTON_DOWN_OD                   ODCONBbits.
#define BUTTON_DOWN_ANS                  ANSELBbits.ANSB2
#define BUTTON_DOWN_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define BUTTON_DOWN_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define BUTTON_DOWN_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define BUTTON_DOWN_GetValue()           PORTBbits.RB2
#define BUTTON_DOWN_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define BUTTON_DOWN_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define BUTTON_DOWN_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define BUTTON_DOWN_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define BUTTON_DOWN_SetPushPull()        do { ODCONBbits. = 0; } while(0)
#define BUTTON_DOWN_SetOpenDrain()       do { ODCONBbits. = 1; } while(0)
#define BUTTON_DOWN_SetAnalogMode()      do { ANSELBbits.ANSB2 = 1; } while(0)
#define BUTTON_DOWN_SetDigitalMode()     do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set RC0 aliases
#define LED_SYSTEM_TRIS                 TRISCbits.TRISC0
#define LED_SYSTEM_LAT                  LATCbits.LATC0
#define LED_SYSTEM_PORT                 PORTCbits.RC0
#define LED_SYSTEM_WPU                  WPUCbits.
#define LED_SYSTEM_OD                   ODCONCbits.
#define LED_SYSTEM_ANS                  ANSELCbits.
#define LED_SYSTEM_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define LED_SYSTEM_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define LED_SYSTEM_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define LED_SYSTEM_GetValue()           PORTCbits.RC0
#define LED_SYSTEM_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define LED_SYSTEM_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define LED_SYSTEM_SetPullup()          do { WPUCbits. = 1; } while(0)
#define LED_SYSTEM_ResetPullup()        do { WPUCbits. = 0; } while(0)
#define LED_SYSTEM_SetPushPull()        do { ODCONCbits. = 0; } while(0)
#define LED_SYSTEM_SetOpenDrain()       do { ODCONCbits. = 1; } while(0)
#define LED_SYSTEM_SetAnalogMode()      do { ANSELCbits. = 1; } while(0)
#define LED_SYSTEM_SetDigitalMode()     do { ANSELCbits. = 0; } while(0)

// get/set RC2 aliases
#define BUZZER_TRIS                 TRISCbits.TRISC2
#define BUZZER_LAT                  LATCbits.LATC2
#define BUZZER_PORT                 PORTCbits.RC2
#define BUZZER_WPU                  WPUCbits.
#define BUZZER_OD                   ODCONCbits.
#define BUZZER_ANS                  ANSELCbits.ANSC2
#define BUZZER_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define BUZZER_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define BUZZER_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define BUZZER_GetValue()           PORTCbits.RC2
#define BUZZER_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define BUZZER_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define BUZZER_SetPullup()          do { WPUCbits. = 1; } while(0)
#define BUZZER_ResetPullup()        do { WPUCbits. = 0; } while(0)
#define BUZZER_SetPushPull()        do { ODCONCbits. = 0; } while(0)
#define BUZZER_SetOpenDrain()       do { ODCONCbits. = 1; } while(0)
#define BUZZER_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define BUZZER_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set RC3 aliases
#define I2C_SCL_TRIS                 TRISCbits.TRISC3
#define I2C_SCL_LAT                  LATCbits.LATC3
#define I2C_SCL_PORT                 PORTCbits.RC3
#define I2C_SCL_WPU                  WPUCbits.
#define I2C_SCL_OD                   ODCONCbits.
#define I2C_SCL_ANS                  ANSELCbits.ANSC3
#define I2C_SCL_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define I2C_SCL_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define I2C_SCL_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define I2C_SCL_GetValue()           PORTCbits.RC3
#define I2C_SCL_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define I2C_SCL_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define I2C_SCL_SetPullup()          do { WPUCbits. = 1; } while(0)
#define I2C_SCL_ResetPullup()        do { WPUCbits. = 0; } while(0)
#define I2C_SCL_SetPushPull()        do { ODCONCbits. = 0; } while(0)
#define I2C_SCL_SetOpenDrain()       do { ODCONCbits. = 1; } while(0)
#define I2C_SCL_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define I2C_SCL_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set RC4 aliases
#define I2C_SDA_TRIS                 TRISCbits.TRISC4
#define I2C_SDA_LAT                  LATCbits.LATC4
#define I2C_SDA_PORT                 PORTCbits.RC4
#define I2C_SDA_WPU                  WPUCbits.
#define I2C_SDA_OD                   ODCONCbits.
#define I2C_SDA_ANS                  ANSELCbits.ANSC4
#define I2C_SDA_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define I2C_SDA_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define I2C_SDA_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define I2C_SDA_GetValue()           PORTCbits.RC4
#define I2C_SDA_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define I2C_SDA_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define I2C_SDA_SetPullup()          do { WPUCbits. = 1; } while(0)
#define I2C_SDA_ResetPullup()        do { WPUCbits. = 0; } while(0)
#define I2C_SDA_SetPushPull()        do { ODCONCbits. = 0; } while(0)
#define I2C_SDA_SetOpenDrain()       do { ODCONCbits. = 1; } while(0)
#define I2C_SDA_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define I2C_SDA_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set RC6 aliases
#define UART_TX_TRIS                 TRISCbits.TRISC6
#define UART_TX_LAT                  LATCbits.LATC6
#define UART_TX_PORT                 PORTCbits.RC6
#define UART_TX_WPU                  WPUCbits.
#define UART_TX_OD                   ODCONCbits.
#define UART_TX_ANS                  ANSELCbits.ANSC6
#define UART_TX_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define UART_TX_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define UART_TX_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define UART_TX_GetValue()           PORTCbits.RC6
#define UART_TX_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define UART_TX_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define UART_TX_SetPullup()          do { WPUCbits. = 1; } while(0)
#define UART_TX_ResetPullup()        do { WPUCbits. = 0; } while(0)
#define UART_TX_SetPushPull()        do { ODCONCbits. = 0; } while(0)
#define UART_TX_SetOpenDrain()       do { ODCONCbits. = 1; } while(0)
#define UART_TX_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define UART_TX_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set RC7 aliases
#define UART_RX_TRIS                 TRISCbits.TRISC7
#define UART_RX_LAT                  LATCbits.LATC7
#define UART_RX_PORT                 PORTCbits.RC7
#define UART_RX_WPU                  WPUCbits.
#define UART_RX_OD                   ODCONCbits.
#define UART_RX_ANS                  ANSELCbits.ANSC7
#define UART_RX_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define UART_RX_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define UART_RX_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define UART_RX_GetValue()           PORTCbits.RC7
#define UART_RX_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define UART_RX_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define UART_RX_SetPullup()          do { WPUCbits. = 1; } while(0)
#define UART_RX_ResetPullup()        do { WPUCbits. = 0; } while(0)
#define UART_RX_SetPushPull()        do { ODCONCbits. = 0; } while(0)
#define UART_RX_SetOpenDrain()       do { ODCONCbits. = 1; } while(0)
#define UART_RX_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define UART_RX_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

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
#define HEATER_SetAnalogMode()      do { ANSELEbits.ANSE1 = 1; } while(0)
#define HEATER_SetDigitalMode()     do { ANSELEbits.ANSE1 = 0; } while(0)

/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize (void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handling routine
 * @param none
 * @return none
 */
void PIN_MANAGER_IOC(void);


#endif // PINS_H
/**
 End of File
*/