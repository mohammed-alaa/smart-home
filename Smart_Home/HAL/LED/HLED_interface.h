/**
 * @file    HLED_interface.h
 * @author  Mohamed Alaa
 * @brief   This file contains the interface information of LED Module
 * @date    2021/04/06
 *
 * @copyright Copyright (c) 2021
 *
 */

/* Header file guard */
#ifndef HLED_INTERFACE_H_
#define HLED_INTERFACE_H_

/************************************************************************/
/*                          Interfacing macros                          */
/************************************************************************/

/*
  \defgroup   LED Macros
*/

/*!
  \def	HLED_LED1
  Indicates the values of the LED 1
*/
#define HLED_LED1	(1)
/*!
  \def	HLED_LED2
  Indicates the values of the LED 2
*/
#define HLED_LED2	(2)

/************************************************************************/
/*                        Functions' prototypes                         */
/************************************************************************/

/**
 * @brief   This function is responsible for initializing a specific LED
 * @param   au8_led Variable to determine which LED to initialize
 *
 * @return  void
 */
void hled_init(u8_t au8_led);

/**
 * @brief   This function is responsible for turning ON a specific LED
 * @param   au8_led Variable to determine which LED to turn on
 *
 * @return   void
 */
void hled_turnOnLED(u8_t au8_led);

/**
 * @brief   This function is responsible for turning OFF a specific LED
 * @param   au8_led Variable to determine which LED to turn off
 *
 * @return   void
 */
void hled_turnOffLED(u8_t au8_led);

/**
 * @brief   This function is responsible for toggling a specific LED
 * @param   au8_led Variable to determine which LED to toggle
 *
 * @return   void
 */
void hled_toggleLED(u8_t au8_led);

#endif /* HLED_INTERFACE_H_ */