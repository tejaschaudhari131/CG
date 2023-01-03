#include<iostream>
#include<graphics.h>
#include<cstdlib>
using namespace std;
int main()
{
int gd=DETECT, gm;
initgraph(&gd,&gm,NULL);
int i,x,y,flag=0;
x=getmaxx()/2;
y=getmaxy()/2;
while(1)
{
setcolor(WHITE);
line(0,300,160,150);
line(160,150,320,310);
line(320,310,480,150);
line(480,150,640,310);
line(0,310,640,310);
if(y>=getmaxy()-y||y<=getmaxy()/4)
{
flag=!flag;
}
setcolor(RED);
circle(x,y,40);
floodfill(x,y,WHITE);
delay(50);
if(flag)
{
y=y+2;
}
else
{
y=y-2;
}
cleardevice();
}
delay(5000);
getch();
closegraph();
return 0;
}
