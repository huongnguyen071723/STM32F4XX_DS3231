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
#include "common.h"

extern I2C_HandleTypeDef hi2c1;

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

/**
 * @internal
 * @brief Transmit data to the DS3231 module via I2C protocol
 * 
 * 
 * @param pBuffer 
 * @param dataLen 
 * @endinternal
 */
void i2c_transmit_data(uint8_t *pBuffer, uint16_t dataLen)
{
	if ((pBuffer == NULL) || (dataLen == 0U))
	{
		return;
	}
	else
	{
		HAL_I2C_Mem_Write(&hi2c1, DS3231_I2C_ADDRESS, 0x00, 1, pBuffer, dataLen, 1000);
	}
}

/**
 * @internal
 * @brief Receive data from the DS3231 module via I2C protocol
 * 
 * @param pBuffer 
 * @param dataLen 
 * @endinternal
 */
void i2c_receive_data(uint8_t *pBuffer, uint16_t dataLen)
{
	if ((pBuffer == NULL) || (dataLen == 0U))
	{
		return;
	}
	else
	{
		HAL_I2C_Mem_Read(&hi2c1, DS3231_I2C_ADDRESS, 0x00, 1, pBuffer, dataLen, 1000);
	}
}

/**
 * @internal
 * @brief Get time data from the DS3231 module
 * 
 * 
 * @param pTime 
 * @endinternal
 */
void ds3231_get_time(DS3231_t *pTime)
{
	if (pTime == NULL)
	{
		return;
	}
	else
	{
		uint8_t tmpBuffer[7U];

		i2c_receive_data(tmpBuffer, sizeof(tmpBuffer));

		pTime->seconds = bcdToDec(tmpBuffer[0U]);
		pTime->minutes = bcdToDec(tmpBuffer[1U]);
		pTime->hour = bcdToDec(tmpBuffer[2U]);
		pTime->dayOfWeek = bcdToDec(tmpBuffer[3U]);
		pTime->dayOfMonth = bcdToDec(tmpBuffer[4U]);
		pTime->month = bcdToDec(tmpBuffer[5U]);
		pTime->year = bcdToDec(tmpBuffer[6U]);
	}
}

/**
 * @internal
 * @brief Set time data to the DS3231 module
 * 
 * 
 * @param pTime 
 * @endinternal
 */
void ds3231_set_time(DS3231_t *pTime)
{
	if (pTime == NULL)
	{
		return;
	}
	else
	{
		uint8_t tmpBuffer[7U];
		tmpBuffer[0U] = decToBcd(pTime->seconds);
		tmpBuffer[1U] = decToBcd(pTime->minutes);
		tmpBuffer[2U] = decToBcd(pTime->hour);
		tmpBuffer[3U] = decToBcd(pTime->dayOfWeek);
		tmpBuffer[4U] = decToBcd(pTime->dayOfMonth);
		tmpBuffer[5U] = decToBcd(pTime->month);
		tmpBuffer[6U] = decToBcd(pTime->year);

		i2c_transmit_data(tmpBuffer, sizeof(tmpBuffer));
	}
}

/**
 * @internal
 * @brief Get temperature from the DS3231 module
 * 
 * 
 * @param  
 * @endinternal
 */
float ds3231_get_temperature(void)
{
	float retVal = 0;

	return retVal;
}

/** EOF */
