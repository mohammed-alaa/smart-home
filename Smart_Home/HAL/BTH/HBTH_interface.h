/***********************************************************************************/
/* File name: HBTH_interface.h                                                     */
/* Author: Mohamed Alaa                                                            */
/* Description: This file contains the interfacing information of Bluetooth Module */
/* Date: 4/3/2021                                                                  */
/***********************************************************************************/

/* Header file guard */
#ifndef HBTH_INTERFACE_H_
#define HBTH_INTERFACE_H_

/************************************************************************/
/*                          Interfacing macros                          */
/************************************************************************/

/************************************************************************/
/*                        Functions' prototypes                         */
/************************************************************************/

/* This function is responsible for initializing the bluetooth module */
void hbth_init(void);

/* This function is responsible for checking whether there is a received data over the bluetooth module or not */
u8_t hbth_dataExists(void);

/* This function is responsible for receiving a command over the bluetooth module */
void hbth_recvCmd(u8_t* pu8_dataByte);

#endif /* HBTH_INTERFACE_H_ */