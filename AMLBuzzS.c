/* USER CODE BEGIN 0 */
void LEDs(uint8_t x)
{
	  led1(x & (1<<0));
	  led2(x & (1<<1));
	  led3(x & (1<<2));
	  led4(x & (1<<3));
}
uint8_t readPB(void)
{
	uint8_t x=0;
	if(pb1==0) x|=(1<<0);
	if(pb2==0) x|=(1<<1);
	if(pb3==0) x|=(1<<2);
	return x;
}
void beep(uint8_t bil, uint8_t masa)
{
	for(uint8_t i=0;i<bil;i++)
	{
		buzz(HIGH);	HAL_Delay(masa);
		buzz(LOW);	HAL_Delay(masa);
	}
}
/* USER CODE END 0 */

// SCROLL DOWN TO COPY A PIECE OF PROGRAM FOR WHILE LOOP!!



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
		  if(cnt<0) cnt=0;

		  if(pbStatus != 0)
		  {
			  beep(2,50);

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

