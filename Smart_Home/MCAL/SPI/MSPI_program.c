/*****************************************************************************/
/* File name: MSPI_program.c                                                 */
/* Author: Mohamed Alaa                                                      */
/* Description: This file contains the logical operations of SPI Module      */
/* Date: 3/10/2021                                                           */
/*****************************************************************************/

/************************************************************************/
/*                             Includes                                 */
/************************************************************************/

#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"
#include "MSPI_private.h"
#include "MSPI_interface.h"
#define F_CPU 16000000UL
#include "util/delay.h"

/************************************************************************/
/*                         Important macros                             */
/************************************************************************/

#define TIMEOUT_DELAY (100)

/************************************************************************/
/*                         Functions' definitions                       */
/************************************************************************/
void mspi_init(u8_t au8_spiMode, u8_t au8_dataOutMode, u8_t au8_clockMode, u8_t au8_spiSpeed)
{
	/* Enable the SPI mode, set the data out mode, SPI mode, clock mode & SPI speed */
	MSPI_SPCR = (0x40) | au8_dataOutMode | au8_spiMode | au8_clockMode | au8_spiSpeed;
	
	/* (En/Dis)able the SPI2X bit based on the SPI speed */
	MSPI_SPSR = (au8_spiSpeed >> 6);
	
	/* Return from this function */
	return;
}

void mspi_masterSendRecvByte(u8_t au8_sendData, u8_t* pu8_recvData)
{
	/* Local variable for timing out operation */
	u8_t au8_timeOut = 0;
	
	/* Send the new data through SPI bus from master to slave */
	MSPI_SPDR = au8_sendData;
	
	/* Wait for the data to be transmitted or a timeout occurs */
	while ((!GET_BIT(MSPI_SPSR, 7)) && (au8_timeOut < TIMEOUT_DELAY))
	{
		/* Increase the timeout variable */
		au8_timeOut++;
		
		/* Delay for 1us */
		_delay_us(1);
	}
	
	/* Return the received data from the slave to the master */
	*pu8_recvData = MSPI_SPDR;
	
	/* Return from this function */
	return;
}

void mspi_slaveSendRecvByte(u8_t au8_sendData, u8_t* pu8_recvData)
{
	/* Send data through SPI bus from slave to master */
	MSPI_SPDR = au8_sendData;
	
	/* Check whether theres any new data from master */
	if (GET_BIT(MSPI_SPSR, 7))
	{
		/* Get the received data from master */
		*pu8_recvData = MSPI_SPDR;
	}
	else
	{
		/* Do nothing */
	}
	
	/* Return from this function */
	return;
}