/**
 * @file    ASMH_program.c
 * @author  Mohamed Alaa
 * @brief   This file contains the logical operations of Smart Home Application
 * @date    2021/04/06
 * @dir		APP/
 *
 * @copyright Copyright (c) 2021
 */

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

static void asmh_initSpi(u8_t au8_spiMode)
{
	/* Check whether the SPI Mode is in the MASTER mode */
	if (au8_spiMode == ASMH_SPIM_MASTER)
	{
		/* Set PB5 (MOSI) and PB7 (SCK) to OUTPUT */
		mdio_setPinStatus(PORTB, (PIN5|PIN7), OUTPUT);
		
		/* Set PA0 (SS) to OUTPUT */
		mdio_setPinStatus(PORTA, (PIN0), OUTPUT);
		
		/* Set PB6 (MISO) to INPUT */
		mdio_setPinStatus(PORTB, (PIN6), INPUT_FLOAT);
		
		/* Initialize the SPI module in MASTER mode */
		au8_spiMode = MSPI_MODE_MASTER;
	}
	else
	{
		/* Set PB5 (MOSI) and PB7 (SCK) to INPUT_FLOAT */
		mdio_setPinStatus(PORTB, (PIN5|PIN7), INPUT_FLOAT);
		
		/* Set PA0 (SS) to INPUT */
		mdio_setPinStatus(PORTA, (PIN0), INPUT_FLOAT);
		
		/* Set PB6 (MISO) to OUTPUT */
		mdio_setPinStatus(PORTB, (PIN6), OUTPUT);
		
		/* Initialize the SPI module in SLAVE mode */
		au8_spiMode = MSPI_MODE_SLAVE;
	}
	
	/* Initialize the SPI module with MSB data mode, Sample on rising and setup on falling and clock speed of 16 */
	mspi_init(au8_spiMode, MSPI_DMODE_MSB, MSPI_CMODE_SAMPLE_R_SETUP_F, MSPI_CLK_BY_16);
}

void asmh_initApp(u8_t au8_mode)
{
	/* Initialize SPI module */
	asmh_initSpi(au8_mode);
	
	/* Check whether the SPI Mode is in the MASTER mode */
	if (au8_mode == ASMH_SPIM_MASTER)
	{
		/* Initialize the Bluetooth module */
		hbth_init();
	}
	else
	{
		/* Initialize the LED1 in the LED module */
		hled_init(HLED_LED1);
		
		/* Initialize the LED 2 in the LED module */
		hled_init(HLED_LED2);
	}
	/* Return from this function */
	return;
}

void asmh_masterBTHRecvCmd(u8_t* pu8_cmd)
{
	/* Receive a command over the Bluetooth module */
	hbth_recvCmd(pu8_cmd);
	
	/* Return from this function */
	return;
}

void asmh_masterSPISendCmd(u8_t au8_cmd)
{
	/* Send the 1-byte data from the MASTER to the SLAVE with ignoring the received data from the SLAVE */
	mspi_masterSendRecvByte(au8_cmd, 0x00);
	
	/* Return from this function */
	return;
}

void asmh_slaveSPIrecvCmd(u8_t* pu8_cmd)
{
	/* Receive and store the 1-byte data got from the MASTER with sending a dump data to the MASTER */
	mspi_slaveSendRecvByte(0x00, pu8_cmd);
	
	/* Return from this function */
	return;
}

void asmh_slaveProcessRecvData(u8_t au8_data)
{
	/* Switch over the received data from the MASTER over the SPI module */
	switch (au8_data)
	{
		/* In case of char a */
		case 'a':
			/* Turn on LED1 */
			hled_turnOnLED(HLED_LED1);
		
			/* Break from this case */
			break;
		/* In case of char b */
		case 'b':
			/* Turn off LED1 */
			hled_turnOffLED(HLED_LED1);
		
			/* Break from this case */
			break;
		/* In case of char c */
		case 'c':
			/* Turn on LED2 */
			hled_turnOnLED(HLED_LED2);
		
			/* Break from this case */
			break;
		/* In case of char d */
		case 'd':
			/* Turn off LED2 */
			hled_turnOffLED(HLED_LED2);
		
			/* Break from this case */
			break;
		/* In case of char e */
		case 'e':
			/* Toggle LED1 */
			hled_toggleLED(HLED_LED1);
		
			/* Break from this case */
			break;
		/* In case of char f */
		case 'f':
			/* Toggle LED2 */
			hled_toggleLED(HLED_LED2);
		
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