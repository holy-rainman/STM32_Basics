void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim -> Instance == TIM6)
	{
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6);
	}
}
/* USER CODE END 0 */

  /* USER CODE BEGIN 2 */
  t0 = t1 = HAL_GetTick();
  buzz(LOW);
  HAL_TIM_Base_Start_IT(&htim6);
  /* USER CODE END 2 */


