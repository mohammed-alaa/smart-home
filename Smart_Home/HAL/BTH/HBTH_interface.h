/**
 * @file    HBTH_interface.h
 * @author  Mohamed Alaa
 * @brief   This file contains the interfacing information of Bluetooth Module
 * @date    2021/04/06
 *
 * @copyright Copyright (c) 2021
 *
 */

/* Header file guard */
#ifndef HBTH_INTERFACE_H_
#define HBTH_INTERFACE_H_

/************************************************************************/
/*                          Interfacing macros                          */
/************************************************************************/

/************************************************************************/
/*                        Functions' prototypes                         */
/************************************************************************/

/**
 * @brief   This function is responsible for initializing the bluetooth module
 *
 * @return	void
 */
void hbth_init(void);

/**
 * @brief   This function is responsible for checking whether there is a received data over the bluetooth module or not
 *
 * @return	1 if there is a new unread data, 0 otherwise
 */
u8_t hbth_dataExists(void);

/**
 * @brief   This function is responsible for receiving a command over the bluetooth module
 * @param   pu8_dataByte Pointer to store the received command over the Bluetooth module
 *
 * @return	void
 */
void hbth_recvCmd(u8_t* pu8_dataByte);

#endif /* HBTH_INTERFACE_H_ */