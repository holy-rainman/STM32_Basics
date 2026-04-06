/* USER CODE BEGIN PD */
#define led1(x)		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, x? LOW:HIGH)
#define led2(x)		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, x? LOW:HIGH)
#define led3(x)		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, x? LOW:HIGH)
#define led4(x)		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, x? LOW:HIGH)
#define buzz(x)		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, x? LOW:HIGH)
#define pb1			HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1)
#define pb2			HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4)
#define pb3			HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0)
/* USER CODE END PD */

  /* USER CODE BEGIN 2 */
  t0 = HAL_GetTick();
  int8_t cnt=0;
  buzz(LOW);
  /* USER CODE END 2 */

// SCROLL DOWN TO COPY A PIECE OF PROGRAM FOR WHILE LOOP!!








  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  if(t0 < HAL_GetTick())
	  {
		  t0 += 10;
		  pbStatus = readPB();

		  if(pbStatus == 4) cnt++;
		  if(pbStatus == 1) cnt--;
		  if(pbStatus == 2) cnt=0;
		  if(cnt<0) cnt=0;

		  if(pbStatus != 0)
		  {
			  buzz(HIGH);
			  HAL_Delay(50);
			  buzz(LOW);

			  sprintf(tx2buf,"\r\nCnt value is: %d",cnt);
			  HAL_UART_Transmit_IT(&huart2, (uint8_t*)tx2buf, strlen(tx2buf));
			  while(readPB() != 0);
			  HAL_Delay(200);
		  }
	  }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */

