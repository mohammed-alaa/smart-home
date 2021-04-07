/**
 * @file    MSPI_private.h
 * @author  Mohamed Alaa
 * @brief   This file contains the private information of SPI Module
 * @date    2021/04/06
 *
 * @copyright Copyright (c) 2021
 *
 */

/* Header file guard */
#ifndef MSPI_PRIVATE_H_
#define MSPI_PRIVATE_H_

/************************************************************************/
/*                          SPI registers                               */
/************************************************************************/

/*!
  \def	MSPI_SPCR
  Point of MSPI_SPCR's address in the memory
*/
#define MSPI_SPCR	(*(volatile u8_t*) (0x2D))

/*!
  \def	MSPI_SPSR
  Point of MSPI_SPCR's address in the memory
*/
#define MSPI_SPSR	(*(volatile u8_t*) (0x2E))

/*!
  \def	MSPI_SPDR
  Point of MSPI_SPCR's address in the memory
*/
#define MSPI_SPDR	(*(volatile u8_t*) (0x2F))

#endif /* MSPI_PRIVATE_H_ */