#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

void main()
{ clrscr();
 int arr[25],pseudo[25],bingo[6][6];
 randomize();
 int c=random(25)+1;
 for(int i=0;i<25;i++)
 { arr[i]=random(25)+1;
   pseudo[i]=arr[i];
   for(int j=0;j<i;j++)
   { if (pseudo[j]==arr[i])
     i--;
   }

 }
 int t=5;
 for(int k=0;k<5;k++)
 {
 for(int r=0;r<5;r++)
 { bingo[k][r]=arr[t*k+r];
 }

 }
 for(k=0;k<5;k++)
 for(int r=0;r<5;r++)
 {cout<<bingo[k][r];
 cout<<" ";
 }
 getch();

}