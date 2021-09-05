#include "draw.h"
#include "TFT_GLCD.h"
#include "common.h"

char	buff1[40] = {'\n'};
char	buff2[40] = {'\n'};
char	buff3[40] = {'\n'};
char	buff4[40] = {'\n'};
char	buff5[40] = {'\n'};
char	buff6[40] = {'\n'};
int len_buff;

int text1_x,text1_y,text2_x,text2_y,text3_x,text3_y,text4_x,text4_y,text5_x,text5_y,text6_x,text6_y;

int bubble_x,bubble_y,bubble_x1,bubble_x2,bubble_y2,bubble_x3,bubble_y3;

int button1_x,button1_y;
int button2_x,button2_y;
int button3_x,button3_y;
int button4_x,button4_y;
int button5_x,button5_y;
int button6_x,button6_y;
int button7_x,button7_y;
int button8_x,button8_y;
uint8_t	button_r = 12;

void 	DrawLCD_DemoSymbol(void)
{
	/* ve cac bieu tuong */
	lcd_set_colorRGB(255,0,0);
	lcd_draw_enter_fill(260,40,30);
	lcd_set_colorRGB(255,0,0);
	lcd_draw_triangle_fill(175,120,50,70,180);
	
	lcd_draw_triangle_fill(55,120,50,70,0);	
	
	lcd_set_colorRGB(0,255,0);
	lcd_draw_triangle_fill(115,180,40,30,270);
	
	lcd_set_colorRGB(0,0,255);
	lcd_draw_triangle_fill(115,60,90,50,90);
	
	lcd_set_colorRGB(255,0,0);
	lcd_draw_power_fill(115,120,30,VGA_WHITE);
	lcd_set_colorRGB(0,0,255);
	lcd_draw_exit_fill(250,120,30,VGA_RED);
	
	lcd_set_colorRGB(0,0,255);
	lcd_draw_return_fill(250,180,30,VGA_RED);
}

void	DrawLCD_Bubble_area(void)
{
	lcd_draw_square_outline(130,30,140,140,VGA_NAVY);
	lcd_draw_square_outline(129,29,142,142,VGA_NAVY);
	lcd_draw_square_outline(128,28,144,144,VGA_NAVY);
	lcd_draw_square_outline(127,27,146,146,VGA_NAVY);
}

