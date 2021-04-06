/*******************************************************************************/
/* File name: HLED_interface.h                                                 */
/* Author: Mohamed Alaa                                                        */
/* Description: This file contains the interface information of LED Module     */
/* Date: 4/5/2021                                                              */
/******************************************************************************/

/* Header file guard */
#ifndef HLED_INTERFACE_H_
#define HLED_INTERFACE_H_

/************************************************************************/
/*                          Interfacing macros                          */
/************************************************************************/

/* LED Macros */
#define HLED_LED1	(1)
#define HLED_LED2	(2)

/************************************************************************/
/*                        Functions' prototypes                         */
/************************************************************************/

/* This function is responsible for initializing a specific LED */
void hled_init(u8_t au8_led);

/* This function is responsible for turning ON a specific LED */
void hled_turnOnLED(u8_t au8_led);

/* This function is responsible for turning OFF a specific LED */
void hled_turnOffLED(u8_t au8_led);

/* This function is responsible for toggling a specific LED */
void hled_toggleLED(u8_t au8_led);

#endif /* HLED_INTERFACE_H_ */