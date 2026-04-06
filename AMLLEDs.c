/* USER CODE BEGIN 0 */
void LEDs(uint8_t x)
{
	  led1(x & (1<<0));
	  led2(x & (1<<1));
	  led3(x & (1<<2));
	  led4(x & (1<<3));
}
/* USER CODE END 0 */


  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  LEDs(5);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */

