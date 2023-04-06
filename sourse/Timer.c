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
	static unsigned int i = 0;
	unsigned char i_flag = 0;
	TL0 = 0X18;		//设置定时初始值
	TH0 = 0XFC;		//设置定时初始值
	
	P0 = 0xff;

	HC138_config(4);
	if(temp / 10 >= refer)
	{
	i++;
	if(i >= 1000)
	{
		
		i = 0;
		i_flag = ~i_flag;
		if(i_flag)
			led_config(3,0);
		else
			led_config(3,1);
	}
  }
	else
	led_config(3,0);
	
	HC138_config(0);//可防止led灯暗淡
	
	menu_Scon();
	
	
}


