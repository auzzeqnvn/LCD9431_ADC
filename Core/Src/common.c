/**
  ******************************************************************************
  * File Name          : config.c
  * Description        : This file provides code for the configuration
  *                      of the USART instances.
  ******************************************************************************
  */
  
#include "common.h"
#include "main.h"
#include "stdio.h"
#include "usart.h"
#include "application.h"
#include "SimpleKalmanFilter.h"
#include "RELAY.h"

#define	header 0x22
#define	footer1 0x55
#define	footer2 0x66

#define	COM1_MAX_SIZE	200
#define	COM2_MAX_SIZE	200

uint8_t	adc_samplecount = 0;
uint8_t	adc_sampledone = 0;

uint16_t adcBuffer[6];

uint16_t	adc1_buffer[ADC_SAMPLE];
uint16_t	adc2_buffer[ADC_SAMPLE];
uint16_t	adc3_buffer[ADC_SAMPLE];
uint16_t	adc4_buffer[ADC_SAMPLE];
uint16_t	adc5_buffer[ADC_SAMPLE];
uint16_t	adc6_buffer[ADC_SAMPLE];

uint16_t	ADC_RES[6];


uint8_t	com1_buff[COM1_MAX_SIZE];
uint8_t	com2_buff[COM2_MAX_SIZE];

uint8_t	com1_data_ready = 0;
uint8_t	com2_data_ready = 0;

uint8_t	com1_buff_cnt = 0;
uint8_t	com2_buff_cnt = 0;

uint8_t	com1_data_check = 0;
uint8_t	com2_data_check = 0;

uint8_t	Button_1,Button_2,Button_3,Button_4,Button_5,Button_6,Button_7,Button_8;
uint8_t	Button_1_last,Button_2_last,Button_3_last,Button_4_last,Button_5_last,Button_6_last,Button_7_last,Button_8_last;

uint8_t	Button_1_cnt = 0;
uint8_t Button_2_cnt = 0;
uint8_t	Button_3_cnt = 0;
uint8_t Button_4_cnt = 0;
uint8_t Button_5_cnt = 0;
uint8_t Button_6_cnt = 0;
uint8_t Button_7_cnt = 0;
uint8_t Button_8_cnt = 0;

uint32_t	time;

void UART1_CharReception_Callback(void);
void UART3_CharReception_Callback(void);
/*
Ham delay mili giay
*/
void	APP_Delay(uint16_t	ms)
{
	HAL_Delay(ms);
}


void	ADC_measure(void)
{
	uint8_t	i;
	uint32_t	value_tmp[6];
	for(i=0;i<6;i++)	value_tmp[i] = 0;
	
	for(i=0;i<ADC_SAMPLE;i++)
	{
		value_tmp[0] += adc1_buffer[i];
		value_tmp[1] += adc2_buffer[i];
		value_tmp[2] += adc3_buffer[i];
		value_tmp[3] += adc4_buffer[i];
		value_tmp[4] += adc5_buffer[i];
		value_tmp[5] += adc6_buffer[i];
	}
	for(i=0;i<6;i++) ADC_RES[i] = value_tmp[i]/(ADC_SAMPLE);
}

void	ADC_update(uint8_t	sample_order)
{
	adc1_buffer[sample_order] = updateEstimate(adcBuffer[0]*1.259);
	adc2_buffer[sample_order] = updateEstimate_2(adcBuffer[1]*1.259);
	adc3_buffer[sample_order] = updateEstimate_3(adcBuffer[2]*1.259);
	adc4_buffer[sample_order] = updateEstimate_4(adcBuffer[3]*1.259);
	adc5_buffer[sample_order] = updateEstimate_5(adcBuffer[4]*1.259);
	adc6_buffer[sample_order] = updateEstimate_6(adcBuffer[5]*1.259);
}


