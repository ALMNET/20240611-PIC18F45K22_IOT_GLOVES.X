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
#include "API_OLED_SSD1306_FONTS.h"



#define I2C_SLAVE_ADDR                  0x20
#define MCP23008_REG_ADDR_IODIR         0x00
#define MCP23008_REG_ADDR_GPIO          0x09

#ifndef I2C_RW_BIT
#define I2C_RW_BIT                      0x01
#endif

#define PINS_DIGITAL_OUTPUT             0x00
#define PINS_DIGITAL_LOW                0x00
#define PINS_DIGITAL_HIGH               0xFF

/*
    Main application
*/

void delay_ms(unsigned long delay_value);

void I2C_MCP23008_Output_Test();
void I2C_MCP23008_Input_Test();
void I2C_MCP23017_Output_Test();
void I2C_PCA9536_Output_Test();
void I2C_PCA9536_Intput_Test();
void I2C_MCP23008_Output_Test();

int main(void)
{
    SYSTEM_Initialize();
    I2C1_Initialize_Bare_Metal();
    
//    uint32_t millis = timer0_Absolute_Value_Get();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts 
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts 
    // Use the following macros to: 

    // Enable the Global High Interrupts 
    //INTERRUPT_GlobalInterruptHighEnable(); 

    // Disable the Global High Interrupts 
    //INTERRUPT_GlobalInterruptHighDisable(); 

    // Enable the Global Low Interrupts 
    //INTERRUPT_GlobalInterruptLowEnable(); 

    // Disable the Global Low Interrupts 
    //INTERRUPT_GlobalInterruptLowDisable(); 

    // Enable the Peripheral Interrupts 
    //INTERRUPT_PeripheralInterruptEnable(); 

    // Disable the Peripheral Interrupts 
    //INTERRUPT_PeripheralInterruptDisable(); 
    
    // I2C_MCP23017_Output_Test();
    
    SSD1306_Init();
    
    SSD1306_GotoXY (0,0);
	SSD1306_Puts ("MENU", &Font_7x10, SSD1306_COLOR_WHITE);
	SSD1306_GotoXY (0, 20);
	SSD1306_Puts ("(1) CONGRESO", &Font_7x10, SSD1306_COLOR_WHITE);
	SSD1306_GotoXY (0, 40);
	SSD1306_Puts ("(2) HARTONG", &Font_7x10, SSD1306_COLOR_WHITE);
	SSD1306_GotoXY (0, 60);
	SSD1306_Puts ("(1) CONGRESO", &Font_7x10, SSD1306_COLOR_WHITE);
    
    while(1);
    
    
    I2C_MCP23017_Output_Test();

    printf("ADC Value: %d\n", ADC_GetConversion(TEMP_SENSOR));
    
    
    // I2C_MCP23008_Output_Test();
    
    // I2C_PCA9536_Output_Test();
    
    I2C_PCA9536_Intput_Test();

    
    while (1)
    {
        
	}  
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////// AUXILIARY FUNCTIONS /////////////////////////////
///////////////////////////////////////////////////////////////////////////////

// Delay in milliseconds
void delay_ms(unsigned long delay_value){
    for(unsigned long x=0; x < delay_value; x++) __delay_ms(1);
}



////////////////////////////////////////////////////////////////////////////////
///////////////////////// I2C MCP23008 OUTPUT TEST DEVICE //////////////////////
////////////////////////////////////////////////////////////////////////////////

void I2C_MCP23008_Output_Test(){
    printf("I2C_MCP23008_Output_Test...\n\n");
    
    // i2c Link Test
    // i2c1_driver_driver_open();
    
    MCP23008_WriteRegister(MCP23008_IODIR, ALL_OUTPUTS);
    
    do
    {        
        MCP23008_WriteRegister(MCP23008_GPIO, ALL_OUTPUTS_LOW);
        delay_ms(500);
        
        MCP23008_WriteRegister(MCP23008_GPIO, ALL_OUTPUTS_HIGH);
        delay_ms(500);
    
    }while(1);
    
}






////////////////////////////////////////////////////////////////////////////////
//////////////////////// I2C MCP23008 INPUT TEST DEVICE ////////////////////////
////////////////////////////////////////////////////////////////////////////////

void I2C_MCP23008_Input_Test(){
    printf("I2C_MCP23008_Input_Test...\n\n");
    
    TRISB = 0;
    
    // i2c Link Test
    //I2C1_open();
    
    
    I2C1_write1ByteRegister(MCP23008_ADDRESS, MCP23008_GPINTEN, 0);
    delay_ms(100);
    I2C1_write1ByteRegister(MCP23008_ADDRESS, MCP23008_IPOL, 0);
    delay_ms(100);
    I2C1_write1ByteRegister(MCP23008_ADDRESS, MCP23008_IODIR, ALL_INPUTS);
    delay_ms(100);
    I2C1_write1ByteRegister(MCP23008_ADDRESS, MCP23008_GPPU, ALL_PULLUPS);
    delay_ms(100);
    
    // MCP23008_GPIO       
    
    TRISB = 0;
    do{
        
        PORTB = I2C1_read1ByteRegister(MCP23008_ADDRESS, MCP23008_GPIO);
        delay_ms(100);
    
    }while(1);
    
}

////////////////////////////////////////////////////////////////////////////////
///////////////////////// I2C MCP23017 OUTPUT TEST DEVICE //////////////////////
////////////////////////////////////////////////////////////////////////////////

void I2C_MCP23017_Output_Test(){
    printf("I2C_MCP23017_Output_Test...\n\n");
    
    // i2c Link Test
    // I2C1_open();
    
    
    I2C1_write1ByteRegister(MCP23017_ADDRESS , MCP23017_IODIRA  , ALL_OUTPUTS);
    delay_ms(5);
    I2C1_write1ByteRegister(MCP23017_ADDRESS , MCP23017_IODIRB  , ALL_OUTPUTS);
    delay_ms(5);
    I2C1_write1ByteRegister(MCP23017_ADDRESS , MCP23017_GPINTENA  , 0);
    delay_ms(5);
    I2C1_write1ByteRegister(MCP23017_ADDRESS , MCP23017_GPINTENB  , 0);
    delay_ms(5);
    
    do{
        I2C1_write1ByteRegister(MCP23017_ADDRESS , MCP23017_GPIOA, ALL_OUTPUTS_LOW);
        delay_ms(5);
        I2C1_write1ByteRegister(MCP23017_ADDRESS , MCP23017_GPIOB, ALL_OUTPUTS_HIGH);
        delay_ms(500);
        I2C1_write1ByteRegister(MCP23017_ADDRESS , MCP23017_GPIOA, ALL_OUTPUTS_HIGH);
        delay_ms(5);
        I2C1_write1ByteRegister(MCP23017_ADDRESS , MCP23017_GPIOB, ALL_OUTPUTS_LOW);
        delay_ms(500);
    
    }while(1);
    
    
    
}




////////////////////////////////////////////////////////////////////////////////
///////////////////////// I2C PCA9536 OUTPUT TEST DEVICE ///////////////////////
////////////////////////////////////////////////////////////////////////////////

void I2C_PCA9536_Output_Test(){
    printf("I2C_PCA9536_Output_Test...\n\n");
    
    // i2c Link Test
    // I2C1_open();
    
    I2C1_write1ByteRegister(PCA9536_ADDRESS, CONFIGURATION_REG, ALL_OUTPUTS);
    I2C1_write1ByteRegister(PCA9536_ADDRESS, OUTPUT_PORT_REG, ALL_OUTPUTS_LOW);
    delay_ms(500);
    
    
    do{
        I2C1_write1ByteRegister(PCA9536_ADDRESS, OUTPUT_PORT_REG, IO0_HIGH);
        delay_ms(500);
        I2C1_write1ByteRegister(PCA9536_ADDRESS, OUTPUT_PORT_REG, IO1_HIGH);
        delay_ms(500);
        I2C1_write1ByteRegister(PCA9536_ADDRESS, OUTPUT_PORT_REG, IO2_HIGH);
        delay_ms(500);
        I2C1_write1ByteRegister(PCA9536_ADDRESS, OUTPUT_PORT_REG, IO3_HIGH);
        delay_ms(500);
    }while(1);
    
}

////////////////////////////////////////////////////////////////////////////////
///////////////////////// I2C PCA9536 INPUT TEST DEVICE ////////////////////////
////////////////////////////////////////////////////////////////////////////////

void I2C_PCA9536_Intput_Test(){
    
    uint8_t valueReceived = 0;
    
    printf("I2C_PCA9536_Intput_Test...\n\n");
    
    // i2c Link Test
//    I2C1_open();
    
    I2C1_write1ByteRegister(PCA9536_ADDRESS, CONFIGURATION_REG, ALL_OUTPUTS);
    delay_ms(100);
    I2C1_write1ByteRegister(PCA9536_ADDRESS, OUTPUT_PORT_REG, ALL_OUTPUTS_LOW);
    delay_ms(100);
    I2C1_write1ByteRegister(PCA9536_ADDRESS, CONFIGURATION_REG, ALL_INPUTS);
    delay_ms(100);
    
    do{
        
        valueReceived = (uint8_t)(I2C1_read1ByteRegister(PCA9536_ADDRESS, INPUT_PORT_REG) & 0x00FF);
        printf("Value = %u\n", valueReceived);
        delay_ms(100);
    
    }while(1);
    
}







//////////////////////////////////////////////////////////////////////////////////
/////////////////////////// I2C MCP23008 OUTPUT TEST DEVICE //////////////////////
//////////////////////////////////////////////////////////////////////////////////
//
//void I2C_MCP23008_Output_Test(){
//    printf("I2C_MCP23008_Output_Test...\n\n");
//    
//    // i2c Link Test
//    I2C1_open();
//    
//    
//    I2C1_write1ByteRegister(MCP23008_ADDRESS, MCP23008_IODIR, ALL_OUTPUTS);
//    delay_ms(5);
//    I2C1_write1ByteRegister(MCP23008_ADDRESS, MCP23008_GPINTEN, 0);
//    delay_ms(5);
//    
//    do{
//        I2C1_write1ByteRegister(MCP23008_ADDRESS, MCP23008_GPIO, ALL_OUTPUTS_LOW);
//        delay_ms(500);
//        I2C1_write1ByteRegister(MCP23008_ADDRESS, MCP23008_GPIO, ALL_OUTPUTS_HIGH);
//        delay_ms(500);
//    
//    }while(1);
//    
//}