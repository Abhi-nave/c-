#include<iostream.h>
#include<conio.h>
#include<process.h>
void main()
{
int n,a[100],g,c=1;
clrscr();
cin>>n;
for(int i = 1;i<=n;i++)
{
 a[i]=i ;
 cout<<a[i]<<" " ;
}
g=n;
x:
 n=g;
cout<<"\n";
if(g==3&&c==0)
{
cout<<a[2];
getch();
exit(0);
}
else
{
if(g%2==0)
g=g/2;
else
g=g/2+1;
}
if(c==0)
{
for(i=1;i<=g;i++)
{
a[i]=a[i+i];
cout<<a[i]<<" ";
}
if(c==0&&a[g]!=a[n])
g=g-1;

c=1;
}
else
{
for(i=1;i<=g;i++)
{

a[i]=a[i+i-1];
cout<<a[i]<<" ";
}
}
if(a[g]==a[n])
{
c=0;
}
if(g!=1)
goto x;
getch();
}
