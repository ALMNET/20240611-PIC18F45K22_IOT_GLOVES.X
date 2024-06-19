

#include "configuration.h"

#ifdef _18F45K22
#include "mcc_generated_files/system/system.h"
#else
#include <htc.h>
#include "API_ADC_PIC18F4550.h"
#include "API_UART_PIC18F4550.h"
#endif


#include "API_I2C.h"
#include "API_OLED_SSD1306.h"


////////////////////////////////////////////////////////////////////////////////
/////////////////////////////// VARIABLES //////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// Buffer for OLED Messages
char buffer[128];

// received data byte from uart
char receivedData;




// Button status state machine
typedef enum
{
    RELEASED,
    PRESSED
} buttonStatus_t;

////////////////////////////////////////////////////////////////////////////////
//////////////////////////// LOCAL PROTOTYPES //////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// Simple delay function prototype
void delay_ms(unsigned long delay_value);

////////////////////////////////////////////////////////////////////////////////
///////////////////////////// MAIN FUNCTION ////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

int main(void)
{
    
#ifdef _18F45K22
    SYSTEM_Initialize();
    
    BUTTON_DOWN_SetDigitalMode();
    BUTTON_UP_SetDigitalMode();
    
#else
    UART_init_baud(9600);
    ADC_Init();
    
#endif
    
    BUTTON_DOWN_SetDigitalInput();
    BUTTON_UP_SetDigitalInput();
    
    REMOTE_LOCAL_SELECT_SetDigitalInput();
    
    HEATER_SetDigitalOutput();    

   
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
#ifdef _18F45K22    
        currentTemperature = (uint16_t)(ADC_GetConversion(TEMP_SENSOR) * 150 / 308);
#else   
        currentTemperature = (uint16_t)(ADC_Read(0) * 150 / 308);
#endif  
        // Console Message
        //printf("Current Temp: %u, Set Temp: %u\n", currentTemperature, setTemperature);
        
        UART_Write((uint8_t)(0xFF & currentTemperature));

        OLED_Write_Text(16, 10, "Set Temp:");
        
        sprintf(buffer, "%d C  ", setTemperature);
        OLED_Write_Text(16, 20, buffer);
        
        sprintf(buffer, "Current Temp:");
        OLED_Write_Text(16, 40, buffer);
        
        sprintf(buffer, "%d C  ", currentTemperature);
        OLED_Write_Text(16, 50, buffer);
        
        OLED_Update();
        
        ////////////////////////////////////////////////////////////////////////
        // check if UART received data and if selector is in remote mode
#ifdef _18F45K22
        if((receivedData = EUSART1_Read()) && REMOTE_LOCAL_SELECT_GetValue())
#else
        if((receivedData = UART_Read()) && REMOTE_LOCAL_SELECT_GetValue())
#endif
        {
            switch(receivedData)
            {
                case 'A': // Activate Heater
                    HEATER_SetHigh();
                break;
                    
                case 'D':    // Deactivate heater
                    HEATER_SetLow();
                break;
            }
        }
            
        
        //////////////////////////// TEMP DOWN INPUT ///////////////////////////
        
        if(BUTTON_DOWN_GetValue())
        {
            if(buttonDownState == RELEASED)
            {
                setTemperature--;
                buttonDownState = PRESSED;
            }
            
        }
        else
        {
            buttonDownState = RELEASED;
        }
        
        ///////////////////////////// TEMP UP INPUT ////////////////////////////
                
        if(BUTTON_UP_GetValue())
        {
            if(buttonUpState == RELEASED)
            {
                setTemperature++;
                buttonUpState = PRESSED;
            }
            
        }
        else
        {
            buttonUpState = RELEASED;
        }
        
        
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
        
        // EUSART1_Write('a');.
        
        //UART_Write_Text("HOLA");
        
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