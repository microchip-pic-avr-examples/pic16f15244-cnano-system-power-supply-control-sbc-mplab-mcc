<!-- Please do not change this logo with link -->

[![MCHP](images/microchip.png)](https://www.microchip.com)

# Process Computer Emulation using PIC16F15244 Microcontroller

## Introduction

This code example demonstrates how Raspberry Pi© Single Board Computer (SBC) functionality is emulated using the pic16f15244 curiosity nano evaluation kit. For overview of the application implementation, refer “Supply Control Module using PIC16F15244 Microcontroller“ code example.

For complete details of the application implementation, refer application note : [Using PIC16F15244 Microcontrollers for System Power Supply Control]( https://www.microchip.com/DS00004121).


## Related Documentation

- [Application note : Using PIC16F15244 Microcontrollers for System Power Supply Control]( https://www.microchip.com/DS00004121)
- [GitHub Microchip PIC Examples : System Power Supply Control Module Emulation using PIC16F15244 Microcontroller](https://github.com/microchip-pic-avr-examples/pic16f15244-cnano-system-power-supply-control-module-mplab-mcc)
- [GitHub Microchip PIC Examples : System Power Supply Control Module using PIC16F15245 Microcontroller](https://github.com/microchip-pic-avr-examples/pic16f15245-system-power-supply-control-module-mplab-mcc)
- [PIC16F152xx Product Family Page](https://www.microchip.com/en-us/products/microcontrollers-and-microprocessors/8-bit-mcus/pic-mcus/pic16f15244)
- [PIC16F152xx Family Code Examples on GitHub](https://github.com/orgs/microchip-pic-avr-examples/repositories?q=pic16f152&type=all&language=&sort=)
- [PIC16F15244 MCU Family Video](https://www.youtube.com/watch?v=nHLv3Th-o-s)
- [PIC16F15244 MCU Product Page](https://www.microchip.com/en-us/product/PIC16F15244)


## Software Used

- MPLAB® X IDE [6.0.0 or newer](http://www.microchip.com/mplab/mplab-x-ide)
- MPLAB® XC8 [2.36.0 or newer](http://www.microchip.com/mplab/compilers)
- MPLAB® Code Configurator (MCC) [5.1.1 or newer](https://www.microchip.com/mplab/mplab-code-configurator)
- Microchip PIC16F1xxxx_DFP Device Support [1.9.163 or newer](https://packs.download.microchip.com)
- MCC Melody Core 2.1.9
- I2C_Client MCC Melody driver 2.0.1
- UART MCC Melody driver 1.6.0


## Hardware Used

- PIC16F15244 Curiosity Nano Evaluation Kit [EV09Z19A](https://www.microchip.com/en-us/development-tool/EV09Z19A)

## Process Computer Module Implementation 

To implement the emulated Raspberry Pi-based SBC functionality , PIC16F15244 Curiosity Nano Evaluation Kit is used which will be referred as “process computer”.

The process computer-side firmware for the system power supply control demo is developed to emulate the power-down feature of the process computer. The process computer will send out a power-down command to the supply control module when a switch press event is detected. 

This power-down command triggers the shutdown of the regulator by the supply control module’s microcontroller. The command also contains the time duration the system will be turned OFF. The command consists of an ASCII string for cross platform support: S (number of seconds), where the first byte is the character ‘S’ and the following six characters are the shutdown duration in seconds (for example, ‘S007200’ represents 7200 seconds, or two hours, of system power-down).

In case the process computer needs to be turned ON before the power-down period is over, the supply control module can also accept user input. To demonstrate this feature, an on-board switch is used on the Curiosity Nano board serving as the supply controller is used. The supply controller module will immediately turn ON the regulator in the event of a switch press.

## Demo Operation

To know about the demo operation, refer GitHub code example [Using PIC16F15244 Microcontrollers for System Power Supply Control]( https://www.microchip.com/DS00004121).

 