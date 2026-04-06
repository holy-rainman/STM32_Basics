void readAnalog()
{
	HAL_ADC_Start(&hadc);
	if(HAL_ADC_PollForConversion(&hadc, 1000) == HAL_OK)
		adc_val = HAL_ADC_GetValue(&hadc);
	HAL_ADC_Stop(&hadc);

	float volt = (float)adc_val*3.3/1024;
	float temp = volt*100;

	sprintf(tx2buf,"\r\nADC_IN0:%d, Volt:%.2fV, Temp:%.2fC",adc_val,volt,temp);
	HAL_UART_Transmit_IT(&huart2, (uint8_t*)tx2buf, strlen(tx2buf));
	HAL_Delay(10);
}
/* USER CODE END 0 */

