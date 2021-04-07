/**
 * @file    MDIO_private.h
 * @author  Mohamed Alaa
 * @brief   This file contains the private information of DIO Module
 * @date    2021/04/06
 *
 * @copyright Copyright (c) 2021
 *
 */

/* Header file guard */
#ifndef MDIO_PRIVATE_H_
#define MDIO_PRIVATE_H_

/************************************************************************/
/*                          DIO registers                               */
/************************************************************************/

/* PORTA Registers */
/*!
  \def	MDIO_PORTA
  Pointer to PORTA's address in the memory
*/
#define MDIO_PORTA	(*(volatile u8_t *) (0x3B))

/*!
  \def	MDIO_DDRA
  Pointer to DDRA's address in the memory
*/
#define MDIO_DDRA	(*(volatile u8_t *) (0x3A))

/*!
  \def	MDIO_PINA
  Pointer to PINA's address in the memory
*/
#define MDIO_PINA	(*(volatile u8_t *) (0x39))

/* PORTB Registers */
/*!
  \def	MDIO_PORTB
  Pointer to PORTB's address in the memory
*/
#define MDIO_PORTB	(*(volatile u8_t *) (0x38))

/*!
  \def	MDIO_DDRB
  Pointer to DDRB's address in the memory
*/
#define MDIO_DDRB	(*(volatile u8_t *) (0x37))

/*!
  \def	MDIO_PINB
  Pointer to PINB's address in the memory
*/
#define MDIO_PINB	(*(volatile u8_t *) (0x36))

/* PORTC Registers */
/*!
  \def	MDIO_PORTC
  Pointer to PORTC's address in the memory
*/
#define MDIO_PORTC	(*(volatile u8_t *) (0x35))

/*!
  \def	MDIO_DDRC
  Pointer to DDRC's address in the memory
*/
#define MDIO_DDRC	(*(volatile u8_t *) (0x34))

/*!
  \def	MDIO_PINC
  Pointer to PINC's address in the memory
*/
#define MDIO_PINC	(*(volatile u8_t *) (0x33))

/* PORTD Registers */
/*!
  \def	MDIO_PORTD
  Pointer to PORTD's address in the memory
*/
#define MDIO_PORTD	(*(volatile u8_t *) (0x32))

/*!
  \def	MDIO_DDRD
  Pointer to DDRD's address in the memory
*/
#define MDIO_DDRD	(*(volatile u8_t *) (0x31))

/*!
  \def	MDIO_PIND
  Pointer to PIND's address in the memory
*/
#define MDIO_PIND	(*(volatile u8_t *) (0x30))

#endif /* MDIO_PRIVATE_H_ */