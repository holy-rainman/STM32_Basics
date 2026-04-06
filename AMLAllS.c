/* USER CODE BEGIN Includes */
#include "stdio.h"
#include "string.h"
/* USER CODE END Includes */

/* USER CODE BEGIN PTD */
#define HIGH GPIO_PIN_SET
#define LOW  GPIO_PIN_RESET
/* USER CODE END PTD */

/* USER CODE BEGIN PD */
#define led1(x)		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, x? LOW:HIGH)
#define led2(x)		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, x? LOW:HIGH)
#define led3(x)		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, x? LOW:HIGH)
#define led4(x)		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, x? LOW:HIGH)
#define buzz(x)		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, x? LOW:HIGH)
#define SH_CP(x)	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, x? HIGH:LOW)
#define DS(x)		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, x? HIGH:LOW)
#define ST_CP(x)	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, x? HIGH:LOW)

#define pb1			HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1)
#define pb2			HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4)
#define pb3			HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_0)
/* USER CODE END PD */

/* USER CODE BEGIN PV */
uint32_t t0, t1, t2;
uint8_t pbStatus;
char tx2buf[100];
uint16_t ptr2disp, buff[4], cnt=0;
static uint8_t num[10] = {0xC0,0XF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
static uint8_t seg[4] = {0xF1,0xF2,0xF4,0xF8};
uint16_t adc_val;
/* USER CODE END PV */


/* USER CODE BEGIN 0 */
void LEDs(uint8_t x)
{	  led1(x & (1<<0));
	  led2(x & (1<<1));
	  led3(x & (1<<2));
	  led4(x & (1<<3));
}
uint8_t readPB(void)
{	uint8_t x=0;
	if(pb1==0) x|=(1<<0);
	if(pb2==0) x|=(1<<1);
	if(pb3==0) x|=(1<<2);
	return x;
}
void beep(uint8_t bil, uint8_t masa)
{	for(uint8_t i=0;i<bil;i++)
	{	buzz(HIGH);	HAL_Delay(masa);
		buzz(LOW);	HAL_Delay(masa);
	}
}
void displaySegment(void)
{	static uint8_t seg=0;

	ST_CP(LOW);
	for(int8_t i=15;i>-1;i--)
	{	SH_CP(LOW);
		if(buff[seg] & (1<<i))	DS(HIGH);
		else					DS(LOW);
		SH_CP(HIGH);
	}
	ST_CP(HIGH);

	if(++seg>3) seg=0;
}




void multiplexSegment(uint16_t x)
{	for(uint8_t i=0;i<4;i++)
	{	switch(i)
		{	case 0:
				ptr2disp = x/1000;
				break;
			case 1:
				ptr2disp = (x%1000) / 100;
				break;
			case 2:
				ptr2disp = (x%100) / 10;
				break;
			case 3:
				ptr2disp = x%10;
				break;
		}
		buff[i] = (num[ptr2disp]<<8) | seg[i];
	}
}
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{	if(htim -> Instance == TIM6)
	{
		displaySegment();
	}
}
void readAnalog()
{	HAL_ADC_Start(&hadc);
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


  /* USER CODE BEGIN 2 */
  t0 = t1 = t2 = HAL_GetTick();
  buzz(LOW);
  HAL_TIM_Base_Start_IT(&htim6);
  /* USER CODE END 2 */

  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  if(t0 < HAL_GetTick())
	  {
		  t0 += 500;
		  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6);
	  }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */

