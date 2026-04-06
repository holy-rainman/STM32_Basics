/* USER CODE BEGIN Includes */
#include "stdio.h"
#include "string.h"
/* USER CODE END Includes */

/* USER CODE BEGIN PV */
char tx2buf[100];
/* USER CODE END PV */

  /* USER CODE BEGIN 2 */
  strcpy(tx2buf,"\r\nHELLO WORLD!");
  HAL_UART_Transmit_IT(&huart2, (uint8_t*)tx2buf, strlen(tx2buf));
  /* USER CODE END 2 */

