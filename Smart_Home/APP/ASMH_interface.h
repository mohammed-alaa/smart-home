/**
 * @file    ASMH_interface.h
 * @author  Mohamed Alaa
 * @brief   This file contains the interfacing information of Smart Home Application
 * @date    2021/04/06
 * @dir		APP/
 *
 * @copyright Copyright (c) 2021
 *
 */

/* Header file guard */
#ifndef ASMH_INTERFACE_H_
#define ASMH_INTERFACE_H_

/************************************************************************/
/*                          Interfacing macros                          */
/************************************************************************/

/* SPI Module modes */
/*!
  \def	ASMH_SPIM_MASTER
  Indicates that the MASTER mode equals 0 in the SPI module
*/
#define ASMH_SPIM_MASTER	(0)

/*!
  \def	ASMH_SPIM_SLAVE
  Indicates that the SLAVE mode equals 1 in the SPI module
*/
#define ASMH_SPIM_SLAVE		(1)

/************************************************************************/
/*                        Functions' prototypes                         */
/************************************************************************/

/**
 * @brief   This function is responsible for initializing the application module with a specific mode whether MASTER mode or SLAVE mode
 * @param	au8_mode	Variable to determine which mode the application should be initialized in
 *
 * @return void
 */
void asmh_initApp(u8_t au8_mode);

/**
 * @brief   This function is responsible for receiving command in the MASTER mode over the Bluetooth module
 * @param	pu8_data	Pointer to store the received command in the MASTER mode over the Bluetooth module
 *
 * @return void
 */
void asmh_masterBTHRecvCmd(u8_t* pu8_data);

/**
 * @brief   This function is responsible for sending command over the SPI module in the MASTER mode
 * @param	au8_cmd	Variable to hold the received command over the Bluetooth module and send it to the SLAVE over the SPI module
 *
 * @return void
 */
void asmh_masterSPISendCmd(u8_t au8_cmd);

/**
 * @brief   This function is responsible for receiving command over the SPI module in the SLAVE mode
 * @param   pu8_cmd	Pointer to store the received command in the SLAVE mode from the MASTER over the SPI module
 *
 * @return void
 */
void asmh_slaveSPIrecvCmd(u8_t* pu8_cmd);

/**
 * @brief   This functions is responsible for processing the received data from the MASTER over the SPI module
 * @param   au8_data	Variable to hold the received command over the SPI module from the MASTER and apply specific action(s) based on the received command
 *
 * @return void
 */
void asmh_slaveProcessRecvData(u8_t au8_data);

#endif /* ASMH_INTERFACE_H_ */