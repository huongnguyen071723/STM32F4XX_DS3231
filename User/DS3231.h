/**
 * @file DS3231.h 
 * @author Huong Nguyen
 * @brief 
 * @version 1.0.0
 * @date 2023-09-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef DS3231_H
#define DS3231_H

/*----- Inclusions ---------------------------------------------------------------------------------------------------*/

#include "app.h"

/*----- Exposed Macros -----------------------------------------------------------------------------------------------*/

/** 
 * The slave address byte contains the 7-bit DS3231 address, which is 1101000, 
 * followed by the direction bit (R/W), which is 0 for a write 
 */
#define DS3231_I2C_ADDRESS							0xD0

/*----- Exposed Typedef ----------------------------------------------------------------------------------------------*/

/** Data structure of the DS3231 module */
typedef struct DS3231_t
{
	uint8_t seconds;							/**< second value */
	uint8_t minutes;							/**< minute value */
	uint8_t hour;								/**< hours value */
	uint8_t dayOfWeek;							/**< the day of week */
	uint8_t dayOfMonth;							/**< the day of month */
	uint8_t month;								/**< month */
	uint8_t year;								/**< year */
} DS3231_t;


/*----- Exposed Functions --------------------------------------------------------------------------------------------*/

#endif /* DS3231_H */

/** EOF */
