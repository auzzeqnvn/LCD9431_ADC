#include "RELAY.h"
#include "74HC595.h"


uint16_t	i;

void	Relay_Init(void)
{
	HC595_Init();
	Relay_Control(0,0,0,0,0,0);
	HC595_Enable();
}

uint8_t	Relay_RowConvert(uint8_t	row)
{
	switch(row)
	{
		case 1:	return 0x01;
		case 2:	return 0x02;
		case 3:	return 0x04;
		case 4:	return 0x08;
		case 5:	return 0x10;
		case 6:	return 0x20;
		case 7:	return 0x40;
		default:	return 0;
	}
}

/*
Ham dieu khien relay
row1,row2 : 1-6
row3...row6: 1-7
*/
void	Relay_Control(uint8_t	row1,uint8_t	row2,uint8_t	row3,uint8_t	row4,uint8_t	row5,uint8_t	row6)
{
	uint8_t	tmp1;
	uint8_t	tmp2;
	uint8_t	byte[5];
	if(row1 < 7)	tmp1 = Relay_RowConvert(row1);
	else	tmp1 = 0;
	
	if(row2 < 7)	tmp2 = Relay_RowConvert(row2);
	else	tmp2 = 0;
	
	byte[0] = tmp1 << 2 | tmp2 >> 4;
	
	
	if(row2 < 7)	tmp1 = Relay_RowConvert(row2);
	else	tmp1 = 0;
	
	if(row3 < 8)	tmp2 = Relay_RowConvert(row3);
	else	tmp2 = 0;
	
	byte[1] = tmp1 << 4 | tmp2 >> 3;
	
	if(row3 < 8)	tmp1 = Relay_RowConvert(row3);
	else	tmp1 = 0;
	
	if(row4 < 8)	tmp2 = Relay_RowConvert(row4);
	else	tmp2 = 0;
	
	byte[2] = tmp1 << 5 | tmp2 >> 2;
	
	if(row4 < 8)	tmp1 = Relay_RowConvert(row4);
	else	tmp1 = 0;
	
	if(row5 < 8)	tmp2 = Relay_RowConvert(row5);
	else	tmp2 = 0;
	
	byte[3] = tmp1 << 6 | tmp2 >> 1;
	
	if(row5 < 8)	tmp1 = Relay_RowConvert(row5);
	else	tmp1 = 0;
	
	if(row6 < 8)	tmp2 = Relay_RowConvert(row6);
	else	tmp2 = 0;
	
	byte[4] = tmp1 << 7 | tmp2;	
	
	
	HC595_WriteDataByte(byte[0]);
	HC595_WriteDataByte(byte[1]);
	HC595_WriteDataByte(byte[2]);
	HC595_WriteDataByte(byte[3]);
	HC595_WriteDataByte(byte[4]);
	HC595_OutData();
}


void	Relay_Test(void)
{
	if(i<8)	Relay_Control(i,i,i,i,i,i);
	if(i == 7) i = 0;
	i++;
}


