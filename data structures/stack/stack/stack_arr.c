/* Stack implementation using static array*/

#include<stdio.h>
#include<stdlib.h>
#define capacity 4

int top=-1;
int stack[capacity];

void push()
{
 int item;
 if(top==capacity)
 {
   printf("\nStack Full\n");
   return;
 }
 else
 {
 printf("\nEnter the element to be inserted\n");
 scanf("%d",&item);
 top=top+1;
 stack[top]=item;
}
 return;
}

void pop()
{
 int item;
 if(top==-1)
 {
  printf("\nThe stack is empty");
  return;
 }
 else
 item=stack[top];
 top=top-1;
  printf("\n The deleted element is :%d",item);
 return ;
}

void display()
{
 int i;
 if(top==-1)
 {
  printf("\nThe stack is empty");
  return;
 }
 else
 {
   printf("Stack Contents are : ");
   for(i=top;i>=0;i--)
    
    printf("%d  ",stack[i]);
   
    }
  }
  
  void main()
  {
   int choice;
   for(;;)
   {
    printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
    scanf("%d",&choice);
    switch(choice)
    {
     case 1: push(); break;
     
     case 2: pop();
             break;
     case 3: display(); break;
     default :exit(0);
    }
    
    }
  }  
      

    
 
