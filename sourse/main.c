#include "head.h"



void main()
{
	write_ds1302();
	
	EA = 0;
	Timer0Init();
	EA = 1;
	
	dat_output(10); 
	
	while(1)
	{
		ds18b20_config();
		read_ds1302();
		adc_switch();
		refer_key();
		menu_key();
	}

}





