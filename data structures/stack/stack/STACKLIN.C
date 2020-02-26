
/* STACK IMPLEMENTATION USING LINKED LIST */

#include<stdio.h>

#include<alloc.h>
#define size 5
int count=1;

struct node
{
  int info;
  struct node *link;
};
typedef struct node* NODE;

NODE getnode()
{
  NODE x;
  x=(NODE)malloc(sizeof(struct node));
    if(x==NULL)
  {
    printf("Out of memory\n");
  }
  return x;
}

void freenode(NODE x)
{
   free(x);
}

NODE push(int item,NODE first)
{
  NODE temp;
   temp=getnode();
  temp->info=item;
  temp->link=NULL;
  if(first==NULL)
   return temp;
  else
  {
  temp->link=first;
  count++;
  return temp;
  }

}

NODE pop(NODE first)
{
  NODE prev,cur;
  if(first==NULL)
  {
   printf("Stack Empty\n");
   return first;
  }
 else
  if(first->link==NULL)
  {
  printf("The item popped is %d\n",first->info);

  freenode(first);
    first=NULL;
  return first;
  }
  else
  {
prev=first;
first=first->link;
printf("The item deleted is %d\n",prev->info);
freenode(prev);
count--;
return first;
}
}


void display(NODE first)
{
  NODE temp;
  if(first==NULL)
  {
   printf("stack  is empty\n");
   return;
  }
  printf("\nThe contents of the stack are:\n");
  temp=first;
  while(temp!=NULL)
  {
    printf("%d\n",temp->info);
    temp=temp->link;
  }

}

void main()
{
 NODE first=NULL;
 int choice,item;
  clrscr();
 do
 {
   printf("\n1:PUSH\n");
   printf("2:POP\n");
   printf("3:DISPLAY\n");
   printf("4:EXIT\n");
   printf("Enter ur choice\n");
   scanf("%d",&choice);
   switch(choice)
   {
     case 1: if(count==size)
     {  printf("\nStack overflow\n");
	break;
     }
     else
	     printf("Enter the item to be pushed\n");
	     scanf("%d",&item);
	     first=push(item,first);
	     break;

     case 2: first=pop(first);
	     break;

     case 3:display(first);
	     break;
    default : exit(0);
    }
    }while(choice!=4);
   }







