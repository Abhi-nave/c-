#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fstream.h>


char ch[80],ch1[80],ch2[80],ch3[80];
int red=3,e=0,w=0,w2=0;
int er=0,tr[27]={33,34,37,38,39,40,41,42,44,43,45,46,47,48,49,50,51,52,53,54,55,56,57,60,61,62,63};
int track=0,star=67,start=0,t=0,fr=92,t1=1;

	 ofstream rfile("ABH.cpp",ios::out);
	 ifstream ffile(ch2,ios::in);
void rw()
{
for(int e3=0;e3<=80;e3++)
 ch[e3]=0;
 w=0;
 for(int r4=1;r4!=0;w++)
 {
   if(t1==0)
 {
 ch[w]=ch1[0];
 t1=1;
 break;
 }
   ffile.get(ch[w]);
   for(e3=0;e3<27;e3++)
   {
    if(ch[w]==tr[e3])
    { ch1[0]=ch[w];
      ch[w]=' ';
      r4=0;
      t1=0;
      break;
    }
    else if(ch[w]==32||ch[w]==10)
    {
       ch[w]=' ';
      r4=0;
      break;
    }
   }

 }
}

void se()
{
       if(strcmp(ch,"'")==0||(int)ch==42)
       {
	    rfile<<'"';
	    if(t==0)
	    {
	       rw();
	       t=1;
	    }


	while(strcmp(ch,"'")!=0||(int)ch!=42)
	{
	     rfile<<ch<<" ";
	   rw();

	}

	   rfile<<'"';
	   rw();
	}

}

