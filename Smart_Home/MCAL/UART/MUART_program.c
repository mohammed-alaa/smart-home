/**
 * @file    MUART_program.c
 * @author  Mohamed Alaa
 * @brief   This file contains the logical operations of UART Module
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
#include "MUART_private.h"
#include "MUART_interface.h"
/*!
  \def	F_CPU
  CPU's Oscillator
*/
#define F_CPU 16000000UL
#include "util/delay.h"

/************************************************************************/
/*                         Important macros                             */
/************************************************************************/

/*!
  \def	TIMEOUT_DELAY
  Timeout Delay macro
*/
#define TIMEOUT_DELAY	10

/************************************************************************/
/*                         Functions' definitions                       */
/************************************************************************/
void muart_init(u8_t au8_baudRate)
{
	/* Enable TX and RX pins */
	MUART_UCSRB = 0x18;
	
	/* Enable asynchronous mode, no parity bit, 1 stop bit and1 byte of data operation */
	MUART_UCSRC = 0x86;
	
	/* Setting the low baud rate register */
	MUART_UBRRL = (u8_t) au8_baudRate;
	
	/* Setting the high baud rate register */
	MUART_UBRRH = (u8_t) (au8_baudRate >> 8);
	
	/* Return from this function */
	return;
}

void muart_sendByte(u8_t au8_dataByte)
{
	/* Local variable in timing out operations */
	u8_t au8_timeOut = 0;
	
	/* Checking if UDR register is empty */
	if (GET_BIT(MUART_UCSRA, 5))
	{
		/* Transmitting data over UART */
		MUART_UDR = au8_dataByte;
		
		while ((!GET_BIT(MUART_UCSRA, 6)) && (au8_timeOut < TIMEOUT_DELAY))
		{
			/* Increase the timeout variable */
			au8_timeOut++;
			
			/* Delay for 1ms */
			_delay_ms(1);
		}
		
		/* Clear the TX flag */
		SET_BIT(MUART_UCSRA, 6);
	}
	else
	{
		/* Do nothing */
	}
	/* Return from this function */
	return;
}

void muart_sendStream(u8_t* pu8_dataStream, u8_t au8_dataSize)
{
	/* Local index counter within the loop */
	u8_t au8_index = 0;
	
	/* Loop through the data stream */
	for (au8_index = 0; au8_index < au8_dataSize; au8_index++)
	{
		/* Send data byte */
		muart_sendByte(pu8_dataStream[au8_index]);
	}
	
	/* Return from this function */
	return;
}

u8_t muart_dataExists(void)
{
	return (u8_t) GET_BIT(MUART_UCSRA, 7);
}

void muart_recvByte(u8_t* pu8_dataByte)
{
	/* Checking if there's any received data in UDR register */
	if (muart_dataExists())
	{
		/* Store the received data */
		*pu8_dataByte = MUART_UDR;
	}
	else
	{
		/* Do nothing */
	}
	
	/* Return from this function */
	return;
}