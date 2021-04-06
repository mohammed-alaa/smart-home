/*****************************************************************************/
/* File name: MSPI_interface.h                                               */
/* Author: Mohamed Alaa                                                      */
/* Description: This file contains the interfacing information of SPI Module */
/* Date: 3/10/2021                                                           */
/*****************************************************************************/

/* Header file guard */
#ifndef MSPI_INTERFACE_H_
#define MSPI_INTERFACE_H_

/************************************************************************/
/*                          Interfacing macros                          */
/************************************************************************/

/* SPI modes */
#define MSPI_MODE_SLAVE		(0x00)
#define MSPI_MODE_MASTER	(0x10)

/* SPI data out modes */
#define MSPI_DMODE_LSB		(0x20)
#define MSPI_DMODE_MSB		(0x00)

/* Clock mode */
#define MSPI_CMODE_SAMPLE_R_SETUP_F	(0x00)
#define MSPI_CMODE_SAMPLE_F_SETUP_F	(0x04)
#define MSPI_CMODE_SAMPLE_F_SETUP_R	(0x80)
#define MSPI_CMODE_SAMPLE_R_SETUP_R	(0x84)

/* SPI speed */
#define MSPI_CLK_BY_2	(0x40)
#define MSPI_CLK_BY_4	(0x00)
#define MSPI_CLK_BY_8	(0x41)
#define MSPI_CLK_BY_16	(0x01)
#define MSPI_CLK_BY_32	(0x42)
#define MSPI_CLK_BY_64	(0x02)
#define MSPI_CLK_BY_128	(0x03)

/************************************************************************/
/*                        Functions' prototypes                         */
/************************************************************************/

/* This function is responsible for initializing the SPI module */
void mspi_init(u8_t au8_spiMode, u8_t au8_dataOutMode, u8_t au8_clockMode, u8_t au8_spiSpeed);

/* This function is responsible for sending and receiving 1 byte in master mode */
void mspi_masterSendRecvByte(u8_t au8_sendData, u8_t* pu8_recvData);

/* This function is responsible for sending and receiving 1 byte in slave mode */
void mspi_slaveSendRecvByte(u8_t au8_sendData, u8_t* pu8_recvData);

#endif /* MSPI_INTERFACE_H_ */