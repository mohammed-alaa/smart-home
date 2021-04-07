/**
 * @file    HLED_program.c
 * @author  Mohamed Alaa
 * @brief   This file contains the logical operations of LED Module
 * @date    2021/04/06
 *
 * @copyright Copyright (c) 2021
 *
 */

/************************************************************************/
/*                             Includes                                 */
/************************************************************************/

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_interface.h"
#include "HLED_private.h"
#include "HLED_interface.h"

/************************************************************************/
/*                         Functions' definitions                       */
/************************************************************************/

void hled_init(u8_t au8_led)
{
	switch (au8_led)
	{
		/* In case of LED1 */
		case HLED_LED1:
			/* Set PD0 to OUTPUT */
			mdio_setPinStatus(PORTD, PIN0, OUTPUT);
		
			/* Break from this case */
			break;
		/* In case of LED2 */
		case HLED_LED2:
			/* Set PD1 to OUTPUT */
			mdio_setPinStatus(PORTD, PIN1, OUTPUT);
		
			/* Break from this case */
			break;
		/* Default case */
		default:
			/* Break from this case */
			break;
	}
	
	/* Return from this function */
	return;
}

void hled_turnOnLED(u8_t au8_led)
{
	switch (au8_led)
	{
		/* In case of LED1 */
		case HLED_LED1:
			/* Set PD0 to HIGH */
			mdio_setPinValue(PORTD, PIN0, HIGH);
		
			/* Break from this case */
			break;
		/* In case of LED2 */
		case HLED_LED2:
			/* Set PD1 to HIGH */
			mdio_setPinValue(PORTD, PIN1, HIGH);
		
			/* Break from this case */
			break;
		/* Default case */
		default:
			/* Break from this case */
			break;
	}
	
	/* Return from this function */
	return;
}

void hled_turnOffLED(u8_t au8_led)
{
	switch (au8_led)
	{
		/* In case of LED1 */
		case HLED_LED1:
			/* Set PD0 to LOW */
			mdio_setPinValue(PORTD, PIN0, LOW);
		
			/* Break from this case */
			break;
		/* In case of LED2 */
		case HLED_LED2:
			/* Set PD1 to LOW */
			mdio_setPinValue(PORTD, PIN1, LOW);
		
			/* Break from this case */
			break;
		/* Default case */
		default:
			/* Break from this case */
			break;
	}
	
	/* Return from this function */
	return;
}

void hled_toggleLED(u8_t au8_led)
{
	switch (au8_led)
	{
		/* In case of LED1 */
		case HLED_LED1:
			/* Toggle PD2 */
			mdio_togglePinValue(PORTD, PIN0);
		
			/* Break from this case */
			break;
		/* In case of LED2 */
		case HLED_LED2:
			/* Toggle PD2 */
			mdio_togglePinValue(PORTD, PIN1);
		
			/* Break from this case */
			break;
		/* Default case */
		default:
			/* Break from this case */
			break;
	}
	
	/* Return from this function */
	return;
}