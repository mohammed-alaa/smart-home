#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "HBTH_interface.h"
#include "HLED_interface.h"
#include "ASMH_interface.h"

/* Uncomment below line/macro if the compiled version is going to be for the MASTER microcontroller */
#define MASTER_VERSION

int main(void)
{
	/* If the output compiled version is going to be for the MASTER microcontroller */
	#if defined MASTER_VERSION
		/* A local variable to store the received data over the Bluetooth module */
		u8_t au8_BthData = 0;
		
		/* Initialize Bluetooth module */
		hbth_init();
	
		/* Initialize SPI module as MASTER mode with MSB data mode, sample on rising setup on falling and clock speed by 16 */
		asmh_initSpi(ASMH_SPIM_MASTER);
	/* If the output compiled version is going to be for the SLAVE microcontroller */
	#else
		/* A local variable to store the received data over the SPI module from the MASTER */
		u8_t au8_SPIData = 0;
		
		/* Initialize the LED1 */
		hled_init(HLED_LED1);
		
		/* Initialize the LED 2 */
		hled_init(HLED_LED2);
		
		/* Initialize SPI module as SLAVE mode with MSB data mode, sample on rising setup on falling and clock speed by 16 */
		asmh_initSpi(ASMH_SPIM_SLAVE);
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
			/* Get and store the received data over the SPI module from the MASTER */
			asmh_slaveSPIrecvCmd(&au8_SPIData);
			
			/* Switch over the received SPI data from the MASTER */
			switch (au8_SPIData)
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
			
			/* Reset the received command over the SPI module from the MASTER so it doesn't cause issues */
			au8_SPIData = 0;
		#endif
    }
}

