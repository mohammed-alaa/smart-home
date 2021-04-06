/*****************************************************************************/
/* File name: MDIO_interface.h                                               */
/* Author: Mohamed Alaa                                                      */
/* Description: This file contains the interfacing information of DIO Module */
/* Date: 30-01-2021                                                          */
/*****************************************************************************/

/* Header file guard */
#ifndef MDIO_INTERFACE_H_
#define MDIO_INTERFACE_H_

/************************************************************************/
/*                          Interfacing macros                          */
/************************************************************************/

/* GPIO Ports */
#define PORTA (0)
#define PORTB (1)
#define PORTC (2)
#define PORTD (3)

/* GPIO Pins */
#define PIN0 (0b00000001)
#define PIN1 (0b00000010)
#define PIN2 (0b00000100)
#define PIN3 (0b00001000)
#define PIN4 (0b00010000)
#define PIN5 (0b00100000)
#define PIN6 (0b01000000)
#define PIN7 (0b10000000)

/* GPIO Pins' status */
#define INPUT_FLOAT		(0)
#define INPUT_PULLUP	(1)
#define OUTPUT			(2)

/* GPIO Pin value */
#define LOW		(0)
#define HIGH	(1)

/************************************************************************/
/*                        Functions' prototypes                        */
/************************************************************************/

/* This function is responsible for setting a certain status to a certain port pin */
void mdio_setPinStatus(u8_t au8_port, u8_t au8_pin, u8_t au8_pinStatus);

/* This function is responsible for setting a certain value to a certain port pin */
void mdio_setPinValue(u8_t au8_port, u8_t au8_pin, u8_t au8_pinValue);

/* This function is responsible for toggling the current value of a certain port pin */
void mdio_togglePinValue(u8_t au8_port, u8_t au8_pin);

/* This function is responsible for getting the current value of a certain port pin */
u8_t mdio_getPinValue(u8_t au8_port, u8_t au8_pin);

#endif /* MDIO_INTERFACE_H_ */