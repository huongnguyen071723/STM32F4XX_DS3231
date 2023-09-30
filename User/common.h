/**
 * @file common.h 
 * @author Huong Nguyen
 * @brief 
 * @version 1.0.0
 * @date 2023-09-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef COMMON_H
#define COMMON_H

/*----- Inclusions ---------------------------------------------------------------------------------------------------*/

#include "app.h"
#include <stdio.h>
#include "string.h"

/*----- Exposed Macros -----------------------------------------------------------------------------------------------*/

extern UART_HandleTypeDef huart2;

#define PRINTF(...)														\
	do																	\
	{																	\
		uint8_t tmpBuff[32U] = {0};										\
		uint16_t tmpBuffLen = 0U;										\
		tmpBuffLen = sprintf((char *)tmpBuff, __VA_ARGS__);					\
		HAL_UART_Transmit(&huart2, tmpBuff, tmpBuffLen, HAL_MAX_DELAY);	\
	} while (0)

/*----- Exposed Typedef ----------------------------------------------------------------------------------------------*/

/*----- Exposed Functions --------------------------------------------------------------------------------------------*/

#endif /* COMMON_H */

/** EOF */