void	BUTTON_update(void)
{
	uint8_t	tmp;
	tmp = !HAL_GPIO_ReadPin(BUTTON1_GPIO_Port,BUTTON1_Pin);
	if(tmp != Button_1)	Button_1_cnt++;
	else Button_1_cnt = 0;
	if(Button_1_cnt > 3)	Button_1 = tmp;
	
	tmp = !HAL_GPIO_ReadPin(BUTTON2_GPIO_Port,BUTTON2_Pin);
	if(tmp != Button_2)	Button_2_cnt++;
	else Button_2_cnt = 0;
	if(Button_2_cnt > 3)	Button_2 = tmp;
	
	tmp = !HAL_GPIO_ReadPin(BUTTON3_GPIO_Port,BUTTON3_Pin);
	if(tmp != Button_3)	Button_3_cnt++;
	else Button_3_cnt = 0;
	if(Button_3_cnt > 3)	Button_3 = tmp;
	
	tmp = !HAL_GPIO_ReadPin(BUTTON4_GPIO_Port,BUTTON4_Pin);
	if(tmp != Button_4)	Button_4_cnt++;
	else Button_4_cnt = 0;
	if(Button_4_cnt > 3)	Button_4 = tmp;
	
	tmp = !HAL_GPIO_ReadPin(BUTTON5_GPIO_Port,BUTTON5_Pin);
	if(tmp != Button_5)	Button_5_cnt++;
	else Button_5_cnt = 0;
	if(Button_5_cnt > 3)	Button_5 = tmp;
	
	tmp = !HAL_GPIO_ReadPin(BUTTON6_GPIO_Port,BUTTON6_Pin);
	if(tmp != Button_6)	Button_6_cnt++;
	else Button_6_cnt = 0;
	if(Button_6_cnt > 3)	Button_6 = tmp;
	
	tmp = !HAL_GPIO_ReadPin(BUTTON7_GPIO_Port,BUTTON7_Pin);
	if(tmp != Button_7)	Button_7_cnt++;
	else Button_7_cnt = 0;
	if(Button_7_cnt > 3)	Button_7 = tmp;
	
	tmp = !HAL_GPIO_ReadPin(BUTTON8_GPIO_Port,BUTTON8_Pin);
	if(tmp != Button_8)	Button_8_cnt++;
	else Button_8_cnt = 0;
	if(Button_8_cnt > 3)	Button_8 = tmp;
}

void USART_PrChar(UART_HandleTypeDef USARTx, uint8_t data)
{
	if(HAL_UART_Transmit(&USARTx, (uint8_t *)&data, 1, 1000) != HAL_OK)
	{
	}
}

/*
Ham gui chuoi qua USARTx
USARTx: COM1, COM2
*/
void USART_Prdata(UART_HandleTypeDef USARTx, uint8_t* str)
{
	while(*str)
	{
		USART_PrChar(USARTx, *str++);
	}
}

void	USART_InterruptInit(void)
{
	LL_USART_EnableIT_RXNE(USART1);
  LL_USART_EnableIT_ERROR(USART1);
	LL_USART_EnableIT_RXNE(USART3);
  LL_USART_EnableIT_ERROR(USART3);
}




/**
  * @brief  UART error callbacks
  * @note   This example shows a simple way to report transfer error, and you can
  *         add your own implementation.
  * @retval None
  */
void UART1_Error_Callback(void)
{
  __IO uint32_t sr_reg;

  /* Disable USARTx_IRQn */
  NVIC_DisableIRQ(USART1_IRQn);
  /* Error handling example :
    - Read USART SR register to identify flag that leads to IT raising
    - Perform corresponding error handling treatment according to flag
  */
	
  sr_reg = LL_USART_ReadReg(USART1, SR);
  if (sr_reg & LL_USART_SR_NE) /*Transfer error in reception/transmission process */
  {
  }
  else
  { 
  }
}


void	UART1_GetDataByte(void)
{
	if(LL_USART_IsActiveFlag_RXNE(USART1) && LL_USART_IsEnabledIT_RXNE(USART1))
  {
    /* RXNE flag will be cleared by reading of DR register (done in call) */
    /* Call function in charge of handling Character reception */
    UART1_CharReception_Callback();
  }
	
  if(LL_USART_IsEnabledIT_ERROR(USART1) && LL_USART_IsActiveFlag_NE(USART1))
  {
    /* Call Error function */
    UART1_Error_Callback();
  }
}

