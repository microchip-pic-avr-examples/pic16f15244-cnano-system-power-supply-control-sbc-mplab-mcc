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
© [2021] Microchip Technology Inc. and its subsidiaries.

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
#include "mcc_generated_files/i2c_host/mssp1.h"

#define I2C_ADD 0x0A                          //I2C Client address
#define LED_ON()        LED_SetLow();         //LED ON
#define LED_OFF()       LED_SetHigh();        //LED OFF

uint8_t dataBuf[10] = "S00032";               //I2C Command sent to the client
volatile uint8_t buttonPressed = 0;           //Flag to indicate button press event

void PinChangeInterruptHandler(void);

/*
    Main application
*/

int main(void)
{
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts 
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts 
    // Use the following macros to: 

    // Enable the Global Interrupts 
    INTERRUPT_GlobalInterruptEnable(); 

    // Disable the Global Interrupts 
    //INTERRUPT_GlobalInterruptDisable(); 

    // Enable the Peripheral Interrupts 
    INTERRUPT_PeripheralInterruptEnable(); 

    // Disable the Peripheral Interrupts 
    //INTERRUPT_PeripheralInterruptDisable(); 

    // Pin Change Interrupt Handler function
    INT_SetInterruptHandler(PinChangeInterruptHandler);
    
    while(1)
    {
        if(buttonPressed == 1)                  //Check if button is pressed
        {
            buttonPressed = 0;                  //Clear the flag
            LED_ON();                           //LED ON
          //  __delay_ms(100);                    //Delay is added to observe LED ON
            I2C1_Write(I2C_ADD, dataBuf, 7);    //Send I2C Command
            printf("Sending I2C data\n");       
            LED_OFF();                          //LED OFF   
        }     
    }    
}

/*******************************************************************************
 * void PinChangeInterruptHandler(void)
 * 
 * buttonPressed flag is set, when switch press event is detected
 * @param none
 * @return none
 ******************************************************************************/
void PinChangeInterruptHandler(void)
{
    buttonPressed = 1;
}