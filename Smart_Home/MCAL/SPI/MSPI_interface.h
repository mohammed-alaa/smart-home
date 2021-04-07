/**
 * @file    MSPI_interface.h
 * @author  Mohamed Alaa
 * @brief   This file contains the interfacing information of SPI Module
 * @date    2021/04/06
 *
 * @copyright Copyright (c) 2021
 *
 */

/* Header file guard */
#ifndef MSPI_INTERFACE_H_
#define MSPI_INTERFACE_H_

/************************************************************************/
/*                          Interfacing macros                          */
/************************************************************************/

/* SPI modes */
/*!
  \def	MSPI_MODE_SLAVE
  SPI Slave Mode
*/
#define MSPI_MODE_SLAVE		(0x00)

/*!
  \def	MSPI_MODE_MASTER
  SPI Master Mode
*/
#define MSPI_MODE_MASTER	(0x10)

/* SPI data out modes */
/*!
  \def	MSPI_DMODE_LSB
  SPI Least Significant Bit Mode
*/
#define MSPI_DMODE_LSB		(0x20)

/*!
  \def	MSPI_DMODE_MSB
  SPI Most Significant Bit Mode
*/
#define MSPI_DMODE_MSB		(0x00)

/* Clock mode */
/*!
  \def	MSPI_CMODE_SAMPLE_R_SETUP_F
  SPI Control Mode: Sample (Rising) - Setup (Falling)
*/
#define MSPI_CMODE_SAMPLE_R_SETUP_F	(0x00)

/*!
  \def	MSPI_CMODE_SAMPLE_F_SETUP_F
  SPI Control Mode: Sample (Falling) - Setup (Falling)
*/
#define MSPI_CMODE_SAMPLE_F_SETUP_F	(0x04)

/*!
  \def	MSPI_CMODE_SAMPLE_F_SETUP_R
  SPI Control Mode: Sample (Rising) - Setup (Rising)
*/
#define MSPI_CMODE_SAMPLE_F_SETUP_R	(0x80)

/*!
  \def	MSPI_CMODE_SAMPLE_R_SETUP_R
  SPI Control Mode: Sample (Rising) - Setup (Rising)
*/
#define MSPI_CMODE_SAMPLE_R_SETUP_R	(0x84)

/* SPI speed */
/*!
  \def	MSPI_CLK_BY_2
  SPI Clock speed prescaler by 2
*/
#define MSPI_CLK_BY_2	(0x40)

/*!
  \def	MSPI_CLK_BY_4
  SPI Clock speed prescaler by 4
*/
#define MSPI_CLK_BY_4	(0x00)

/*!
  \def	MSPI_CLK_BY_8
  SPI Clock speed prescaler by 8
*/
#define MSPI_CLK_BY_8	(0x41)

/*!
  \def	MSPI_CLK_BY_16
  SPI Clock speed prescaler by 16
*/
#define MSPI_CLK_BY_16	(0x01)

/*!
  \def	MSPI_CLK_BY_32
  SPI Clock speed prescaler by 32
*/
#define MSPI_CLK_BY_32	(0x42)

/*!
  \def	MSPI_CLK_BY_64
  SPI Clock speed prescaler by 64
*/
#define MSPI_CLK_BY_64	(0x02)

/*!
  \def	MSPI_CLK_BY_128
  SPI Clock speed prescaler by 128
*/
#define MSPI_CLK_BY_128	(0x03)

/************************************************************************/
/*                        Functions' prototypes                         */
/************************************************************************/

/**
 * @brief   This function is responsible for initializing the SPI module
 * @param	au8_spiMode		Variable to determine which mode the SPI module should be initialized in (MASTER or SLAVE)
 * @param	au8_dataOutMode	Variable to determine which data out mode the SPI module should be working with (MSB or LSB)
 * @param	au8_clockMode	Variable to determine which clock mode the SPI module should be running on
 * @param	au8_spiSpeed	Variable to determine what clock speed the SPI module should be running on
 *
 * @return   void
 */
void mspi_init(u8_t au8_spiMode, u8_t au8_dataOutMode, u8_t au8_clockMode, u8_t au8_spiSpeed);

/**
 * @brief   This function is responsible for sending and receiving 1 byte in master mode
 * @param   au8_sendData	Specific data to be sent over the SPI module to the SLAVE
 * @param   pu8_recvData	Variable to hold and store the received data from the SLAVE over the SPI module
 *
 * @return   void
 */
void mspi_masterSendRecvByte(u8_t au8_sendData, u8_t* pu8_recvData);

/**
 * @brief   This function is responsible for sending and receiving 1 byte in slave mode
 * @param   au8_sendData	Specific data to be sent over the SPI module to the MASTER
 * @param   pu8_recvData	Variable to hold and store the received data from the MASTER over the SPI module
 *
 * @return   void
 */
void mspi_slaveSendRecvByte(u8_t au8_sendData, u8_t* pu8_recvData);

#endif /* MSPI_INTERFACE_H_ */