#include<iostream.h>
 #include<conio.h>
  #include<graphics.h>
   #include<dos.h>
    #include<stdlib.h>
     #include<ctype.h>

char sc[5];
int inpt;

void wall(int x,int r)  // function for the wall
{
	setfillstyle(1,RED);
	bar(x+10,0,x+30,r);
	    setfillstyle(1,CYAN);
	    bar(x+30,0,x+50,r);


	setfillstyle(1,RED);
	bar(x+10,r+100,x+30,480);
	    setfillstyle(1,CYAN);
	    bar(x+30,r+100,x+50,480);
}

void main()
{
     int gdriver = DETECT ,gmode;
     initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
	 int rad;
	 setbkcolor(BLUE);

/*for(rad=400;rad>0;rad--)       // loop for the pattern at main page
  {
      setfillstyle(1,RED);
      pieslice(0,0,0,360,rad);
	  setfillstyle(1,RED);
	  pieslice(640,480,0,360,rad);

  }*/

setcolor(BLUE);
  settextstyle(1, 0, 10);
   outtextxy(50, 20, "FLY ");
     settextstyle(1, 0, 10);
      outtextxy(330, 300, "HIGH ");
       settextstyle(1, 0, 4);
	outtextxy(100, 200, "press any key to continue ");
	  getch();
	    cleardevice();



  setbkcolor(CYAN);
  int level = 1;

  y:      cleardevice();
	   char o,e;

int x=600,y=x-250,z=y-250,r=200,b=200,c=200,f=4;
 setbkcolor(CYAN);
  int a=170,score=40,score_main=0;
  /* if(level==1)
    {
       settextstyle(1, 0, 9);
	  outtextxy(50, 0, "INSTRUCTION ");
	    delay(2000);
	settextstyle(1, 0, 2);
	    outtextxy(20, 150, ": level one tutorial level ");
	     delay(2000);
	settextstyle(1, 0, 2);
	    outtextxy(40, 200, ": press up key to fly(^) ");
	     delay(2000);
	settextstyle(1, 0, 2);
	 outtextxy(40, 250, ": cross five gate to goto to the next level ");
	  delay(2000);
	settextstyle(1, 0, 1);
	   outtextxy(40, 300, ": in level-2: make the score as possible and know your rank ");
	       delay(2000);
    settextstyle(1, 0, 2);
       outtextxy(200, 400, "press 'enter' to skip ");  */

/*if (level==1)                                                // Checking the level
     {
do{
	   if(kbhit())
	   inpt=getch();
     }while(inpt!=13);
     }
cleardevice();
     }*/
d : if(level==2)                   // randomizing the wall if level is 2
 {
	 r=random(280);
	 b=random(280);
	 c=random(280);
}
	 randomize();


for(x=600;;x--,y--,z--)                            // starting of the main loop
  {


      wall(x,r);                                                 // Calling the function
      wall(y,b);
      wall(z,c);

  setfillstyle(9,RED);
      bar(150,a-20,200,a+10);
  setfillstyle(1,CYAN);
      bar(150,a-50,200,a-20);

	 a=a+1;
	 delay(f+1);
	  setbkcolor(CYAN);
if( (y+10 >=130&&y+10<=200) && a-20<=b)
break;                                     //checking the collision of the box
		  else if((y+10>=130 &&y+10<=200) && a+10>=b+100)
		  break;
  else if(( z+10>=130 && z+10 <=200) && a-20<=c)
  break;
		  else if((z+10>=130 && z+10 <=200) && a+10>=c+100)
		  break;
  else if(( x+10>=130 && x+10 <=200) && a-20<=r)
  break;
		   else if((x+10>=130 && x+10 <=200) && a+10>=r+100)
		   break;
  else if (a-20<=0)
  break;
		    else if (a+10>=640 )
		    break;
  else
  score=score+1;

  if(-120== y+10  && level == 1)           // Creating the wall again
   y=600;
	     if(-120== x+10 && level==1 )
	      x=600;
  if(-120== z +10 && level == 1)
    z=600;

if (score_main==5  && level==1 )      // Going to the next level
  {
     level=2;
       settextstyle(3, 0, 9);
	 outtextxy(100, 100, "level 2");
       settextstyle(1, 0, 4);
    outtextxy(100, 200, "press 'w' to continue ");

do{
	 if(kbhit())
	 inpt=getch();
	    inpt=tolower(inpt);
      }while(inpt!='w');
}
  if((score%250==0 && f>0)&& level==2)
    f=f-1 ;                                                     //increasing speed of wall

 if(-120== y+10 && level==2)                    // Randomizing the wall
  {
	     y=600;
	       b=random(280)+10;
  }
 if(-120== x+10 && level==2 )
  {
	      x=600;
		 r=random(280)+10;
  }
 if(-120== z +10 && level == 2)
  {
	      z=600;
		c=random(280)+10;
  }

  if(score%250==0)          //Increasing the score after crossing th wall
    score_main=score_main+1;

  if(kbhit())
    {
	     o=getch();
	     if((int)o==27)
	     break;
    }

if(kbhit())
{
	e=getch();
	  if((int)e==72)               // Jumping of the wall
	   {
		    setfillstyle(1,CYAN);
			bar(150,a-20,200,a+10);
			  a=a-30;
	   }
}



settextstyle(1, 0, 4);
   outtextxy(50, 220, "score : ");
settextstyle(1, 0, 2);
   outtextxy(50, 300, "press 'e'  to exit or press 'enter' to  continue");

itoa(score_main,sc,10);          //changing int into character
  outtextxy(189,230,sc);

if( score_main<=5)                  // else if ladder for rank
 {
     settextstyle(1, 0, 2);
     outtextxy(300, 240, "RANK : NOOB !");
 }

else if( score_main>5&&score_main<=13)
 {
     settextstyle(1, 0, 2);
     outtextxy(300, 240, "RANK : AMATEUR");
 }

else if ( score_main>13&&score_main<=20)
 {
     settextstyle(1, 0, 2);
     outtextxy(300, 240, "RANK : SKILLED");
 }

 else
  {
     settextstyle(1, 0, 2);
     outtextxy(50, 240, "RANK : PRO !!");
   }
m:
inpt=getch();
   if(inpt==13)
     goto y;
else if (inpt!='e')
   goto m;
 }
 x :
		setfillstyle(9,BLUE);
		bar(150,a-20,200,a+10);

setfillstyle(1,BLUE);
bar(45,100,600,350);

		setcolor(WHITE);
		settextstyle(1, 0, 9);
		outtextxy(50, 100, "GAME OVER");
			       //end of loop { end of game }
}