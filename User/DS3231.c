/**
 * @file DS3231.c
 * @author Huong Nguyen
 * @brief 
 * @version 1.0.0
 * @date 2023-09-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/*----- Inclusions ---------------------------------------------------------------------------------------------------*/

#include "DS3231.h"

/*----- Private Macros -----------------------------------------------------------------------------------------------*/

/*----- Private Typedef ----------------------------------------------------------------------------------------------*/

/*----- Private Variables --------------------------------------------------------------------------------------------*/

/*----- Private Functions Declarations -------------------------------------------------------------------------------*/

/**
 * @brief Convert normal decimal numbers to binary coded decimal 
 * 
 * @note Can relocate this function to use another object
 * @param val 
 * @return
 * 
 */
static uint8_t decToBcd(int val);

/**
 * @brief Convert binary coded decimal to normal decimal numbers
 * 
 * @note Can relocate this function to use another object
 * 
 * @note Can relocate this function to use another object
 * @param val 
 * @return
 */
static int bcdToDec(uint8_t val);

/*----- Private Functions Definitions --------------------------------------------------------------------------------*/

/**
 * @internal
 * @brief Convert normal decimal numbers to binary coded decimal 
 * 
 * @note Can relocate this function to use another object
 * @param val 
 * @return
 * 
 * @endinternal
 */
static uint8_t decToBcd(int val)
{
	return (uint8_t)((val / 10U * 16U) + (val % 10U));
}

/**
 * @internal
 * @brief Convert binary coded decimal to normal decimal numbers
 * 
 * @note Can relocate this function to use another object
 * @param val 
 * @return
 * @endinternal
 */
static int bcdToDec(uint8_t val)
{
	return (int)((val / 16U * 10U) + (val % 16U));
}

/*----- Exposed Functions Definitions --------------------------------------------------------------------------------*/

/** EOF */
