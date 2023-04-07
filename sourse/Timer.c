#include "head.h"

unsigned char busy;


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



//void UartInit()		//9600bps@12.000MHz
//{
//	SCON = 0x50;		//8位数据,可变波特率
//	AUXR |= 0x40;		//定时器时钟1T模式
//	AUXR &= 0xFE;		//串口1选择定时器1为波特率发生器
//	TMOD &= 0x0F;		//设置定时器模式
//	TL1 = 0xC7;		//设置定时初始值
//	TH1 = 0xFE;		//设置定时初始值
//	ET1 = 0;		//禁止定时器%d中断
//	TR1 = 1;		//定时器1开始计时
//	
//	ES = 1;
//}




//void Uart() interrupt 4
//{
//	while(!RI);
//	dat = SBUF;
//	P2 = dat;
//	
//}






//void Sendbyte(unsigned char dat)
//{
//  SBUF = dat;                 //写数据到UART数据寄存器
//	while(!TI);
//	Ti = 0;
//}


















void ServiceTimer0() interrupt 1
{
	static unsigned int i = 0;
	static unsigned int i_flag = 0;
	TL0 = 0X18;		//设置定时初始值
	TH0 = 0XFC;		//设置定时初始值
	
	P0 = 0xff;

	HC138_config(4);
	if(temp / 10 >= refer)
	{
	i++;
	if(i >= 100)
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


