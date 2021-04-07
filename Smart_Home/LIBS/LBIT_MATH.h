/**
 * @file    LBIT_MATH.h
 * @author  Ahmed Ashraf (ahmedashrafelnaqeeb@gmail.com)
 * @brief   This header file contains required mathematical operations over bits, (Bit manipulation).
 * @version 1.0
 * @date    2020-09-18
 *
 * @copyright Copyright (c) 2020
 *
 */

/*Header file guard*/
#ifndef _LBIT_MATH_H_
#define _LBIT_MATH_H_

/*!
  \def	SET_BIT(REG, BIT)
  Set a specific BIT in a certain register to 1
*/
#define SET_BIT(REG, BIT)      REG |= (1<<BIT)

/*!
  \def	CLEAR_BIT(REG, BIT)
  Set a specific BIT in a certain register to 0
*/
#define CLEAR_BIT(REG, BIT)    REG &= ~(1<<BIT)

/*!
  \def	GET_BIT(REG, BIT)
  Get the required bit value
*/
#define GET_BIT(REG, BIT)      ((REG >> BIT)&1)

/*!
  \def	TOGGLE_BIT(REG, BIT)
  Toggle the required bit value
*/
#define TOGGLE_BIT(REG, BIT)   REG ^= (1<<BIT)

#endif /*_LBIT_MATH_H_*/
