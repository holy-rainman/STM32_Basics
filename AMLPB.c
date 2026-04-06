  /* USER CODE BEGIN 2 */
  uint32_t t0 = HAL_GetTick();
  LEDs(0);
  /* USER CODE END 2 */


  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  if(t0 < HAL_GetTick())
	  {
		  t0 += 10;
		  uint8_t pb = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1);
		  if(pb==0) LEDs(15);
		  else		LEDs(0);
	  }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */

