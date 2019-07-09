
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
void nocursor(int x1,int y1,int x2,int y2,int value=0)
	{     textmode(C4350);
		window(x1+1,y1+1,x2-1,y2-1);
		textbackground(CYAN);
		textcolor(LIGHTGREEN);

		clrscr();
		window(x1+2.5,y1+2.5,x1+2.5,y1+3.5);
		cout<<value;

	}

void cursor(int x1,int y1,int x2,int y2,int value=0)
	{     textmode(C4350);
		window(x1+1,y1+1,x2-1,y2-1);
		textbackground(BLUE);
	       //	textcolor(LIGHTGREEN);
		clrscr();
		window(x1+2.5,y1+2.5,x1+2.5,y1+3.5);
		cout<<value;

	}

void rcursor(int x1,int y1,int x2,int y2,int value=0)
	{     textmode(C4350);
		window(x1+1,y1+1,x2-1,y2-1);
		textbackground(RED);
	       //	textcolor(LIGHTGREEN);
		clrscr();
		window(x1+2.5,y1+2.5,x1+2.5,y1+3.5);
		cout<<value;

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
int arr[25],pseudo[25],bingo[5][5],value,val1,val2;
 randomize();
 //int c=random(25)+1;
 for(int i=0;i<25;i++)
 { arr[i]=random(25)+1;
   pseudo[i]=arr[i];
   for(int j=0;j<i;j++)
   { if (pseudo[j]==arr[i])
     i--;
   }

 }
 int t=5,ar[25],pointer=0;
 for(int k=0;k<5;k++)
 {
 for(int r=0;r<5;r++)
 { bingo[k][r]=arr[t*k+r];
 }

 }
box(x1,y1,x2,y2,z1,z2);
for(i=0;i<z1;i++)
for(int j=0;j<z2;j++)
{ value=bingo[i][j];
nocursor(x1+i*z1,y1+j*z2,x1+z1+i*z1,y1+z2+j*z2,value);
}
int val=bingo[0][0];
cursor(x1,y1,x1+z1,y1+z2,val);
while(c!=1)
{ int d=0,e=0;
  ch=getch();
  if(ch==0)
  ch=getch();
  switch(ch)
  { case 80://cursor(x1+z1,y1+)
	    for(int ptr=0;ptr<pointer;ptr++)
	     if(bingo[b][a]==ar[ptr])
	     {  int val3=bingo[b][a];
		rcursor(x1,y1,x1+z1,y1+z2,val3);


		d=1;
		break;
	     }
	     for( ptr=0;ptr<pointer;ptr++)
	     if(bingo[b][a+1]==ar[ptr])
	     {  int val4=bingo[b][a];
		nocursor(x1,y1,x1+z1,y1+z2,val4);
		a++;

		e++;
		break;
	     }

	    if(a==4)
	    { val1=bingo[b][a];

	    if(d==0)
	    nocursor(x1,y1,x1+z1,y1+z2,val1);

	    y1=y1-z2*a;
	    a=0;
	    val2=bingo[b][a];
	    if(e==0)
	    cursor(x1,y1,x1+z1,y1+z2,val2);
	    else
	    {    y1=y1+e*z2;
	    cursor(x1,y1,x1+z1,y1+z2,val2);
	    }
	     //y2=y2-z2*a+z2;
	     //a=0;
	    }
	    else
	    {
	     y1=y1+z2;
	     val1=bingo[b][a];
	     if(d==0)
	     nocursor(x1,y1-z2,x1+z1,y1,val1);
	     a++;
	     val2=bingo[b][a];
	     if(e==0)
	     cursor(x1,y1,x1+z1,y1+z2,val2);
	     else
	     { y1=y1+e*z2;
	     cursor(x1,y1,x1+z1,y1+z2,val2);
	     }
	   // y2=y2+z2*a+z2;
	    }
	    break;
    case 72:if(a==0)
	    { val1=bingo[b][a];
	    nocursor(x1,y1,x1+z1,y1+z2,val1);
	    a=4;
	      y1=y1+a*z2;
	      val2=bingo[b][a];
	      cursor(x1,y1,x1+z1,y1+z2,val2);

	    }
	    else
	    {//a--;
	     val1=bingo[b][a];
	     nocursor(x1,y1,x1+z1,y1+z2,val1);
	     y1=y1-z2;
	     a--;
	     val2=bingo[b][a];

	     cursor(x1,y1,x1+z1,y1+z2,val2);


	    } break;
    case 75:if(b==0)
	    { val1=bingo[b][a];
	    nocursor(x1,y1,x1+z1,y1+z2,val1);
	     b=4;
	     val2=bingo[b][a];
	      x1=x1+b*z1;
	      cursor(x1,y1,x1+z1,y1+z2,val2 );

	    }
	    else
	    {//b--;
	    val1=bingo[b][a];
	     nocursor(x1,y1,x1+z1,y1+z2,val1);
	     b--;
	     val2=bingo[b][a];
	     x1=x1-z1;
	     cursor(x1,y1,x1+z1,y1+z2,val2);


	    } break;
    case 77:if(b==4)
	    {val1=bingo[b][a];
	    nocursor(x1,y1,x1+z1,y1+z2,val1);
	    x1=x1-z1*b;
	    b=0;

	    val2=bingo[b][a];
	    cursor(x1,y1,x1+z1,y1+z2,val2);

	    }
	    else
	    { x1=x1+z1;
	     val1=bingo[b][a];
	     nocursor(x1-z1,y1,x1,y1+z2,val1);
	    b++;
	    val2=bingo[b][a];

	     cursor(x1,y1,x1+z1,y1+z2,val2);


	   // y2=y2+z2*a+z2;
	    }
	    break;
    case 13:ar[pointer]=bingo[b][a];

	    int y=ar[pointer];
	    pointer++;
	    rcursor(x1,y1,x1+z1,y1+z1,y);
	    //cursor(x1,y1+z1,x1+z1,y1+2*z1);
	    break;


    case 27:c=1;break;
  }
}


}