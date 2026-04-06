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

  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  led1(HIGH);
	  led2(LOW);
	  led3(HIGH);
	  led4(LOW);
	  HAL_Delay(100);
	  led1(LOW);
	  led2(HIGH);
	  led3(LOW);
	  led4(HIGH);
	  HAL_Delay(100);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