void trwe()            //comparing character with num or special char
{
     if(int(ch[0])>=65&&int(ch[0])<=90)
     {
     rfile<<ch<<" ";
     rw();
     }
}
void converter()      //definition of func. Converter
{                     //this func convert the algo to program


rfile<<"#include<iostream.h>"<<endl<<"#include<conio.h>"<<endl;
rfile<<"void main(){"<<endl<<"clrscr();"<<endl;
rw();
cout<<ch;
while(!ffile.eof())
{

     if(fr==0)
     if(strcmp(ch,"step")==0)
     {
	    rw();
	    if(ch[0]>track)
	    {
	     rfile<<"}"<<endl;
	     fr=9;
	    }
	     rw();
	     rw();
     }

     if(strcmp(ch,"step")==0)
     {
     rw();
     rw();
     rw();
     cout<<"a" ;
     }

     else if((strcmp(ch,"print")==0)||(strcmp(ch,"write")==0))
     {
	   cout<<"a";
	   rfile<<"\ncout<<";
x :
	   rw();
	   trwe();
	   se();
	   if(strcmp(ch,".")==0)
	   {
	      rfile<<';'<<endl;
	      rw();
	   }

	   else if((strcmp(ch,",")==0)||(strcmp(ch,"and")==0))
	   {
		 rfile<<"<<";
		 goto x;
	   }

      }


      else if(strcmp(ch,".")==0)
      { cout<<"a";
	rfile<<';'<<endl;
	rw();
      }
     else if(strcmp(ch,"read")==0)
     {   cout<<"a";
	 rfile<<"cin>>";
     e :
	 rw();
	 trwe();
	 if(strcmp(ch,".")==0)
	 {
	  rfile<<';'<<endl;
	  rw();
	 }

	 if((strcmp(ch,",")==0)||(strcmp(ch,"and")==0))
	 {
	  rfile<<">>";
	  goto e;
	 }
     }

      else if(strcmp(ch,"repeat")==0)
       {    cout<<"a";
	    rfile<<"while(";
	    while(!ffile.eof())
	    {
		rw();
		if(strcmp(ch,"to")==0)
		{
			rw();
			if(strcmp(ch,"step")==0)
			{
			  rw();
			  track=ch[0];
			  fr=0;
			  break;
			}
			else
			{
			  track=ch[0];
			  fr=0;
			  break;
			}
		}
	     }
	     rw();
	     if(strcmp(ch,"while")==0||strcmp(ch,"till")==0)
	     {
		rw();
		 while(strcmp(ch,".")!=0)
		 {
			rfile<<ch<<' ';
			rw();
		 }
		 rfile<<")"<<endl<<"{";
		 rw();
	    }
	}


     else if(strcmp(ch,"if")==0)
	 {     cout<<"A";
	      rfile<<"\nif(";
	      rw();
	      for(;strcmp(ch,"then")!=0;)
	      {
		  if(strcmp(ch,"and")==0||strcmp(ch,"&")==0)
		    {
		     rfile<<" && ";
		     rw();
		     }
		    else if(strcmp(ch,"or")==0)
		    {
		     rfile<<" || ";
		     rw();
		     }
		  else
		  {
		  rfile<<ch<<" ";
		  rw();
		  }
	      }
	      rfile<<")"<<endl;
	       rw();
	 }

    else if(ch[0]==32||ch[0]==13)
     {
     rw();
     cout<<ch<<"1";
     }
    else if(strcmp(ch,"else")==0)
	  {
	    rfile<<"else"<<endl;
	      rw();
	      }
       else if((strcmp(ch,"{")==0)||(strcmp(ch,"}")==0))
	    {
	     rfile<<ch<<endl;
	       rw();
	    }
	 else if((strcmp(ch,"int")==0)||(strcmp(ch,"char")==0)||(strcmp(ch,"float")==0))
	   {
	       rfile<<ch<<" ";
	       d: rw();
	       trwe();
		if(strcmp(ch,",")==0 || strcmp(ch,"and")==0)
	    {
	    rfile<<',';
	    cout<<ch<<" ";
	    goto d;
	    }
	       for(int i=0;i<21;i++)
	       {
		 if(int(ch[0])==tr[i])
		 {
		    rfile<<ch<<' ';
		    rw();
		 }
	       }



	    }


    else  if(strcmp(ch,"size")==0)
	{
	    rfile<<"[";
	    rw();
	    rfile<<ch<<"]";
	}

       else if(int(ch[0])>=65&&int(ch[0])<=90)
     {
     rfile<<ch<<" ";
     rw();
     }

     else if(star==0)
	{
	    rfile<<" }"<<endl;
	    star=1;
	}

      else	if(strcmp(ch,"stop")==0)
	{
	    cout<<"K";
	   rfile<<"getch();";
	     rfile<<"\n}";
	     break;
	 }
	 else
	    se();

	    for(int i=0;i<21;i++)
	    {

	    if(int(ch[0])==tr[i])
	    {
	    rfile<<ch<<' ';
	    rw();
	    }



	    }
     }
     }

void main()
{
   clrscr();
   int gdrive = DETECT,gmode,qu;

   initgraph(&gdrive,&gmode,"C:\\TURBOC3\\BGI");
   setbkcolor(WHITE);
	setcolor(RED);
	settextstyle(10,0,10);
	outtextxy(280,40,"2");
	settextstyle(10,0,7);
   outtextxy(220,160,"A");
   settextstyle(10,0,7);
   outtextxy(375,160,"P");
   randomize();
	 qu=random(2);
	 if(qu==0)
	 {
	    settextstyle(12,0,3);
	  setcolor(GREEN+BLINK);
	  outtextxy(140,440,"TIP : 'If you are a beginner see help first '");
	}

      else
	{
	    settextstyle(12,0,3);
	    setcolor(GREEN+BLINK);
	    outtextxy(180,440,"This program will soon be updated");
	}

      getch();
	  cleardevice();
	closegraph();
	cout<<"ENTER THE PATH OF THE FILE : ";
	cin>>ch2;
	//converter();
	ffile.close();


	ifstream rfile(ch,ios::in);
	while(!rfile.eof())
	{
	rfile.getline(ch1,80);
	cout<<"\n"<<ch1;
	}
	rfile.close();
	getch();

	}