<!-- Please do not change this logo with link -->

[![MCHP](images/microchip.png)](https://www.microchip.com)

# Process Computer Emulation using PIC16F15244 Microcontroller

## Introduction

This code example demonstrates how Raspberry Pi© Single Board Computer (SBC) functionality is emulated using the pic16f15244 curiosity nano evaluation kit. For overview of the application implementation, refer “Supply Control Module using PIC16F15244 Microcontroller“ code example.

For complete details of the application implementation, refer application note : Using PIC16F15244 Microcontrollers for System Power Supply Control.


## Related Documentation

- [Application note : Using PIC16F15244 Microcontrollers for System Power Supply Control]
- [GitHub Microchip PIC Examples : Supply Control Module using PIC16F15244 Microcontroller]
- [GitHub Microchip PIC Examples : Supply Control Module using PIC16F15245 Microcontroller]
- [PIC16F15244 Product Family Page](https://www.microchip.com/en-us/products/microcontrollers-and-microprocessors/8-bit-mcus/pic-mcus/pic16f15244)
- [PIC16F15244 Code Examples on GitHub](https://github.com/microchip-pic-avr-examples?q=pic16f15244&type=&language=&sort=)
- [PIC16F15244 MCU Family Video](https://www.youtube.com/watch?v=nHLv3Th-o-s)
- [PIC16F15244 MCU Product Page](https://www.microchip.com/en-us/product/PIC16F15244)


## Software Used

- [MPLAB® X IDE 5.50 or newer](http://www.microchip.com/mplab/mplab-x-ide)
- [MPLAB® XC8 2.32 or a newer compiler](http://www.microchip.com/mplab/compilers)
- [MPLAB® Code Configurator (MCC) v5.0.3 or newer](https://www.microchip.com/mplab/mplab-code-configurator)
- [Master Synchronous Serial Port(MSSP) MCC Melody driver v6.1.0]
- [Timer0 (TMR0) MCC Melody driver v4.0.8]


## Hardware Used

- PIC16F15244 Curiosity Nano Evaluation Kit [EV09Z19A](https://www.microchip.com/en-us/development-tool/EV09Z19A)

## Process Computer Module Implementation 

To implement the emulated Raspberry Pi-based SBC functionality , PIC16F15244 Curiosity Nano Evaluation Kit is used which will be referred as “process computer”.

The process computer-side firmware for the system power supply control demo is developed to emulate the power-down feature of the process computer. The process computer will send out a power-down command to the supply control module when a switch press event is detected. 

This power-down command triggers the shutdown of the regulator by the supply control module’s microcontroller. The command also contains the time duration the system will be turned OFF. The command consists of an ASCII string for cross platform support: S (number of seconds), where the first byte is the character ‘S’ and the following six characters are the shutdown duration in seconds (for example, ‘S007200’ represents 7200 seconds, or two hours, of system power-down).

In case the process computer needs to be turned ON before the power-down period is over, the supply control module can also accept user input. To demonstrate this feature, an on-board switch is used on the Curiosity Nano board serving as the supply controller is used. The supply controller module will immediately turn ON the regulator in the event of a switch press.

## Demo Operation

To know about the demo operation, refer GitHub code example “Supply Control Module using PIC16F15244 Microcontroller”.

 