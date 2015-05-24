//#include "iostream"
//#include "cstdlib"
//#include "stdio.h"
//#include "ctime"

//using namespace std;
	
int main()
{
	volatile int* led = 		(int*)0xFF200040;		//Reded LED address
	volatile int* hex3_0 = 		(int*)0xFF200020;		//HEX3_HEX0 address
	volatile int* hex5_4 = 		(int*)0xFF200010;		//HEX5_HEX4 address
	volatile int* switchptr = 	(int*)0xFF200030;		//SW Slider switch address
	volatile int* pushptr = 	(int*)0xFF200000;		//KEY push button address

	int ctr_width = 50; // horizontal position of center of cross (from circle)
	int ctr_height = 50; // vertical position of center of cross (from circle)
	int w = 1920; // width of entire image
	int h = 1080; // height of entire image
	int w_i = 540;
	int h_i = 360;
	int output = 000;
	int i = 0;
	int switchValue;
	//time_t start_time;
	//time_t now;
	*(led) = 0;

	while (output != 111)
	{			
		if (ctr_width < (w/2 - w_i/2))
		{
			*(led) = 4;
			output = 100; // move left, specify duration?
			while(i < 100000)
			{
				i++;
			}
			i = 0;
			output = 000;
			*(led) = 0;

			ctr_width +=100;
		}
		
		else if (ctr_width > (w/2 + w_i/2))
		{
			output = 101;
			*(led) = 5;
		
			while(i < 100000)
			{
				i++;
			}
			i = 0;

			output = 000;
			*(led) = 0;

			ctr_width -=100;
		}
		
		if (ctr_height > (h/2 + h_i/2))
		{
			*(led) = 3;
			while(i < 100000)
			{
				i++;
			}
			i = 0;
			output = 000;
			*(led) = 0;

			ctr_height -=100;
		}
		
		else if (ctr_height < (h/2 - h_i/2))
		{
			output = 77;
			*(led) = 2;
			while(i < 100000)
			{
				i++;
			}
			i = 0;
		
			output = 000;
			*(led) = 0;

			ctr_height +=100;
		}
		
		/* -----------------------------------------------------

		SW0 = 0
		SW1 = 0
		Less than = 5

		01 = less than = 10
		10 = less than = 15
		11 = greater than 15

		Start with Switches at 11 and then reduce at ease

		-------------------------------------------------------*/
		switchValue = *(switchptr);
		if (switchValue == 3)
		{
			output = 001;
			*(led) = 1;
			while(i < 100000)
			{
				i++;
			}
			i = 0;
		
			output = 000;
			*(led) = 0;
		}
		
		else if (switchValue == 2)
		{
			output = 001;
			*(led) = 1;
		
			while(i < 100000)
			{
				i++;
			}
			i = 0;
		
			output = 000;
			*(led) = 0;
		}

		else if (switchValue == 1)
		{
			output = 001;
			*(led) = 1;
		
			while(i < 100000)
			{
				i++;
			}
			i = 0;
		
			output = 000;
			*(led) = 0;
		}

		else /*switchValue == 0*/
		{
			output = 111;
			*(led) = 7;
		}
		
		while(i < 1000000)
		{
			i++;
		}
		i = 0;
	}
	return (0);
}

