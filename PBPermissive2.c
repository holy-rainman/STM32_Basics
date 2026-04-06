  /* USER CODE BEGIN WHILE */
  uint32_t t0,t1;
  t0 = t1 = HAL_GetTick();
  uint8_t pb;
  while (1)
  {
	  if(t0 < HAL_GetTick())
	  {
		  t0 += 500;
		  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
	  }
	  if(t1 < HAL_GetTick())
	  {
		  t1 += 10;
		  pb = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13);

		  if(pb==0)
		  {
			  sprintf(tx2buf,"\r\nCnt value: %d",++cnt);
			  HAL_UART_Transmit_IT(&huart2, (uint8_t*)tx2buf, strlen(tx2buf));
			  while(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13)==GPIO_PIN_RESET);
			  HAL_Delay(200);
		  }
	  }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */

