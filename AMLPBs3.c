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

		  if(pbStatus != 0)
		  {
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

