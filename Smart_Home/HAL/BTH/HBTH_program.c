/**
 * @file    HBTH_program.c
 * @author  Mohamed Alaa
 * @brief   This file contains the logical operations of Bluetooth Module
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
#include "MUART_interface.h"

/************************************************************************/
/*                         Functions' definitions                       */
/************************************************************************/
void hbth_init(void)
{
	/* Set the RX pin as input */
	mdio_setPinStatus(PORTD, PIN0, INPUT_FLOAT);
	
	/* Set the TX pin as output */
	mdio_setPinStatus(PORTD, PIN1, OUTPUT);
	
	/* Initialize the UART module with 9600 baud rate */
	muart_init(MUART_BAUDRATE_9600);
	
	/* Return from this function */
	return;
}

u8_t hbth_dataExists(void)
{
	/* Return whether there is a new data exists or not */
	return muart_dataExists();
}

void hbth_recvCmd(u8_t* pu8_dataByte)
{
	/* Return the received data */
	muart_recvByte(pu8_dataByte);
	
	/* Return from this function */
	return;
}