/************************************************************************************/
/* File name: ASMH_progran.c                                                        */
/* Author: Mohamed Alaa                                                             */
/* Description: This file contains the logical operations of Smart Home Application */
/* Date: 4/6/2021                                                                   */
/************************************************************************************/

/************************************************************************/
/*                             Includes                                 */
/************************************************************************/

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "MDIO_interface.h"
#include "MSPI_interface.h"
#include "HBTH_interface.h"
#include "HLED_interface.h"
#include "ASMH_private.h"
#include "ASMH_interface.h"

/************************************************************************/
/*                         Functions' definitions                       */
/************************************************************************/

void asmh_initSpi(u8_t au8_spiMode)
{
	/* Check whether the SPI Mode is in the MASTER mode */
	if (au8_spiMode == ASMH_SPIM_MASTER)
	{
		/* Initialize the SPI module in MASTER mode with MSB data mode, Sample on rising and setup on falling and clock speed of 16 */
		mspi_init(MSPI_MODE_MASTER, MSPI_DMODE_MSB, MSPI_CMODE_SAMPLE_R_SETUP_F, MSPI_CLK_BY_16);
		
		/* Set PB5 (MOSI) and PB7 (SCK) to OUTPUT */
		mdio_setPinStatus(PORTB, (PIN5|PIN7), OUTPUT);
		
		/* Set PA0 (SS) to OUTPUT */
		mdio_setPinStatus(PORTA, (PIN0), OUTPUT);
		
		/* Set PB6 (MISO) to INPUT */
		mdio_setPinStatus(PORTB, (PIN6), INPUT_FLOAT);
	}
	else
	{
		/* Initialize the SPI module in MASTER mode with MSB data mode, Sample on rising and setup on falling and clock speed of 16 */
		mspi_init(MSPI_MODE_SLAVE, MSPI_DMODE_MSB, MSPI_CMODE_SAMPLE_R_SETUP_F, MSPI_CLK_BY_16);
		
		/* Set PB5 (MOSI) and PB7 (SCK) to INPUT_FLOAT */
		mdio_setPinStatus(PORTB, (PIN5|PIN7), INPUT_FLOAT);
		
		/* Set PA0 (SS) to INPUT */
		mdio_setPinStatus(PORTA, (PIN0), INPUT_FLOAT);
		
		/* Set PB6 (MISO) to OUTPUT */
		mdio_setPinStatus(PORTB, (PIN6), OUTPUT);
	}
}

void asmh_masterBTHRecvCmd(u8_t* pu8_data)
{
	/* Receive a command over the Bluetooth module */
	hbth_recvCmd(pu8_data);
	
	/* Return from this function */
	return;
}

void asmh_masterSPISendCmd(u8_t au8_data)
{
	/* Send the 1-byte data from the MASTER to the SLAVE with ignoring the received data from the SLAVE */
	mspi_masterSendRecvByte(au8_data, 0x00);
	
	/* Return from this function */
	return;
}

void asmh_slaveSPIrecvCmd(u8_t* pu8_data)
{
	/* Receive and store the 1-byte data got from the MASTER with sending a dump data to the MASTER */
	mspi_slaveSendRecvByte(0x00, pu8_data);
	
	/* Return from this function */
	return;
}