  /* USER CODE BEGIN 2 */
  /* USER CODE END 2 */


  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  strcpy(tx2buf,"\r\nHELLO WORLD!");
	  HAL_UART_Transmit_IT(&huart2, (uint8_t*)tx2buf, strlen(tx2buf));
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */

