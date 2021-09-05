
#ifndef __SYS_TFT_H
#define __SYS_TFT_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f2xx.h"

#define LCD_HOME 0

#define LCD_OUT  30

#define adress_pic_home 0x000000////50x50
#define length_pic_home 76800

void LCD_show_Acc(void);
void LCD_show_change_dongho_banhlai_vong2(char huong_quay);
void LCD_show_change_dongho_volang_vong2(char huong_quay);
void LCD_show_change_dongho_banhlai(char huong_quay);
void show_para_xe(void);
void LCD_show_dongho_volang(uint16_t sogoc,char huong);
void LCD_show_dongho_banhlai(uint16_t sogoc,char huong);
void LCD_show_dongho_saiso(uint16_t sogoc);
void LCD_show_change_dongho_volang(char huong_quay);
void show_caidat(char index);
void LCD_show_num_pulse_volang(uint16_t soxung);
void LCD_show_num_pulse_banhlai(uint16_t sovong);
void show_para_banhlai(void);
void esare_value(uint16_t length_value,uint8_t R,uint8_t G,uint8_t B,uint16_t x,uint16_t y);
void show_para_volang(void);
void LCD_show_vantoc(uint16_t vantoc);
void LCD_show_km(uint32_t km);
void LCD_show_toggle_time_rtc(void);
void timer_1s_tft(void);
void LCD_show_sovong_volang(char sovong);
void LCD_show_time_rtc(void);
void LCD_show_goc_volang(uint16_t xung);
void LCD_show_huong_volang(char huong);
void LCD_show_goc_banh(uint16_t xung);
void LCD_show_huong_banh(char huong);
void sys_tft(void);
void read_datapic_w25Q64(uint32_t addes,int x, int y, int sx, int sy);
void LCD_Show_Home(void);
void LCD_Clear(uint16_t Color);
#endif /* __STM32F10X_IP_DBG_H */

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