void UART3_Error_Callback(void)
{
  __IO uint32_t sr_reg;

  /* Disable USARTx_IRQn */
  NVIC_DisableIRQ(USART3_IRQn);
  /* Error handling example :
    - Read USART SR register to identify flag that leads to IT raising
    - Perform corresponding error handling treatment according to flag
  */
	
  sr_reg = LL_USART_ReadReg(USART3, SR);
  if (sr_reg & LL_USART_SR_NE) /*Transfer error in reception/transmission process */
  {
  }
  else
  { 
  }
}


void	UART3_GetDataByte(void)
{
	if(LL_USART_IsActiveFlag_RXNE(USART3) && LL_USART_IsEnabledIT_RXNE(USART3))
  {
    /* RXNE flag will be cleared by reading of DR register (done in call) */
    /* Call function in charge of handling Character reception */
    UART3_CharReception_Callback();
  }
	
  if(LL_USART_IsEnabledIT_ERROR(USART3) && LL_USART_IsActiveFlag_NE(USART3))
  {
    /* Call Error function */
    UART3_Error_Callback();
  }
}




/* retarget the C library printf function to the USART */
/*# 7- Retarget printf to UART (std library and toolchain dependent) #########*/
int fputc(int ch, FILE *f)
{
    HAL_UART_Transmit(&COM1, (uint8_t*) &ch,1,1000);
    return ch;
}



/**
  * @brief  Rx Transfer completed callback
  * Du lieu se duoc dua vao buff khi dung header
	* Khi dung footer se bat thong bao du lieu san sang com1_data_ready
	* Se reset bo nhan du lieu khi chi nhan duoc footer 1 hoac do lon du lieu vuot qua do lon buff
  * @retval None
  */
void UART1_CharReception_Callback(void)
{
	uint8_t	byte;

  /* Read Received character. RXNE flag is cleared by reading of DR register */
  byte = LL_USART_ReceiveData8(USART1);
	if(com1_data_check == 0)
	{
		if(byte == header)	
		{
			com1_data_check++;
			com1_buff_cnt = 0;
		}
	}
	else if(com1_data_check == 1)
	{
		if(byte == footer1) 	com1_data_check++;
		else
		{
			com1_buff[com1_buff_cnt++] = byte;
		}
		if(com1_buff_cnt > COM1_MAX_SIZE) com1_data_check = 0;
	}
	else if(com1_data_check == 2)
	{
		if(byte == footer2)
		{
			com1_data_ready = 1;
		}
		com1_data_check = 0;
	}
	//LL_USART_TransmitData8(USART1,byte);
}

void UART3_CharReception_Callback(void)
{
	uint8_t	byte;

  /* Read Received character. RXNE flag is cleared by reading of DR register */
  byte = LL_USART_ReceiveData8(USART3);
	if(com2_data_check == 0)
	{
		if(byte == header)	
		{
			com2_data_check++;
			com2_buff_cnt = 0;
		}
	}
	else if(com2_data_check == 1)
	{
		if(byte == footer1) 	com2_data_check++;
		else
		{
			com2_buff[com2_buff_cnt++] = byte;
		}
		if(com2_buff_cnt > COM2_MAX_SIZE) com2_data_check = 0;
	}
	else if(com2_data_check == 2)
	{
		if(byte == footer2)
		{
			com2_data_ready = 1;
		}
		com2_data_check = 0;
	}
	//LL_USART_TransmitData8(USART3,byte);
}

void TimerUpdate_Callback(void)
{
	
	ADC_update(adc_samplecount);
	adc_samplecount++;
	if(adc_samplecount >= ADC_SAMPLE)	
	{		
		adc_samplecount = 0;
		adc_sampledone++;
		if(adc_sampledone > 5) adc_sampledone = 5;
	}
	if(adc_sampledone >= 5) 
	{
		HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
		ADC_measure();
	}
	else HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
	
	BUTTON_update();
	
	time++;
}


