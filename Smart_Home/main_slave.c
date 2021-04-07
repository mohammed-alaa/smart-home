/**
 * @file    main.c
 * @author  Mohamed Alaa
 * @brief   This is the main source file which is responsible for running the project in the SLAVE mode
 * @date    2021/04/06
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "ASMH_interface.h"

/**
 * @brief  Main function
 *
 * @return int 0 on successful execution of the program, anything else on errors
 */
int main(void)
{
	/* A local variable to store the received data over the SPI module from the MASTER */
	u8_t au8_SPIData = 0;
	
	/* Initialize the application is SLAVE mode */
	asmh_initApp(ASMH_SPIM_SLAVE);
	
    while (1)
    {
		/* Get and store the received data from the MASTER over the SPI module */
		asmh_slaveSPIrecvCmd(&au8_SPIData);
		
		/* Apply specific action based on the received data from the MASTER over the SPI module*/
		asmh_slaveProcessRecvData(au8_SPIData);
		
		/* Reset the received command from the MASTER over the SPI module so it doesn't cause issues */
		au8_SPIData = 0;
    }
}

