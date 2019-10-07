#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
void main()
{
int gd=DETECT,gm,x=300,j=0,r,t=0,q=640,tr=0,tr1=1;
initgraph(&gd,&gm,"C:\\TC\\BGI");
cleardevice();

for(;q>0;q--)
{
if(q==1)
q=640;
if(tr1==0)
tr++;
rectangle(30,x,50,x+20);
line(0,320,640,320);
if(x<=280&&tr>100)
{
x=x+20;
tr1=1;
tr=0;
}
if(kbhit())
{
r=getch();
if(r==72&&x<=320)
{
x=x-20;
tr1=0;
}
}
rectangle(q,305,q+10,320);
if(q>=20&&q<=50)
if(x+20>305)
break;
delay (5);
cleardevice();

}

getch();

}