/**
 * @file    MUART_interface.h
 * @author  Mohamed Alaa
 * @brief   This file contains the interfacing information of UART Module
 * @date    2021/04/06
 *
 * @copyright Copyright (c) 2021
 *
 */

/* Header file guard */
#ifndef MUART_INTERFACE_H_
#define MUART_INTERFACE_H_

/************************************************************************/
/*                          Interfacing macros                          */
/************************************************************************/

/* UART baud rate register values at 16MHz */
/*!
  \def	MUART_BAUDRATE_2400
  UART Baud Rate of 2400
*/
#define MUART_BAUDRATE_2400		(416)

/*!
  \def	MUART_BAUDRATE_4800
  UART Baud Rate of 4800
*/
#define MUART_BAUDRATE_4800		(207)

/*!
  \def	MUART_BAUDRATE_9600
  UART Baud Rate of 9600
*/
#define MUART_BAUDRATE_9600		(103)

/*!
  \def	MUART_BAUDRATE_19200
  UART Baud Rate of 19200
*/
#define MUART_BAUDRATE_19200	(51)

/*!
  \def	MUART_BAUDRATE_115200
  UART Baud Rate of 115200
*/
#define MUART_BAUDRATE_115200	(8)

/************************************************************************/
/*                        Functions' prototypes                         */
/************************************************************************/

/**
 * @brief   This function is responsible for initializing the UART module with specific baud rate
 * @param   au8_baudRate	Variable to determine which baud rate the UART should be running on
 *
 * @return   void
 */
void muart_init(u8_t au8_baudRate);

/**
 * @brief   This function is responsible for sending one byte of data over the UART peripheral
 * @param   au8_dataByte Specific 1-byte value to be sent over the UART module
 *
 * @return   void
 */
void muart_sendByte(u8_t au8_dataByte);

/**
 * @brief   This function is responsible for sending stream of data bytes over the UART peripheral
 * @param   pu8_dataStream	Stream of 1-bytes items each to be sent over the UART module
 * @param   au8_dataSize	Size of the stream to be sent over the UART module
 *
 * @return   void
 */
void muart_sendStream(u8_t* pu8_dataStream, u8_t au8_dataSize);

/**
 * @brief	This function is responsible for checking whether there is a received data or not
 *
 * @return   1 if there is a new unread data exists, 0 otherwise
 */
u8_t muart_dataExists(void);

/**
 * @brief   This function is responsible for receiving one byte of data over the UART peripheral
 * @param   pu8_dataByte	Pointer to store the received 1-byte data over the UART module
 *
 * @return   void
 */
void muart_recvByte(u8_t* pu8_dataByte);

#endif /* MUART_INTERFACE_H_ */