/* USER CODE BEGIN PV */
uint32_t t0, t1, t2;
uint8_t pbStatus;
char tx2buf[100];
uint16_t ptr2disp, buff[4], cnt=0;
static uint8_t num[10] = {0xC0,0XF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
static uint8_t seg[4] = {0xF1,0xF2,0xF4,0xF8};
uint16_t adc_val[3];
uint8_t adcCha=0;
/* USER CODE END PV */

void readAnalog()
{
	HAL_ADC_Start(&hadc);
	for(adcCha=0; adcCha<3; adcCha++)
	{
		if(HAL_ADC_PollForConversion(&hadc, 1000) == HAL_OK)
			adc_val[adcCha] = HAL_ADC_GetValue(&hadc);
	}
	HAL_ADC_Stop(&hadc);

	sprintf(tx2buf,"\r\nv0=%d v1=%d v2=%d",adc_val[0],adc_val[1],adc_val[2]);
	HAL_UART_Transmit_IT(&huart2, (uint8_t*)tx2buf, strlen(tx2buf));
	HAL_Delay(10);
}
/* USER CODE END 0 */

