/* USER CODE BEGIN Includes */
#include "stdio.h"
#include "string.h"
/* USER CODE END Includes */


/* USER CODE BEGIN PTD */
#define HIGH GPIO_PIN_SET
#define LOW  GPIO_PIN_RESET
/* USER CODE END PTD */


/* USER CODE BEGIN PD */
#define led1(x)		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, x? LOW:HIGH)
#define led2(x)		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, x? LOW:HIGH)
#define led3(x)		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, x? LOW:HIGH)
#define led4(x)		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, x? LOW:HIGH)
/* USER CODE END PD */

/* USER CODE BEGIN 0 */
void LEDs(uint8_t x)
{	led1(x & (1<<0));
	led2(x & (1<<1));
	led3(x & (1<<2));
	led4(x & (1<<3));
}
/* USER CODE END 0 */

  /* USER CODE BEGIN WHILE */
  while (1)
  {	  for(uint8_t i=0;i<16;i++)
	  {	  LEDs(i);
		  HAL_Delay(300);
	  }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
