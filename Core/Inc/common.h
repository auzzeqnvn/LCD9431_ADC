#include "stdint.h"
#include "usart.h"
#include "stm32f2xx_ll_usart.h"
#include "stm32f2xx_ll_tim.h"
#include "stdio.h"

/* Size of Reception buffer */
#define	ADC_SAMPLE	30

#define	COM1	huart1
#define	COM2	huart3

/* UART handler declaration */
//UART_HandleTypeDef UartHandle;
extern uint16_t adcBuffer[6];

extern uint16_t	adc1_buffer[ADC_SAMPLE];
extern uint16_t	adc2_buffer[ADC_SAMPLE];
extern uint16_t	adc3_buffer[ADC_SAMPLE];
extern uint16_t	adc4_buffer[ADC_SAMPLE];
extern uint16_t	adc5_buffer[ADC_SAMPLE];
extern uint16_t	adc6_buffer[ADC_SAMPLE];

extern uint8_t	adc_sampledone;

extern uint16_t	ADC_RES[6];

extern uint8_t	com1_buff[200];
extern uint8_t	com2_buff[200];

extern uint8_t	com1_data_ready;
extern uint8_t	com2_data_ready;

extern uint8_t	Button_1,Button_2,Button_3,Button_4,Button_5,Button_6,Button_7,Button_8;
extern uint8_t	Button_1_last,Button_2_last,Button_3_last,Button_4_last,Button_5_last,Button_6_last,Button_7_last,Button_8_last;

extern uint32_t time;

void	APP_Delay(uint16_t	ms);
void USART_Prdata(UART_HandleTypeDef USARTx, uint8_t* str);

void	UART1_GetDataByte(void);
void	UART3_GetDataByte(void);
void	USART_InterruptInit(void);
void TimerUpdate_Callback(void);

