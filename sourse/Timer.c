#include "head.h"

unsigned char busy;


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



//void UartInit()		//9600bps@12.000MHz
//{
//	SCON = 0x50;		//8λ����,�ɱ䲨����
//	AUXR |= 0x40;		//��ʱ��ʱ��1Tģʽ
//	AUXR &= 0xFE;		//����1ѡ��ʱ��1Ϊ�����ʷ�����
//	TMOD &= 0x0F;		//���ö�ʱ��ģʽ
//	TL1 = 0xC7;		//���ö�ʱ��ʼֵ
//	TH1 = 0xFE;		//���ö�ʱ��ʼֵ
//	ET1 = 0;		//��ֹ��ʱ��%d�ж�
//	TR1 = 1;		//��ʱ��1��ʼ��ʱ
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
//  SBUF = dat;                 //д���ݵ�UART���ݼĴ���
//	while(!TI);
//	Ti = 0;
//}


















void ServiceTimer0() interrupt 1
{
	static unsigned int i = 0;
	static unsigned int i_flag = 0;
	TL0 = 0X18;		//���ö�ʱ��ʼֵ
	TH0 = 0XFC;		//���ö�ʱ��ʼֵ
	
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
	
	HC138_config(0);//�ɷ�ֹled�ư���

	
	menu_Scon();
	
	
}


