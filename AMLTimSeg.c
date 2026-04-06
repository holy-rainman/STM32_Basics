void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim -> Instance == TIM6)
	{
		displaySegment();
	}
}
/* USER CODE END 0 */

  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  if(t1 < HAL_GetTick())
	  {
		  t1 += 1000;
		  multiplexSegment(cnt);
		  if(++cnt>16) cnt=0;
	  }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */

