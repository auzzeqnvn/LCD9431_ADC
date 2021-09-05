#include "stdint.h"

#define HC595_OE_Pin GPIO_PIN_2
#define HC595_OE_GPIO_Port GPIOE
#define HC595_RCLK_Pin GPIO_PIN_3
#define HC595_RCLK_GPIO_Port GPIOE
#define HC595_SCLK_Pin GPIO_PIN_4
#define HC595_SCLK_GPIO_Port GPIOE
#define HC595_DATA_Pin GPIO_PIN_5
#define HC595_DATA_GPIO_Port GPIOE


void	HC595_Init(void);
void 	HC595_WriteDataByte(uint8_t number);
void HC595_WriteDataCustom(uint8_t len,uint8_t number);
void	HC595_OutData(void);
void	HC595_Enable(void);
void	HC595_Disable(void);
