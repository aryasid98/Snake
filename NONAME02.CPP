#include<iostream.h>
#include<stdio.h>
#include<conio.h>
void main()
{
int x1=5,y2=20,x2=20;
clrscr();
   for(int i=x1+1;i<=x2-1;i++)
   {
	gotoxy(i,y2);
	cout<<"Ä";
   }
   getch();
}