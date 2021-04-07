/**
 * @file    main.c
 * @author  Mohamed Alaa
 * @brief   This is the main source file which is responsible for running the whole project
 * @date    2021/04/06
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "HBTH_interface.h"
#include "ASMH_interface.h"

/* Uncomment below line/macro if the compiled version is going to be for the MASTER microcontroller */
//#define MASTER_VERSION

/**
 * @brief  Main function
 *
 * @return int 0 on successful execution of the program, anything else on errors
 */
int main(void)
{
	/* If the output compiled version is going to be for the MASTER microcontroller */
	#if defined MASTER_VERSION
		/* A local variable to store the received data over the Bluetooth module */
		u8_t au8_BthData = 0;
		
		/* Initialize the application is MASTER mode */
		asmh_initApp(ASMH_SPIM_MASTER);
	/* If the output compiled version is going to be for the SLAVE microcontroller */
	#else
		/* A local variable to store the received data over the SPI module from the MASTER */
		u8_t au8_SPIData = 0;
		
		/* Initialize the application is SLAVE mode */
		asmh_initApp(ASMH_SPIM_SLAVE);
	#endif
	
    while (1)
    {
		/* If the output compiled version is going to be for the MASTER microcontroller */
		#if defined MASTER_VERSION
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
		/* If the output compiled version is going to be for the SLAVE microcontroller */
		#else
			/* Get and store the received data from the MASTER over the SPI module */
			asmh_slaveSPIrecvCmd(&au8_SPIData);
			
			/* Apply specific action based on the received data from the MASTER over the SPI module*/
			asmh_slaveProcessRecvData(au8_SPIData);
			
			/* Reset the received command from the MASTER over the SPI module so it doesn't cause issues */
			au8_SPIData = 0;
		#endif
    }
}

