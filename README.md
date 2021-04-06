# Smart Home Application

Smart home application is a project based on ATMEGA32 and Bluetooth where we want to control home appliance wirelessly using Mobile App via Bluetooth.

## Project Description

- This project is Smart Home based on Bluetooth where we want to control home appliance wirelessly using Mobile App via Bluetooth.
- Two ECU’s Communicate with each other the first is a control ECU which takes the input from Bluetooth and sends it to the Sink (Actuator) ECU via SPI to interpret which action should be taken.

This project is developed using:

- Micro controller ATMEGA32
- Bluetooth HC-05
- Basic LEDs

## Files Structure
- Release:	Contains the compiled version for the SLAVE micro controller.
- Debug:	Contains the compiled version for the MASTER micro controller.
- APP:		Contains the logical application operations.
- HAL:
	- BTH:	Contains the Bluetooth module.
	- LED:	Contains the LED module.
- MCAL:
	- GPIO:	Contains the General purpose input/ouput module.
	- SPI:	Contains the Serial Peripheral Interface module.
	- UART:	Contains the Universal Asynchronous Receiver-Transmitter module.
- LIBS:		Contains the libraries
- main.c:	Contains the logical operations to run the whole application.

### Note

```c
/* Uncomment below line/macro if the compiled version is going to be for the MASTER microcontroller */
//#define MASTER_VERSION
```

## Static Software Architecture

![Schematic](SSA.png)

## Schematic

![Schematic](Schematic.png)