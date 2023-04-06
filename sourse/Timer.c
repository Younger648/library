#include "head.h"




void Timer0Init()		//1毫秒@11.0592MHz
{
	
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	
	TL0 = 0x18;		//设置定时初始值
	TH0 = 0xfc;		//设置定时初始值
	
	TF0 = 0;

	TR0 = 1;
	ET0 = 1;
}


void ServiceTimer0() interrupt 1
{
	TL0 = 0X18;		//设置定时初始值
	TH0 = 0XFC;		//设置定时初始值
	
	P0 = 0xff;
	
	HC138_config(4);
	led_config(1,1);
	HC138_config(0);
	
	menu_Scon();
	
	
}


