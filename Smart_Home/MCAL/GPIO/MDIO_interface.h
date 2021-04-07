/**
 * @file    MDIO_interface.h
 * @author  Mohamed Alaa
 * @brief   This file contains the interfacing information of DIO Module
 * @date    2021/04/06
 *
 * @copyright Copyright (c) 2021
 *
 */

/* Header file guard */
#ifndef MDIO_INTERFACE_H_
#define MDIO_INTERFACE_H_

/************************************************************************/
/*                          Interfacing macros                          */
/************************************************************************/

/* GPIO Ports */
/*!
  \def	PORTA
  GPIO Port A definition
*/
#define PORTA (0)

/*!
  \def	PORTB
  GPIO Port B definition
*/
#define PORTB (1)

/*! GPIO Port C definition */
#define PORTC (2)

/*! GPIO Port D definition */
#define PORTD (3)

/* GPIO Pins */
/*! GPIO PIN0 definition */
#define PIN0 (0b00000001)

/*! GPIO PIN1 definition */
#define PIN1 (0b00000010)

/*! GPIO PIN2 definition */
#define PIN2 (0b00000100)

/*! GPIO PIN3 definition */
#define PIN3 (0b00001000)

/*! GPIO PIN4 definition */
#define PIN4 (0b00010000)

/*! GPIO PIN5 definition */
#define PIN5 (0b00100000)

/*! GPIO PIN6 definition */
#define PIN6 (0b01000000)

/*! GPIO PIN7 definition */
#define PIN7 (0b10000000)

/* GPIO Pins' status */
/*! GPIO pins' status input float definition */
#define INPUT_FLOAT		(0)

/*! GPIO pins' status input pull-up definition */
#define INPUT_PULLUP	(1)

/*! GPIO pins' status output definition */
#define OUTPUT			(2)

/* GPIO Pin value */
/*! GPIO pins' value high definition */
#define LOW		(0)

/*! GPIO pins' value low definition */
#define HIGH	(1)

/************************************************************************/
/*                        Functions' prototypes                        */
/************************************************************************/

/**
 * @brief   This function is responsible for setting a certain status to a certain PORT PIN
 * @param   au8_port	Variable to determine which PORT we are changing its status
 * @param   au8_pin		Variable to determine which PIN we are changing its status
 * @param   au8_pinStatus	Variable to determine what status we want to change the specified PORT & PIN status
 *
 * @return   void
 */
void mdio_setPinStatus(u8_t au8_port, u8_t au8_pin, u8_t au8_pinStatus);

/**
 * @brief   This function is responsible for setting a certain value to a certain PORT PIN
 * @param   au8_port	Variable to determine which PORT we are changing its status
 * @param   au8_pin		Variable to determine which PIN we are changing its status
 * @param	au8_pinValue	Variable to determine what value we are going to apply on the specified PORT & PIN
 *
 * @return   void
 */
void mdio_setPinValue(u8_t au8_port, u8_t au8_pin, u8_t au8_pinValue);

/**
 * @brief   This function is responsible for toggling the current value of a certain PORT PIN
 * @param   au8_port	Variable to determine which PORT we are toggling its status
 * @param   au8_pin		Variable to determine which PIN we are toggling its status
 *
 * @return   void
 */
void mdio_togglePinValue(u8_t au8_port, u8_t au8_pin);

/**
 * @brief   This function is responsible for getting the current value of a certain PORT PIN
 * @param   au8_port	Variable to determine which PORT we are getting its current value
 * @param   au8_pin		Variable to determine which PIN we are changing its current value
 *
 * @return	The current value of a certain PORT & PIN
 */
u8_t mdio_getPinValue(u8_t au8_port, u8_t au8_pin);

#endif /* MDIO_INTERFACE_H_ */