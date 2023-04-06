#include "head.h"




void Timer0Init()		//1����@11.0592MHz
{
	
	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TMOD |= 0x01;		//���ö�ʱ��ģʽ
	
	TL0 = 0x18;		//���ö�ʱ��ʼֵ
	TH0 = 0xfc;		//���ö�ʱ��ʼֵ
	
	TF0 = 0;

	TR0 = 1;
	ET0 = 1;
}


void ServiceTimer0() interrupt 1
{
	TL0 = 0X18;		//���ö�ʱ��ʼֵ
	TH0 = 0XFC;		//���ö�ʱ��ʼֵ
	
	P0 = 0xff;
	
	HC138_config(4);
	led_config(1,1);
	HC138_config(0);
	
	menu_Scon();
	
	
}


