#include "application.h"
#include "SimpleKalmanFilter.h"
#include "RELAY.h"

/*
Du lieu ADC gia tri mvol
ADC_RES[0] -> ADC_RES[5]
*/

void	ADC_data(void)
{
	printf("%d ADC1:%d-ADC2:%d-ADC3:%d-ADC4:%d-ADC5:%d-ADC6:%d\r\n",
			adc_sampledone,
			ADC_RES[0],
			ADC_RES[1],
			ADC_RES[2],
			ADC_RES[3],
			ADC_RES[4],
			ADC_RES[5]);
}

void	COM1_checkdata(void)
{
	if(com1_data_ready)
	{
		com1_data_ready = 0;
		if((com1_buff[0] >= '0' && com1_buff[0] <= '9') 
			&& (com1_buff[1] >= '0' && com1_buff[1] <= '9') 
		&& (com1_buff[2] >= '0' && com1_buff[2] <= '9') 
		&& (com1_buff[3] >= '0' && com1_buff[3] <= '9') 
		&& (com1_buff[4] >= '0' && com1_buff[4] <= '9') 
		&& (com1_buff[5] >= '0' && com1_buff[5] <= '9'))
		{
			printf("Data com1 ok\r\n");
			Relay_Control(com1_buff[0]-'0',com1_buff[1]-'0',com1_buff[2]-'0',com1_buff[3]-'0',com1_buff[4]-'0',com1_buff[5]-'0');
		}
	}
}

void	COM2_checkdata(void)
{
	if(com2_data_ready)
	{
		com2_data_ready = 0;
		if((com2_buff[0] >= '0' && com2_buff[0] <= '9') 
			&& (com2_buff[1] >= '0' && com2_buff[1] <= '9') 
		&& (com2_buff[2] >= '0' && com2_buff[2] <= '9') 
		&& (com2_buff[3] >= '0' && com2_buff[3] <= '9') 
		&& (com2_buff[4] >= '0' && com2_buff[4] <= '9') 
		&& (com2_buff[5] >= '0' && com2_buff[5] <= '9'))
		{
			printf("Data com2 ok\r\n");
			Relay_Control(com2_buff[0]-'0',com2_buff[1]-'0',com2_buff[2]-'0',com2_buff[3]-'0',com2_buff[4]-'0',com2_buff[5]-'0');
		}
	}
}