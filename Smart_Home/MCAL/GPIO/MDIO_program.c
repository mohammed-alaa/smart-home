/**
 * @file    MDIO_program.c
 * @author  Mohamed Alaa
 * @brief   This file contains the logical operations of DIO Module
 * @date    2021/04/06
 *
 * @copyright Copyright (c) 2021
 *
 */

/************************************************************************/
/*                             Includes                                 */
/************************************************************************/
#include "LSTD_TYPES.h"
#include "MDIO_private.h"
#include "MDIO_interface.h"

/************************************************************************/
/*                         Functions' definitions                       */
/************************************************************************/

void mdio_setPinStatus(u8_t au8_port, u8_t au8_pin, u8_t au8_pinStatus)
{
	/* Switching over the DIO ports */
	switch(au8_port)
	{
		/* In case of PORTA */
		case PORTA:
			/* Switching over pin status */
			switch(au8_pinStatus)
			{
				/* In case of input float */
				case INPUT_FLOAT:
					/* Clearing the corresponding pin in DDRA register */
					MDIO_DDRA &= ~au8_pin;
					break;
				/* In case of input pull up */
				case INPUT_PULLUP:
					/* Clearing the corresponding pin in DDRA register */
					MDIO_DDRA &= ~au8_pin;
					/*  Setting the corresponding bits in PORTA register */
					MDIO_PORTA |= au8_pin;
					break;
				/* In case of output */
				case OUTPUT:
					/*  Setting the corresponding bits in PORTA register */
					MDIO_DDRA |= au8_pin;
					break;
				/* In case of default */
				default:
					break;
			}
			break;
		/* In case of PORTB */
		case PORTB:
			/* Switching over pin status */
			switch(au8_pinStatus)
			{
				/* In case of input float */
				case INPUT_FLOAT:
					/* Clearing the corresponding pin in DDRB register */
					MDIO_DDRB &= ~au8_pin;
					break;
				/* In case of input pull up */
				case INPUT_PULLUP:
					/* Clearing the corresponding pin in DDRB register */
					MDIO_DDRB &= ~au8_pin;
					/*  Setting the corresponding bits in PORTB register */
					MDIO_PORTB |= au8_pin;
					break;
				/* In case of output */
				case OUTPUT:
					/*  Setting the corresponding bits in PORTB register */
					MDIO_DDRB |= au8_pin;
					break;
				/* In case of default */
				default:
					break;
			}
			break;
		/* In case of PORTC */
		case PORTC:
			/* Switching over pin status */
			switch(au8_pinStatus)
			{
				/* In case of input float */
				case INPUT_FLOAT:
					/* Clearing the corresponding pin in DDRA register */
					MDIO_DDRC &= ~au8_pin;
					break;
				/* In case of input pull up */
				case INPUT_PULLUP:
					/* Clearing the corresponding pin in DDRA register */
					MDIO_DDRC &= ~au8_pin;
					/*  Setting the corresponding bits in PORTC register */
					MDIO_PORTC |= au8_pin;
					break;
				/* In case of output */
				case OUTPUT:
					/*  Setting the corresponding bits in PORTC register */
					MDIO_DDRC |= au8_pin;
					break;
				/* In case of default */
				default:
					break;
			}
			break;
		/* In case of PORTD */
		case PORTD:
			/* Switching over pin status */
			switch(au8_pinStatus)
			{
				/* In case of input float */
				case INPUT_FLOAT:
					/* Clearing the corresponding pin in DDRD register */
					MDIO_DDRD &= ~au8_pin;
					break;
				/* In case of input pull up */
				case INPUT_PULLUP:
					/* Clearing the corresponding pin in DDRD register */
					MDIO_DDRD &= ~au8_pin;
					/*  Setting the corresponding bits in PORTD register */
					MDIO_PORTD |= au8_pin;
					break;
				/* In case of output */
				case OUTPUT:
					/*  Setting the corresponding bits in PORTD register */
					MDIO_DDRD |= au8_pin;
					break;
				/* In case of default */
				default:
					break;
			}
			break;
		/* In case of default */
		default:
			break;
	}

	/* Return from the file */
	return;
}