void	DrawLCD_ADC_board(void)
{
	/* Toa do text */
	text1_x = 30;
	text1_y	= 80;
	
	text2_x = text1_x;
	text2_y = text1_y+15; //Moi ki tu co chieu cao 8 px + 7px khoang cach giua 2 dong
	
	text3_x = text2_x;
	text3_y = text2_y+15;
	
	text4_x = text3_x;
	text4_y = text3_y+15;
	
	text5_x = text4_x;
	text5_y = text4_y+15;
	
	text6_x = text5_x;
	text6_y = text5_y+15;
	
	/* Ke khung */
	lcd_set_colorRGB(240,0,0);
	lcd_draw_square_outline(text1_x-5,text1_y-5,95,95,VGA_NAVY);
	lcd_draw_Hline(text1_x-5,text1_y+10,95);
	lcd_draw_Hline(text2_x-5,text2_y+10,95);
	lcd_draw_Hline(text3_x-5,text3_y+10,95);
	lcd_draw_Hline(text4_x-5,text4_y+10,95);
	lcd_draw_Hline(text5_x-5,text5_y+10,95);
	
	/* In cac chu co vi tri co dinh */
	lcd_set_colorRGB(0,0,0);
	sprintf(buff1,"ADC1: ");			
	lcd_print_text(buff1,text1_x,text1_y,0);
	sprintf(buff2,"ADC2: ");			
	lcd_print_text(buff2,text2_x,text2_y,0);
	sprintf(buff3,"ADC3: ");			
	lcd_print_text(buff3,text3_x,text3_y,0);
	sprintf(buff4,"ADC4: ");			
	lcd_print_text(buff4,text4_x,text4_y,0);
	sprintf(buff5,"ADC5: ");			
	lcd_print_text(buff5,text5_x,text5_y,0);
	sprintf(buff6,"ADC6: ");			
	lcd_print_text(buff6,text6_x,text6_y,0);
	
	/* Set toa do X cho cac ki tu thay doi noi dung */
	text1_x = 78;
	text2_x = text1_x;
	text3_x = text2_x;
	text4_x = text3_x;
	text5_x = text4_x;
	text6_x = text5_x;
}
void	UpdateLCD_ADC_value(void)
{
	lcd_set_colorRGB(255,255,255);
	lcd_print_text(buff1,text1_x,text1_y,0); //print chu cung mau background de xoa chu			
	lcd_set_colorRGB(0,0,0);
	sprintf(buff1,"%d",ADC_RES[0]);			
	lcd_print_text(buff1,text1_x,text1_y,0);
	
	lcd_set_colorRGB(255,255,255);
	lcd_print_text(buff2,text2_x,text2_y,0);
	lcd_set_colorRGB(0,0,0);
	sprintf(buff2,"%d",ADC_RES[1]);			
	lcd_print_text(buff2,text2_x,text2_y,0);
	
	lcd_set_colorRGB(255,255,255);
	lcd_print_text(buff3,text3_x,text3_y,0);
	lcd_set_colorRGB(0,0,0);
	sprintf(buff3,"%d",ADC_RES[2]);			
	lcd_print_text(buff3,text3_x,text3_y,0);
	
	lcd_set_colorRGB(255,255,255);
	lcd_print_text(buff4,text4_x,text4_y,0);
	lcd_set_colorRGB(0,0,0);
	sprintf(buff4,"%d",ADC_RES[3]);			
	lcd_print_text(buff4,text4_x,text4_y,0);
	
	lcd_set_colorRGB(255,255,255);
	lcd_print_text(buff5,text5_x,text5_y,0);
	lcd_set_colorRGB(0,0,0);
	sprintf(buff5,"%d",ADC_RES[4]);			
	lcd_print_text(buff5,text5_x,text5_y,0);
	
	lcd_set_colorRGB(255,255,255);
	lcd_print_text(buff6,text6_x,text6_y,0);
	lcd_set_colorRGB(0,0,0);
	sprintf(buff6,"%d",ADC_RES[5]);			
	lcd_print_text(buff6,text6_x,text6_y,0);
}
void	UpdateLCD_Bubbles(void)
{
	lcd_set_colorRGB(255,255,255);
	lcd_draw_circle_fill(bubble_x,bubble_y,10);
	lcd_draw_circle_fill(bubble_x2,bubble_y2,10);
	lcd_draw_circle_fill(bubble_x3,bubble_y3,10);
	
	bubble_x= rand()%119+141;
	bubble_y= rand()%119+41;			
	lcd_set_colorRGB(255,0,0);
	lcd_draw_circle_fill(bubble_x,bubble_y,10);
	
	bubble_x2= rand()%119+141;
	bubble_y2= rand()%119+41;
	lcd_set_colorRGB(0,255,255);
	lcd_draw_circle_fill(bubble_x2,bubble_y2,10);
	
	bubble_x3= rand()%119+141;
	bubble_y3= rand()%119+41;
	lcd_set_colorRGB(200,100,128);
	lcd_draw_circle_fill(bubble_x3,bubble_y3,10);
}

