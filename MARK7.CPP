#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
class bingo
{ public:
int no;
int count;
};
void nocursor(int x1,int y1,int x2,int y2,int value=0)
	{     textmode(C4350);
		window(x1+1,y1+1,x2-1,y2-1);
		textbackground(CYAN);
		textcolor(BLUE);

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
		textcolor(BLACK);
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
int p_cord(int &x)
{ if(x==4)
  x=0;
  else
  x++;

  return x ;
}
int n_cord(int &x)
{ if(x==0)
  x=4;
  else
  x--;

  return x ;
}
 void check(int &x1,int &y1,int &x2,int &y2,int a,int b)
{ x1=5+a*5;
  y1=5+b*5;
  x2=10+a*5;
  y2=10+b*5;
 }
void main()
{ clrscr();
bingo arr[5][5];
int x1=5,x2=30,y1=5,y2=30,z1=5,z2=5,a=0,b=0,val;
char ch;
int array[25],pseudo[25];
 randomize();
 //int c=random(25)+1;
 for(int i=0;i<25;i++)
 { array[i]=random(25)+1;
   pseudo[i]=array[i];
   for(int j=0;j<i;j++)
   { if (pseudo[j]==array[i])
     i--;
   }

 }
 int t=5,c=0;
 for(int k=0;k<5;k++)
 {
 for(int r=0;r<5;r++)
 { arr[k][r].no=array[t*k+r];
 }

 }
box(x1,y1,x2,y2,z1,z2);
for(i=0;i<z1;i++)
for(int j=0;j<z2;j++)
{ val=arr[i][j].no;
arr[i][j].count=0;
nocursor(x1+i*z1,y1+j*z2,x1+z1+i*z1,y1+z2+j*z2,val);
}
val=arr[0][0].no;
cursor(x1,y1,x1+z1,y1+z2,val);
while(c!=1)
{ ch=getch();
  if(ch==0)
  ch=getch();
  switch(ch)
  {

  case 80://val=arr[a][b].no;
	     check(x1,y1,x2,y2,a,b);
	     val=arr[a][b].no;
	     if((arr[a][b].count)==1)
	     {}
	     else
	    nocursor(x1,y1,x2,y2,val);
	    for(i=0,k=0;k!=1;i++)
	    { b=p_cord(b);
	      if((arr[a][b].count)==1)
	      {
		continue;

	      }
	     else
	     { k=1;
	     check(x1,y1,x2,y2,a,b);
	     val=arr[a][b].no;
	     cursor(x1,y1,x2,y2,val);
	     }
	    }
	    break;
  case 81://val=arr[a][b].no;

	     check(x1,y1,x2,y2,a,b);
	     val=arr[a][b].no;
	     if((arr[a][b].count)==1)
	     {}
	     else
	    nocursor(x1,y1,x2,y2,val);
	   /// a=p_cord(a);
	   // b=p_cord(b);
	    for(i=0,k=0;k!=1;i++)
	    { b=p_cord(b);
	      a=p_cord(a);
	      if((arr[a][b].count)==1)
	      {
		continue;

	      }
	     else
	     { k=1;
	     check(x1,y1,x2,y2,a,b);
	     val=arr[a][b].no;
	     cursor(x1,y1,x2,y2,val);
	     }
	    }
	    break;
   case 79://val=arr[a][b].no;

	     check(x1,y1,x2,y2,a,b);
	     val=arr[a][b].no;
	     if((arr[a][b].count)==1)
	     {}
	     else
	    nocursor(x1,y1,x2,y2,val);
	   /// a=p_cord(a);
	   // b=p_cord(b);
	    for(i=0,k=0;k!=1;i++)
	    { b=p_cord(b);
	      a=n_cord(a);
	      if((arr[a][b].count)==1)
	      {
		continue;

	      }
	     else
	     { k=1;
	     check(x1,y1,x2,y2,a,b);
	     val=arr[a][b].no;
	     cursor(x1,y1,x2,y2,val);
	     }
	    }
	    break;
  case 73://val=arr[a][b].no;

	     check(x1,y1,x2,y2,a,b);
	     val=arr[a][b].no;
	     if((arr[a][b].count)==1)
	     {}
	     else
	    nocursor(x1,y1,x2,y2,val);
	   /// a=p_cord(a);
	   // b=p_cord(b);
	    for(i=0,k=0;k!=1;i++)
	    { b=n_cord(b);
	      a=p_cord(a);
	      if((arr[a][b].count)==1)
	      {
		continue;

	      }
	     else
	     { k=1;
	     check(x1,y1,x2,y2,a,b);
	     val=arr[a][b].no;
	     cursor(x1,y1,x2,y2,val);
	     }
	    }
	    break;
  case 71://val=arr[a][b].no;

	     check(x1,y1,x2,y2,a,b);
	     val=arr[a][b].no;
	     if((arr[a][b].count)==1)
	     {}
	     else
	    nocursor(x1,y1,x2,y2,val);
	   /// a=p_cord(a);
	   // b=p_cord(b);
	    for(i=0,k=0;k!=1;i++)
	    { b=n_cord(b);
	      a=n_cord(a);
	      if((arr[a][b].count)==1)
	      {
		continue;

	      }
	     else
	     { k=1;
	     check(x1,y1,x2,y2,a,b);
	     val=arr[a][b].no;
	     cursor(x1,y1,x2,y2,val);
	     }
	    }
	    break;


  case 72: //val=arr[a][b].no;
	     check(x1,y1,x2,y2,a,b);
	     val=arr[a][b].no;
	     if((arr[a][b].count)==1)
	     {}
		   else
		    nocursor(x1,y1,x2,y2,val);
	    for(i=0,k=0;k!=1;i++)
	    { b=n_cord(b);
	      if((arr[a][b].count)==1)
	      {
		continue;

	      }
	     else
	     { k=1;
	     check(x1,y1,x2,y2,a,b);
	     val=arr[a][b].no;
	     cursor(x1,y1,x2,y2,val);
	     }
	    }
	    break;
  case 77: //val=arr[a][b].no;
	     check(x1,y1,x2,y2,a,b);
	     val=arr[a][b].no;
	     if((arr[a][b].count)==1)
	     {}
	     else
	    nocursor(x1,y1,x2,y2,val);
	    for(i=0,k=0;k!=1;i++)
	    { a=p_cord(a);
	      if((arr[a][b].count)==1)
	      {
		continue;

	      }
	     else
	     { k=1;
	     check(x1,y1,x2,y2,a,b);
	     val=arr[a][b].no;
	     cursor(x1,y1,x2,y2,val);
	     }
	    }
	    break;
   case 75://val=arr[a][b].no;
	     check(x1,y1,x2,y2,a,b);
	     val=arr[a][b].no;
	     if((arr[a][b].count)==1)
	     {
	     }
	     else
	    nocursor(x1,y1,x2,y2,val);
	    for(i=0,k=0;k!=1;i++)
	    { a=n_cord(a);
	      if((arr[a][b].count)==1)
	      {
		continue;

	      }
	     else
	     { k=1;
	     check(x1,y1,x2,y2,a,b);
	     val=arr[a][b].no;
	     cursor(x1,y1,x2,y2,val);
	     }
	    }
	    break;
   case 13:val=arr[a][b].no;
	   check(x1,y1,x2,y2,a,b);

	   rcursor(x1,y1,x2,y2,val);
	   arr[a][b].count=1;
	   break;

  case 27:c=1;break;
  }
}


}