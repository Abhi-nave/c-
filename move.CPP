#include<process.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

void main()
{
int gd=DETECT,gm,v,y=0,i=0,w=1,r=0,r2=0,c=0,y2=0,i2=0;
initgraph(&gd,&gm,"C:\\TC\\BGI");
setbkcolor(BLUE);
for(;i>-1&&y>-1&&i<622&&y<462;)
{

if(kbhit())
{

v=getch();
if(v==27)
exit(0);
else if(v==72)
y=y-10;
else if(v==75)
i=i-10;
else if(v==80)
y=y+10;
else if(v==77)
i=i+10;
}


setcolor(WHITE);
rectangle(i,y,10+i,10+y);


delay(200);
cleardevice();

}
getch();
closegraph();

}