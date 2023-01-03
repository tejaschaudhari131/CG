#include<iostream>
#include<graphics.h>

using namespace std;

static int TOP=8,LEFT=1,RIGHT=2,BOTTOM=4,x_low,y_low,x_high,y_high;

int getcode(int x,int y)
{
	int code = 0;
	if(x<x_low)
	{
		code |= LEFT;
	}
	else if(x>x_high)
	{
		code |= RIGHT;
	}
	if(y<y_low)
	{
		code |= BOTTOM;
	}
	else if(y>y_high)
	{
		code |= TOP;
	}
	
	return code;	
}

/*void CohenSutherlandAlgorithm(int a1,int b1,int a2,int b2)
{
	line(a1,b1,a2,b2);
	getch();
	int code1 = getcode(a1,b1);
	int code2 = getcode(a2,b2);
	int draw = 0; //0->Line will not be drawn || 0->Line will be drawn
	while(1)
	{
		float m = (float)(b2-b1)/(a2-a1); //Slope of Line
		int x,y,temp;
		
		if(code1==0 && code2==0)
		{
			draw = 1;
		}
		else if(code1 & code2)
		{
			break;
		}
		else
		{
			if(code1==0)
			{
				temp = code2;
			}
			else
			{
				temp = code1;
			}
			if(temp & TOP)
			{
				x = a1 + (y_high-b1)/m;
				y = y_high;
			}
			else if(temp & BOTTOM)
			{
				x = a1 + (y_low-b1)/m;
				y = y_low;
			}
			else if(temp & RIGHT)
			{
				x = x_high;
				y = b1 + (x_high-a1)*m;
			}
			else if(temp & LEFT)
			{
				x = x_low;
				y = b1 + (x_low-a1)*m;
			}
			
		}
		
		if(temp==code1)
		{
			a1 = x;
			b1 = y;
			code1 = getcode(a1,b1);
		}
		else
		{
			a2 = x;
			b2 = y;
			code2 = getcode(a2,b2);
		}
	}
	cout<<"After Clipping";
	if(draw==1)
	{
		line(a1,b1,a2,b2);	
	}
}*/

int main()
{
	cout<<"Enter the co-ordinates of block:";
	cin>>x_low>>y_low>>x_high>>y_high;
	int a1,b1,a2,b2;
	cout<<"Enter the co-ordinates of line:";
	cin>>a1>>b1>>a2>>b2;
	/*int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	rectangle(x_low,y_low,x_high,y_high);
	//CohenSutherlandAlgorithm(x1,y1,x2,y2);
	line(a1,b1,a2,b2);
	getch();*/
	int code1 = getcode(a1,b1);
	int code2 = getcode(a2,b2);
	int draw = 0; //0->Line will not be drawn || 0->Line will be drawn
	while(1)
	{
		//cout<<"Loop";
		float m = (float)(b2-b1)/(a2-a1); //Slope of Line
		
		if(code1==0 && code2==0)
		{
			draw = 1;
			break;
		}
		else if(code1==1 && code2==1)
		{
			break;
		}
		else
		{
			int x,y,temp;
			if(code1==0)
			{
				temp = code2;
			}
			else
			{
				temp = code1;
			}
			if(temp & TOP)
			{
				x = a1 + (y_high-b1)/m;
				y = y_high;
			}
			else if(temp & BOTTOM)
			{
				x = a1 + (y_low-b1)/m;
				y = y_low;
			}
			else if(temp & RIGHT)
			{
				x = x_high;
				y = b1 + (x_high-a1)*m;
			}
			else if(temp & LEFT)
			{
				x = x_low;
				y = b1 + (x_low-a1)*m;
			}
		
			if(temp==code1)
			{
				a1 = x;
				b1 = y;
				code1 = getcode(a1,b1);
			}
			else
			{
				a2 = x;
				b2 = y;
				code2 = getcode(a2,b2);
		}	
		}
		
	}
	cout<<"After Clipping";
	if(draw==1)
	{
		int gd=DETECT,gm;
		initgraph(&gd,&gm,NULL);
		rectangle(x_low,y_low,x_high,y_high);
		line(a1,b1,a2,b2);
		getch();/**/
		//line(a1,b1,a2,b2);	
	}
	return 0;
}








/*

TOP BOTTOM RIGHT LEFT


          |          |          
          |          |          
  1001    |   1000   |  1010    
          |          |          
__________|__________|__________
          |          |          
          |          |          
  0001    |   0000   |  0010    
          |          |          
__________|__________|__________
          |          |          
  0101    |   0100   |  0110    
          |          |          
          |          |          
          |          |


|= -> Logical OR

0 |= 1 -> 0 = 0 + 1 -> 1

*/
