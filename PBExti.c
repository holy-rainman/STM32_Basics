/* USER CODE BEGIN Includes */
#include "stdio.h"
#include "string.h"
/* USER CODE END Includes */

/* USER CODE BEGIN PV */
uint8_t flag=0;
uint32_t t0;
char tx2buf[100];
/* USER CODE END PV */

/* USER CODE BEGIN 0 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	flag=1;
}
/* USER CODE END 0 */

  /* USER CODE BEGIN 2 */
  EXTI -> IMR &= ~(EXTI_LINE_13);	//Masking interrupt
  t0 = HAL_GetTick();
  uint16_t cnt=0;
  EXTI -> IMR |= (EXTI_LINE_13);	//Unmasking interrupt
  /* USER CODE END 2 */



  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  if(flag==1)
	  {
		  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
		  HAL_Delay(200);
		  flag=0;
	  }
	  if(t0 < HAL_GetTick())
	  {
		  t0 += 200;
		  sprintf(tx2buf,"\r\nCnt is: %d",cnt++);
		  HAL_UART_Transmit_IT(&huart2, (uint8_t*)tx2buf, strlen(tx2buf));
	  }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }

