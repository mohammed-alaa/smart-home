/*****************************************************************************************/
/* File name: ASMH_interface.h                                                           */
/* Author: Mohamed Alaa                                                                  */
/* Description: This file contains the interfacing information of Smart Home Application */
/* Date: 4/6/2021                                                                        */
/*****************************************************************************************/

/* Header file guard */
#ifndef ASMH_INTERFACE_H_
#define ASMH_INTERFACE_H_

/************************************************************************/
/*                          Interfacing macros                          */
/************************************************************************/

/* SPI Module Modes */
#define ASMH_SPIM_MASTER	(0)
#define ASMH_SPIM_SLAVE		(1)

/************************************************************************/
/*                        Functions' prototypes                         */
/************************************************************************/

/* This function is responsible for initializing the SPI module with a specific mode whether MASTER or SLAVE mode */
void asmh_initSpi(u8_t au8_spiMode);

/* This function is responsible for receiving data over the Bluetooth module in the MASTER mode */
void asmh_masterBTHRecvCmd(u8_t* pu8_data);

/* This function is responsible for sending data over the SPI module in the MASTER mode */
void asmh_masterSPISendCmd(u8_t au8_data);

/* This function is responsible for receiving data over the SPI module in the SLAVE mode */
void asmh_slaveSPIrecvCmd(u8_t* pu8_data);

#endif /* ASMH_INTERFACE_H_ */