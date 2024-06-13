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
bool MCP23008_WriteRegister(uint8_t reg, uint8_t value);



bool I2C_PCA9536_WriteRegister(uint8_t reg, uint8_t value);
void I2C_PCA9536_Output_Test();


// const i2c_host_interface_t *I2C = &i2c1_host_interface;


#define I2C_CLIENT_ADDR 0x20
#define MCP23008_REG_ADDR_IODIR 0x00
#define MCP23008_REG_ADDR_GPIO 0x09
#define PINS_DIGITAL_OUTPUT 0x00
#define PINS_DIGITAL_HIGH 0xFF
#define DATALENGTH 2










int main(void)
{
    SYSTEM_Initialize();
    
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
    
    I2C1_Initialize_Bare_Metal();

    printf("ADC Value: %d\n", ADC_GetConversion(TEMP_SENSOR));
    
    
    // I2C_MCP23008_Output_Test();

    /* Set the extended pins as digital output */
    I2C1_write1ByteRegister(I2C_SLAVE_ADDR, MCP23008_REG_ADDR_IODIR, PINS_DIGITAL_OUTPUT);
    
    while (1)
    {
        /* Set the extended pins to digital low */
        I2C1_write1ByteRegister(I2C_SLAVE_ADDR, MCP23008_REG_ADDR_GPIO, PINS_DIGITAL_LOW);
        __delay_ms(500);
        /* Set the extended pins to digital high */
        I2C1_write1ByteRegister(I2C_SLAVE_ADDR, MCP23008_REG_ADDR_GPIO, PINS_DIGITAL_HIGH);
        __delay_ms(500);
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





bool MCP23008_WriteRegister(uint8_t reg, uint8_t value) {
    uint8_t data[2];
    data[0] = reg;    // MCP23008 register address
    data[1] = value;  // Value to be written to the register

    // Write to MCP23008 via I2C
    if (!I2C1_Write(MCP23008_ADDRESS, data, 2)) {
        // Error handling if write fails
        printf("I2C error\n");
        return false;
    }
    return true;
}



bool I2C_PCA9536_WriteRegister(uint8_t reg, uint8_t value) {
    uint8_t data[2];
    data[0] = reg;    // MCP23008 register address
    data[1] = value;  // Value to be written to the register

    // Write to MCP23008 via I2C
    if (!I2C1_Write(PCA9536_ADDRESS, data, 2)) {
        // Error handling if write fails
        printf("I2C error\n");
        return false;
    }
    return true;
}

void I2C_PCA9536_Output_Test(){
    printf("I2C_PCA9536_Output_Test...\n\n");
    
    // i2c Link Test
    // i2c1_driver_driver_open();
    
    I2C_PCA9536_WriteRegister(CONFIGURATION_REG, ALL_OUTPUTS);
    I2C_PCA9536_WriteRegister(OUTPUT_PORT_REG, ALL_OUTPUTS_LOW);
    delay_ms(500);
    
    
    do{
        I2C_PCA9536_WriteRegister(OUTPUT_PORT_REG, IO0_HIGH);
        delay_ms(500);
        I2C_PCA9536_WriteRegister(OUTPUT_PORT_REG, IO1_HIGH);
        delay_ms(500);
        I2C_PCA9536_WriteRegister(OUTPUT_PORT_REG, IO2_HIGH);
        delay_ms(500);
        I2C_PCA9536_WriteRegister(OUTPUT_PORT_REG, IO3_HIGH);
        delay_ms(500);
    }while(1);
    
}