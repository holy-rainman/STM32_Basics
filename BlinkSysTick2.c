  /* USER CODE BEGIN WHILE */
  uint32_t t0,t1;
  t0 = t1 = HAL_GetTick();
  while (1)
  {
	  if(t0 < HAL_GetTick())
	  {
		  t0 += 500;
		  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
	  }
	  if(t1 < HAL_GetTick())
	  {
		  t1 += 200;
		  sprintf(tx2buf,"\r\nNumber is: %d",cnt++);
		  HAL_UART_Transmit_IT(&huart2, (uint8_t*)tx2buf, strlen(tx2buf));

		  if(cnt>50) cnt=0;
	  }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */

