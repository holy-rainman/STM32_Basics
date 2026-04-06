  /* USER CODE BEGIN 2 */
  strcpy(tx2buf,"\r\nHELLO WORLD!");
  HAL_UART_Transmit_IT(&huart2, (uint8_t*)tx2buf, strlen(tx2buf));
  HAL_Delay(1000);
  uint8_t cnt=0;
  /* USER CODE END 2 */


