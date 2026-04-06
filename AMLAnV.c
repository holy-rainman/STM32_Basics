/* USER CODE BEGIN PV */
uint32_t t0, t1, t2;
uint8_t pbStatus;
char tx2buf[100];
uint16_t ptr2disp, buff[4], cnt=0;
static uint8_t num[10] = {0xC0,0XF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
static uint8_t seg[4] = {0xF1,0xF2,0xF4,0xF8};
uint16_t adc_val;
/* USER CODE END PV */

void readAnalog()
{
	HAL_ADC_Start(&hadc);
	if(HAL_ADC_PollForConversion(&hadc, 1000) == HAL_OK)
		adc_val = HAL_ADC_GetValue(&hadc);
	HAL_ADC_Stop(&hadc);

	float volt = (float)adc_val*3.3/1024;

	sprintf(tx2buf,"\r\nADC_IN0:%d, Volt:%.2fV",adc_val,volt);
	HAL_UART_Transmit_IT(&huart2, (uint8_t*)tx2buf, strlen(tx2buf));
	HAL_Delay(10);
}
/* USER CODE END 0 */

