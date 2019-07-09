#include<fstream.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<dos.h>
void nocursor(int x1,int y1,int x2,int y2)
	{     textmode(C4350);
		window(x1,y1,x2,y2);
		textbackground(RED);
	       //	textcolor(LIGHTGREEN);
		clrscr();

	}

void cursor(int x1,int y1,int x2,int y2)
	{     textmode(C4350);
		window(x1,y1,x2,y2);
		textbackground(CYAN);
	       //	textcolor(LIGHTGREEN);
		clrscr();

	}
void box(int x1,int y1,int x2,int y2)
{       int i=0;
	clrscr();
	textmode(C4350);
	window(x1,y1,x2,y2);
		textbackground(RED);
		textcolor(YELLOW);
		clrscr();
		window(1,1,80,50);
		char vert='º';
		char horz='Í';
		char rttop = '»';
		char lttop = 'É' ;
		char rtbott = '¼' ;
		char ltbott='È' ;
		char vmid='³';   //179            ABCD    'ÒÓÞßÆ¯´¯°±²³´µ¶·¸¹º»X½¼½À¾ÀÁÂ
		char hmid='Ä';  //196

		/*	gotoxy(x1,y1);//for positioning
				cout<<lttop;
				gotoxy(x2,y1);
				cout<<rttop;
				gotoxy(x1,y2);
				cout<<ltbott;
				gotoxy(x2,y2);
				cout<<rtbott;
				for(i=y1+1;i<=y2-1;i++)
					{
						gotoxy(x1,i);
						cout<<vert;
					}
				for(i=y1+1;i<=y2-1;i++)
					{
						gotoxy(x2,i);
						cout<<vert;
					}
				for(i=x1+1;i<=x2-1;i++)
					{
						gotoxy(i,y1);
						cout<<horz;
					}
				for(i=x1+1;i<=x2-1;i++)
					{
						gotoxy(i,y2);
						cout<<horz;
					}
		     for(i=x1+1;i<=x2-1;i++)
		     {   gotoxy(i,(y1+y2)/2);
			 cout<<hmid;
		     }
		     for(i=y1+1;i<=y2-1;i++)
		     {   gotoxy((x1+x2)/2,i);
			 cout<<vmid;
		     }     */

  }
void main()
{ clrscr();
box(1,1,40,25);
char ch;
int a=0,b=0,c,i=0;
while(!kbhit())
{

nocursor(6+i,6,6.5+i,6.5);
cursor(6+i,6,7+i,6.5);
delay(500);
	      i++;
}
if(kbhit())
{
c=getch();

}
cout<<c;





//cout<<"iksdjfilksdtgklndffgfbjk.dffjkghkjdfghn";


//nocursor(16,16,24,24);
//nocursor(16,6,24,14);
//nocursor(6,16,14,24);
/*while(c!=1)
{ ch=getch();
  if(ch==0)
  ch=getch();
  switch(ch)
  { case 72:if(a==0)
	    {a=1;
	     cursor(6,16,14,24);
	     nocursor(6,6,14,14);
	    }
	    else
	    {a--;
	     cursor(6,6,14,14);
	     nocursor(6,16,14,24);
	    }
	    break;
   case 27:c++;break;
  }
}
*/

getch();
}