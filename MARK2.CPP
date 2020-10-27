#include<iostream.h>
#include<conio.h>
void nocursor(int x1,int y1,int x2,int y2)
	{     textmode(C4350);
		window(x1+1,y1+1,x2-1,y2-1);
		textbackground(CYAN);
	    	textcolor(LIGHTGREEN);
		clrscr();

	}

void cursor(int x1,int y1,int x2,int y2)
	{     textmode(C4350);
		window(x1+1,y1+1,x2-1,y2-1);
		textbackground(BLUE);
	   	textcolor(LIGHTGREEN);
		clrscr();

	}

void box(int x1,int y1,int x2,int y2,int z1, int z2)
{       int i=0;
	clrscr();
	textmode(C4350);
       //	window(x1,y1,x2,y2);
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
		char vmid='³';   //179                'ÒÓÞßÆ¯´¯°±²³´µ¶·¸¹º»X½¼½À¾ÀÁÂ
		char hmid='Ä';  //196

			gotoxy(x1,y1);//for positioning
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
		  for(int j=1;j<z2;j++)
		  {
		     for(i=x1+1;i<=x2-1;i++)
		     {   gotoxy(i,y1+z2*j);
			 cout<<hmid;
		     }
		  }
		  for(int k=1;k<z1;k++)
		     for(i=y1+1;i<=y2-1;i++)
		     {   gotoxy(x1+z1*k,i);
			 cout<<vmid;
		     }

  }
void main()
{ clrscr();
int x1=5,x2=30,y1=5,y2=30,z1=5,z2=5,c=0,a=0,b=0;
char ch;
box(x1,y1,x2,y2,z1,z2);
for(int i=0;i<z1;i++)
for(int j=0;j<z2;j++)
{
nocursor(x1+i*z1,y1+j*z2,x1+z1+i*z1,y1+z2+j*z2);
}
cursor(x1,y1,x1+z1,y1+z2);
while(c!=1)
{ ch=getch();
  if(ch==0)
  ch=getch();
  switch(ch)
  { case 80:if(a==4)
	    {nocursor(x1,y1,x1+z1,y1+z2);
	    y1=y1-z2*a;
	    cursor(x1,y1,x1+z1,y1+z2);


	     //y2=y2-z2*a+z2;
	     a=0;
	    }
	    else
	    {a++;
	     y1=y1+z2;
	     cursor(x1,y1,x1+z1,y1+z2);
	     nocursor(x1,y1-z2,x1+z1,y1);

	   // y2=y2+z2*a+z2;
	    }
	    break;
    case 72:if(a==0)
	    { a=4;
	    nocursor(x1,y1,x1+z1,y1+z2);
	      y1=y1+a*z2;
	      cursor(x1,y1,x1+z1,y1+z2);

	    }
	    else
	    {a--;
	     nocursor(x1,y1,x1+z1,y1+z2);
	     y1=y1-z2;
	     cursor(x1,y1,x1+z1,y1+z2);


	    } break;
    case 75:if(b==0)
	    { b=4;
	    nocursor(x1,y1,x1+z1,y1+z2);
	      x1=x1+b*z1;
	      cursor(x1,y1,x1+z1,y1+z2);

	    }
	    else
	    {b--;
	     nocursor(x1,y1,x1+z1,y1+z2);
	     x1=x1-z1;
	     cursor(x1,y1,x1+z1,y1+z2);


	    } break;
    case 77:if(b==4)
	    {nocursor(x1,y1,x1+z1,y1+z2);
	    x1=x1-z1*b;
	    cursor(x1,y1,x1+z1,y1+z2);
	    b=0;
	    }
	    else
	    {b++;
	     x1=x1+z2;
	     cursor(x1,y1,x1+z1,y1+z2);
	     nocursor(x1-z1,y1,x1,y1+z2);

	   // y2=y2+z2*a+z2;
	    }
	    break;
    case 27:c=1;break;
  }
}

//getch();
}
