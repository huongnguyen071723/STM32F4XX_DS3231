/**
 * @file app.c
 * @author Huong Nguyen
 * @brief 
 * @version 1.0.0
 * @date 2023-09-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/*----- Inclusions ---------------------------------------------------------------------------------------------------*/

#include "app.h"
#include "common.h"
#include "DS3231.h"

/*----- Private Macros -----------------------------------------------------------------------------------------------*/

/*----- Private Typedef ----------------------------------------------------------------------------------------------*/

/*----- Private Variables --------------------------------------------------------------------------------------------*/

static DS3231_t Time = 
{
	.seconds = 15U,
	.minutes = 15U,
	.hour = 15U,
	.dayOfMonth = 15U,
	.month = 5U,
	.year = 23U
};

/*----- Private Functions Declarations -------------------------------------------------------------------------------*/

/*----- Private Functions Definitions --------------------------------------------------------------------------------*/

/*----- Exposed Functions Definitions --------------------------------------------------------------------------------*/

/**
 * @brief Main Application function
 * 
 * 
 * @param  
 * @return 
 */
int app_main()
{
	PRINTF("app_main\r\n");

	ds3231_set_time(&Time);
	while (1)
	{

		ds3231_get_time(&Time);

		PRINTF("%02d %02d %02d %02d %02d %02d\r\n", Time.seconds, Time.minutes, Time.hour, Time.dayOfMonth, Time.month, Time.year);

		HAL_Delay(500U);
	}

	return 0;
}

/** EOF */
