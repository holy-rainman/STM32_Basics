/* USER CODE BEGIN PD */
#define led1(x)		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, x? LOW:HIGH)
#define led2(x)		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, x? LOW:HIGH)
#define led3(x)		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, x? LOW:HIGH)
#define led4(x)		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, x? LOW:HIGH)
#define pb1			HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1)
#define pb2			HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4)
#define pb3			HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0)
/* USER CODE END PD */

/* USER CODE BEGIN PV */
uint32_t t0;
uint8_t pbStatus;
char tx2buf[100];
/* USER CODE END PV */


/* USER CODE BEGIN 0 */
void LEDs(uint8_t x)
{
	  led1(x & (1<<0));
	  led2(x & (1<<1));
	  led3(x & (1<<2));
	  led4(x & (1<<3));
}
uint8_t readPB(void)
{
	uint8_t x=0;
	if(pb1==0) x|=(1<<0);
	if(pb2==0) x|=(1<<1);
	if(pb3==0) x|=(1<<2);
	return x;
}
/* USER CODE END 0 */
  /* USER CODE BEGIN 2 */
  t0 = HAL_GetTick();
  /* USER CODE END 2 */


  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  if(t0 < HAL_GetTick())
	  {
		  t0 += 10;
		  pbStatus = readPB();
		  sprintf(tx2buf,"\r\nPB status: %d",pbStatus);
		  HAL_UART_Transmit_IT(&huart2, (uint8_t*)tx2buf, strlen(tx2buf));
	  }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */

