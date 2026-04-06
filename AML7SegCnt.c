  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  if(t0 < HAL_GetTick())
	  {
		  t0 += 4;
		  displaySegment();
	  }
	  if(t1 < HAL_GetTick())
	  {
		  t1 += 1000;
		  multiplexSegment(cnt);
		  if(++cnt>12) cnt=0;
	  }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */

