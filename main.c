 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.0
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
#include "mcc_generated_files/system/system.h"

#include "configuration.h"

#include "API_I2C.h"
#include "API_OLED_SSD1306.h"

/*
    Main application
*/

char buffer[128];

typedef enum
{
    RELEASED,
    PRESSED
} buttonStatus_t;

void delay_ms(unsigned long delay_value);


int main(void)
{
    SYSTEM_Initialize();
    
    BUTTON_DOWN_SetDigitalMode();
    BUTTON_UP_SetDigitalMode();
    
    BUTTON_DOWN_SetDigitalInput();
    BUTTON_UP_SetDigitalInput();
   
    I2C_Init_Master(I2C_100KHZ);
    OLED_Init();
    
    uint16_t setTemperature = 25;
    uint16_t currentTemperature;
    
    buttonStatus_t buttonDownState = RELEASED;
    buttonStatus_t buttonUpState = RELEASED;
    
    OLED_SetFont(FONT_1);
    
    while(1)
    {
        // Get temperature and calculate to convert from ADC value to 
        // degrees celsius
        currentTemperature = (uint16_t)(ADC_GetConversion(TEMP_SENSOR) * 150 / 308);
        
        // Console Message
        printf("Current Temp: %u, Set Temp: %u\n", currentTemperature, setTemperature);


        OLED_Write_Text(16, 10, "Set Temp:");
        
        sprintf(buffer, "%d C", setTemperature);
        OLED_Write_Text(16, 20, buffer);
        
        sprintf(buffer, "Current Temp:");
        OLED_Write_Text(16, 40, buffer);
        
        sprintf(buffer, "%d C", currentTemperature);
        OLED_Write_Text(16, 50, buffer);
        
        OLED_Update();
        
        //////////////////////////// TEMP DOWN INPUT ///////////////////////////
        
        if(BUTTON_DOWN_GetValue())
        {
//            if(buttonDownState == RELEASED)
//            {
                setTemperature--;
//                buttonDownState = PRESSED;
//            }
            
        }
//        else
//        {
//            buttonDownState = RELEASED;
//        }
        
        ///////////////////////////// TEMP UP INPUT ////////////////////////////
                
        if(BUTTON_UP_GetValue())
        {
//            if(buttonUpState == RELEASED)
//            {
                setTemperature++;
//                buttonUpState = PRESSED;
//            }
            
        }
//        else
//        {
//            buttonUpState = RELEASED;
//        }
        
        
        ///////////////////////////// HEATER CONTROL ///////////////////////////
        
        // Soon will be improved using pwm and control technics
        if(currentTemperature < setTemperature)
        {
            HEATER_SetHigh();
        }
        else
        {
            HEATER_SetLow();
        }
        
        // EUSART1_Write('a');
        
        delay_ms(100);
        
    };
    
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////// AUXILIARY FUNCTIONS /////////////////////////////
///////////////////////////////////////////////////////////////////////////////

// Delay in milliseconds
void delay_ms(unsigned long delay_value){
    for(unsigned long x=0; x < delay_value; x++) __delay_ms(1);
}