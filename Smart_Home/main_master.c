/**
 * @file    main.c
 * @author  Mohamed Alaa
 * @brief   This is the main source file which is responsible for running the project in the MASTER mode
 * @date    2021/04/06
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "HBTH_interface.h"
#include "ASMH_interface.h"

/**
 * @brief  Main function
 *
 * @return int 0 on successful execution of the program, anything else on errors
 */
int main(void)
{
	/* A local variable to store the received data over the Bluetooth module */
	u8_t au8_BthData = 0;
	
	/* Initialize the application is MASTER mode */
	asmh_initApp(ASMH_SPIM_MASTER);
	
    while (1)
    {
		/* Checking whether there is a new received data */
		if (hbth_dataExists())
		{
			/* Get and store the received data over the Bluetooth module */
			asmh_masterBTHRecvCmd(&au8_BthData);
			
			/* Send the received Bluetooth data to the SLAVE over the SPI */
			asmh_masterSPISendCmd(au8_BthData);
			
			/* Reset the received data over the Bluetooth module so it doesn't cause issues */
			au8_BthData = 0;
		}
		else
		{
			/* Do nothing */
		}
    }
}

