
#include "74HC595.h"
#include "stm32f2xx_hal.h"

void	HC595_Init(void)
{
	 GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
	/*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(HC595_OE_GPIO_Port, HC595_OE_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, HC595_RCLK_Pin|HC595_SCLK_Pin|HC595_DATA_Pin, GPIO_PIN_RESET);
	
	  /*Configure GPIO pins : PEPin PEPin */
  GPIO_InitStruct.Pin = HC595_OE_Pin|HC595_RCLK_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : PEPin PEPin */
  GPIO_InitStruct.Pin = HC595_SCLK_Pin|HC595_DATA_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);
}


void HC595_WriteDataBit(uint8_t number)
{
	 if(number)	HAL_GPIO_WritePin(HC595_OE_GPIO_Port, HC595_DATA_Pin, GPIO_PIN_SET);
	 else				HAL_GPIO_WritePin(HC595_OE_GPIO_Port, HC595_DATA_Pin, GPIO_PIN_RESET);
	 HAL_GPIO_WritePin(HC595_OE_GPIO_Port, HC595_SCLK_Pin, GPIO_PIN_SET);
	 HAL_GPIO_WritePin(HC595_OE_GPIO_Port, HC595_SCLK_Pin, GPIO_PIN_RESET);
}

void HC595_WriteDataByte(uint8_t number)
{
	uint8_t j = 0x01;
	uint8_t	len = 8;
	for(; len > 0; len--) 
	{
		HC595_WriteDataBit(number & j);
		j <<= 1;
	}
}

void HC595_WriteDataCustom(uint8_t len,uint8_t number)
{
	uint8_t j = 0x01;
	for(; len > 0; len--) 
	{
		HC595_WriteDataBit(number & j);
		j <<= 1;
	}
}

void	HC595_OutData(void)
{
	HAL_GPIO_WritePin(HC595_OE_GPIO_Port, HC595_RCLK_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(HC595_OE_GPIO_Port, HC595_RCLK_Pin, GPIO_PIN_RESET);
}

void	HC595_Enable(void)
{
	HAL_GPIO_WritePin(HC595_OE_GPIO_Port, HC595_OE_Pin, GPIO_PIN_RESET);
}

void	HC595_Disable(void)
{
	HAL_GPIO_WritePin(HC595_OE_GPIO_Port, HC595_RCLK_Pin, GPIO_PIN_SET);
}