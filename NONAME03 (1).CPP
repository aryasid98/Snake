#include<include.h>
#include<conio.h>
struct node
{ node*next;

}*ptr,*save,*rear;
void insert()
{ ptr=new node;
  ptr->next=NULL;
  if (rear==NULL)
  { rear=ptr;
  }
  else
  { save=rear;
    rear=ptr;
    save->next=rear;
  }

}
void main()

