/**
 * @file    MUART_private.h
 * @author  Mohamed Alaa
 * @brief   This file contains the private information of UART Module
 * @date    2021/04/06
 *
 * @copyright Copyright (c) 2021
 *
 */

/* Header file guard */
#ifndef MUART_PRIVATE_H_
#define MUART_PRIVATE_H_

/*************************************************************************/
/*                          UART registers                               */
/*************************************************************************/

/*!
  \def	MUART_UDR
  Pointer to UDR's address in the memory
*/
#define MUART_UDR		(*(volatile u8_t*) (0x2C))

/*!
  \def	MUART_UBRRH
  Pointer to UBRRH's address in the memory
*/
#define MUART_UBRRH		(*(volatile u8_t*) (0x40))

/*!
  \def	MUART_UBRRL
  Pointer to UBRRL's address in the memory
*/
#define MUART_UBRRL		(*(volatile u8_t*) (0x29))

/*!
  \def	MUART_UCSRA
  Pointer to UCSRA's address in the memory
*/
#define MUART_UCSRA		(*(volatile u8_t*) (0x2B))

/*!
  \def	MUART_UCSRB
  Pointer to UCSRB's address in the memory
*/
#define MUART_UCSRB		(*(volatile u8_t*) (0x2A))

/*!
  \def	MUART_UCSRC
  Pointer to UCSRC's address in the memory
*/
#define MUART_UCSRC		(*(volatile u8_t*) (0x40))

#endif /* MUART_PRIVATE_H_ */