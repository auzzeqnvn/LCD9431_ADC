/**
  ******************************************************************************
  * @file    Lib_DEBUG/RunTime_Check/stm32f10x_ip_dbg.h 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   This file contains the headers of the library peripherals Debug.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */ 

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __TFT_GLCD_H
#define __TFT_GLCD_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f2xx.h"
#define swap(type, i, j) {type t = i; i = j; j = t;}
#define LEFT 0
#define RIGHT 9999
#define CENTER 9998

#define PORTRAIT 0
#define LANDSCAPE 1

#define u8 uint8_t
#define u16 uint16_t
#define u32 uint32_t

#define SIZE	76800
#define SIZE_X 240
#define SIZE_Y 320

#define false 0
#define true 1
	
//CHIP SELECT PIN AND PORT, STANDARD GPIO
#define LCD_CS_PORT								GPIOB
#define LCD_CS_PIN								GPIO_PIN_6

//DATA COMMAND PIN AND PORT, STANDARD GPIO
#define LCD_DATA_PORT								GPIOD

//RESET PIN AND PORT, STANDARD GPIO
#define	LCD_RST_PORT							GPIOB
#define	LCD_RST_PIN								GPIO_PIN_7

//RESET PIN AND PORT, STANDARD GPIO
#define	LCD_RD_PORT							GPIOB
#define	LCD_RD_PIN								GPIO_PIN_5

#define	LCD_WR_PORT							GPIOB
#define	LCD_WR_PIN								GPIO_PIN_4

#define	LCD_RS_PORT							GPIOB
#define	LCD_RS_PIN								GPIO_PIN_3

// VGA color palette
#define VGA_Xanhnhat		0x1F90FF
#define VGA_CAM		0xFFCC00
#define VGA_BLACK		0x0000
#define VGA_WHITE		0xFFFF
#define VGA_RED			0xF800
#define VGA_GREEN		0x0400
#define VGA_BLUE		0x001F
#define VGA_SILVER		0xC618
#define VGA_GRAY		0x8410
#define VGA_MAROON		0x8000//
#define VGA_YELLOW		0xFFE0
#define VGA_OLIVE		0x8400
#define VGA_LIME		0x07E0
#define VGA_AQUA		0x07FF//
#define VGA_TEAL		0x0410//
#define VGA_NAVY		0x0010
#define VGA_FUCHSIA		0xF81F
#define VGA_PURPLE		0x8010
#define VGA_TRANSPARENT	0xFFFFFFFF
#define VGA_XANHNHE		0x0010//0x336699
#define VGA_XANHLA		0x07E0

#define LCD_W 320//240
#define LCD_H 240//320


extern uint8_t TinyFont[764];
extern uint8_t Arial_round_16x24[];
extern uint8_t Retro8x16[];
extern uint8_t	font85[] ;

typedef struct 
{
	unsigned char* font;
	unsigned char x_size;
	unsigned char y_size;
	unsigned char offset;
	unsigned char numchars;
}current_font;


extern current_font cfont;


void LCD_Reset(void);
void	LCD_GPIO_Init(void);
void delay(int ticks);

void lcd_draw_square_outline(int x1,int y1,int dai,int rong,uint32_t color);
void lcd_draw_square_curve_outline(int x1,int y1,int dai,int rong,uint32_t color);
void lcd_draw_square_curve_fill(int x1,int y1,int dai,int rong);
void lcd_draw_square_fill(int x1,int y1,int dai,int rong);
void lcd_circle_outline1(int16_t x0, int16_t y0, int16_t r,uint16_t color);
void LCD_Writ_Bus(char VH,char VL);
void LCD_Write_COM(int da);
void LCD_Write_DATA(char VH,char VL);
void LCD_Write_COM_DATA(char com1,int dat1);
void Lcd_Init(void);
void setXY(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2);
void lcd_screen_fill(void);
void lcd_draw_enter_outline(int x,int y,int size);
void lcd_draw_enter_fill(int x,int y,int size);
void lcd_draw_triangle_fill(int x,int y,int size_x,int size_y,int deg);
void lcd_draw_exit_fill(int x,int y,int size,uint32_t color_inside);
void lcd_draw_return_fill(int x,int y,int size_r,uint32_t color_inside);
void lcd_draw_circle_outline(int x, int y, int radius);
void lcd_draw_circle_fill(int x, int y, int radius);
void lcd_draw_power_fill(int x,int y,int size_r,uint32_t color_inside);
void lcd_set_colorRGB(uint8_t r, uint8_t g, uint8_t b);
void lcd_set_color16bit(uint32_t color);

void lcd_set_pixel(uint32_t color);
void lcd_draw_pixel(int x, int y);
void lcd_draw_line(int x1, int y1, int x2, int y2);
void lcd_draw_Hline(int x, int y, int l);
void lcd_draw_Vline(int x, int y, int l);
void printChar(u8 c, int x, int y);
void rotateChar(u8 c, int x, int y, int pos, int deg);
void lcd_print_text(char *st, int x, int y, int deg);
void setFont(uint8_t* font);

void LCD_WR_DATA(int da);
void LCD_Clear(u16 Color);
void delay_lcd(uint16_t t);		

		
					 
#endif /* __STM32F10X_IP_DBG_H */

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