void mdio_setPinValue(u8_t au8_port, u8_t au8_pin, u8_t au8_pinValue)
{
	/* Switching over the DIO ports */
	switch(au8_port)
	{
		/* In case of PORTA */
		case PORTA:
			/* Switching over pin status */
			switch(au8_pinValue)
			{
				/* In case of LOW */
				case LOW:
					/* Clearing the corresponding bits in PORT register */
					MDIO_PORTA &= ~au8_pin;
					break;
				/* In case of input HIGH */
				case HIGH:
					/*  Setting the corresponding bits in PORT register */
					MDIO_PORTA |= au8_pin;
					break;
				/* In case of default case */
				default:
					break;
			}
			break;
		/* In case of PORTB */
		case PORTB:
			/* Switching over pin status */
			switch(au8_pinValue)
			{
				/* In case of LOW */
				case LOW:
					/* Clearing the corresponding bits in PORT register */
					MDIO_PORTB &= ~au8_pin;
					break;
				/* In case of input HIGH */
				case HIGH:
					/*  Setting the corresponding bits in PORT register */
					MDIO_PORTB |= au8_pin;
					break;
				/* In case of default case */
				default:
					break;
			}
			break;
		/* In case of PORTC */
		case PORTC:
			/* Switching over pin status */
			switch(au8_pinValue)
			{
				/* In case of LOW */
				case LOW:
					/* Clearing the corresponding bits in PORT register */
					MDIO_PORTC &= ~au8_pin;
					break;
				/* In case of input HIGH */
				case HIGH:
					/*  Setting the corresponding bits in PORT register */
					MDIO_PORTC |= au8_pin;
					break;
				/* In case of default case */
				default:
					break;
			}
			break;
		/* In case of PORTD */
		case PORTD:
			/* Switching over pin status */
			switch(au8_pinValue)
			{
				/* In case of LOW */
				case LOW:
					/* Clearing the corresponding bits in PORT register */
					MDIO_PORTD &= ~au8_pin;
					break;
				/* In case of input HIGH */
				case HIGH:
					/*  Setting the corresponding bits in PORT register */
					MDIO_PORTD |= au8_pin;
					break;
				/* In case of default case */
				default:
					break;
			}
			break;
		/* In case of default case */
		default:
			break;
	}

	/* Return from this function */
	return;
}

void mdio_togglePinValue(u8_t au8_port, u8_t au8_pin)
{
	/* Switching over the DIO ports */
	switch(au8_port)
	{
		/* In case of PORTA */
		case PORTA:
			MDIO_PORTA ^= au8_pin;
			break;
		/* In case of PORTB */
		case PORTB:
			MDIO_PORTB ^= au8_pin;
			break;
		/* In case of PORTC */
		case PORTC:
			MDIO_PORTC ^= au8_pin;
			break;
		/* In case of PORTC */
		case PORTD:
			MDIO_PORTD ^= au8_pin;
			break;
		/* In case of default case */
		default:
			break;
	}
	
	/* Return from this function */
	return;
}

u8_t mdio_getPinValue(u8_t au8_port, u8_t au8_pin)
{
	/* This variable is used to get the corresponding pin value */
	u8_t au8_pinValue = 0;

	/* Switching over the DIO ports */
	switch(au8_port)
	{
		/* In case of PORTA */
		case PORTA:
			if (MDIO_PINA & au8_pin)
			{
				/* The pin value is HIGH */
				au8_pinValue = HIGH;
			}
			else
			{
				/* The pin value is LOW */
				au8_pinValue = LOW;
			}
			break;
		/* In case of PORTB */
		case PORTB:
			if (MDIO_PINB & au8_pin)
			{
				/* The pin value is HIGH */
				au8_pinValue = HIGH;
			}
			else
			{
				/* The pin value is LOW */
				au8_pinValue = LOW;
			}
			break;
		/* In case of PORTC */
		case PORTC:
			if (MDIO_PINC & au8_pin)
			{
				/* The pin value is HIGH */
				au8_pinValue = HIGH;
			}
			else
			{
				/* The pin value is LOW */
				au8_pinValue = LOW;
			}
			break;
		/* In case of PORTD */
		case PORTD:
			if (MDIO_PIND & au8_pin)
			{
				/* The pin value is HIGH */
				au8_pinValue = HIGH;
			}
			else
			{
				/* The pin value is LOW */
				au8_pinValue = LOW;
			}
			break;
		/* In case of default */
		default:
			break;
	}

	/* Return the pin value */
	return au8_pinValue;
}