void	DrawLCD_Button(void)
{
	uint16_t text1_x,text1_y;
	uint16_t text2_x,text2_y;
	uint16_t text3_x,text3_y;
	uint16_t text4_x,text4_y;
	uint16_t text5_x,text5_y;
	uint16_t text6_x,text6_y;
	uint16_t text7_x,text7_y;
	uint16_t text8_x,text8_y;
	
	text1_x = 10;
	text2_x = 50;
	text3_x = 90;
	text4_x = 130;
	text5_x = 170;
	text6_x = 210;
	text7_x = 250;
	text8_x = 290;	
	
	text1_y = text2_y = text3_y = text4_y = text5_y = text6_y = text7_y = text8_y = 220;
	
	
	lcd_set_colorRGB(0,0,0);	
	lcd_print_text("Nut1",text1_x,text1_y,0);
	lcd_print_text("Nut2",text2_x,text2_y,0);
	lcd_print_text("Nut3",text3_x,text3_y,0);
	lcd_print_text("Nut4",text4_x,text4_y,0);
	lcd_print_text("Nut5",text5_x,text5_y,0);
	lcd_print_text("Nut6",text6_x,text6_y,0);
	lcd_print_text("Nut7",text7_x,text7_y,0);
	lcd_print_text("Nut8",text8_x,text8_y,0);
	
	button1_x = text1_x + button_r + (32 - 2*button_r)/2;
	button2_x = text2_x + button_r + (32 - 2*button_r)/2;
	button3_x = text3_x + button_r + (32 - 2*button_r)/2;;
	button4_x = text4_x + button_r + (32 - 2*button_r)/2;;
	button5_x = text5_x + button_r + (32 - 2*button_r)/2;;
	button6_x = text6_x + button_r + (32 - 2*button_r)/2;
	button7_x = text7_x + button_r + (32 - 2*button_r)/2;;
	button8_x = text8_x + button_r + (32 - 2*button_r)/2;;
	
	button1_y = button2_y = button3_y = button4_y = button5_y = button6_y = button7_y = button8_y = 200;
	
	lcd_set_colorRGB(0,0,0);	
	lcd_draw_circle_fill(button1_x,button1_y,button_r);
	lcd_draw_circle_fill(button2_x,button2_y,button_r);
	lcd_draw_circle_fill(button3_x,button3_y,button_r);
	lcd_draw_circle_fill(button4_x,button4_y,button_r);
	lcd_draw_circle_fill(button5_x,button5_y,button_r);
	lcd_draw_circle_fill(button6_x,button6_y,button_r);
	lcd_draw_circle_fill(button7_x,button7_y,button_r);
	lcd_draw_circle_fill(button8_x,button8_y,button_r);
}

void	UpdateLCD_Button(void)
{
	if(Button_1 != Button_1_last)	
	{
		Button_1_last = Button_1;
		if(Button_1)	lcd_set_colorRGB(255,0,0);	
		else	lcd_set_colorRGB(0,0,0);	
		lcd_draw_circle_fill(button1_x,button1_y,button_r);	
	}
	
	if(Button_2 != Button_2_last)	
	{
		Button_2_last = Button_2;
		if(Button_2)	lcd_set_colorRGB(255,0,0);	
		else	lcd_set_colorRGB(0,0,0);	
		lcd_draw_circle_fill(button2_x,button2_y,button_r);	
	}
	if(Button_3 != Button_3_last)	
	{
		Button_3_last = Button_3;
		if(Button_3)	lcd_set_colorRGB(255,0,0);	
		else	lcd_set_colorRGB(0,0,0);	
		lcd_draw_circle_fill(button3_x,button3_y,button_r);	
	}
	if(Button_4 != Button_4_last)	
	{
		Button_4_last = Button_4;
		if(Button_4)	lcd_set_colorRGB(255,0,0);	
		else	lcd_set_colorRGB(0,0,0);	
		lcd_draw_circle_fill(button4_x,button4_y,button_r);	
	}
	if(Button_5 != Button_5_last)	
	{
		Button_5_last = Button_5;
		if(Button_5)	lcd_set_colorRGB(255,0,0);	
		else	lcd_set_colorRGB(0,0,0);	
		lcd_draw_circle_fill(button5_x,button5_y,button_r);	
	}
	if(Button_6 != Button_6_last)	
	{
		Button_6_last = Button_6;
		if(Button_6)	lcd_set_colorRGB(255,0,0);	
		else	lcd_set_colorRGB(0,0,0);	
		lcd_draw_circle_fill(button6_x,button6_y,button_r);	
	}
	if(Button_7 != Button_7_last)	
	{
		Button_7_last = Button_7;
		if(Button_7)	lcd_set_colorRGB(255,0,0);	
		else	lcd_set_colorRGB(0,0,0);	
		lcd_draw_circle_fill(button7_x,button7_y,button_r);	
	}
	if(Button_8 != Button_8_last)	
	{
		Button_8_last = Button_8;
		if(Button_8)	lcd_set_colorRGB(255,0,0);	
		else	lcd_set_colorRGB(0,0,0);	
		lcd_draw_circle_fill(button8_x,button8_y,button_r);	
	}
}

