/* Stack implementation using structure*/

#include<stdio.h>
#include<stdlib.h>
#define capacity 4

struct stack
{
int top;
int stack[capacity];
};

typedef struct stack STACK;

void push(STACK *s)
{
int item;
  if(s->top==capacity)
 {
   printf("\nStack Full\n");
   return;
 }
 else
 {
 printf("\nEnter the element to be inserted\n");
 scanf("%d",&item);
 s->top = s->top+1;
 s->stack[s->top]=item;
 
}
 return;
}

void pop(STACK *s)
{
 int item;
 if(s->top==-1)
 {
  printf("\nThe stack is empty");
  return;
 }
 else
 item=s->stack[s->top];
 s->top=s->top-1;
  printf("\n The deleted element is :%d",item);
 return ;
}

void display(STACK *s)
{
 int i;
 if(s->top==-1)
 {
  printf("\nThe stack is empty");
  return;
 }
 else
 {
   printf("Stack Contents are : ");
   for(i=s->top;i>=0;i--)
   printf("%d  ",s->stack[i]);
  }
 }
  
  void main()
  {
   STACK s;
   int choice,item;
   s.top=-1;
   for(;;)
   {
    printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
    scanf("%d",&choice);
    switch(choice)
    {
     case 1: 
             push(&s); break;
     
     case 2: pop(&s);break;
     case 3: display(&s); break;
     default :exit(0);
 
    }
    
    }
  }  
      

 
    
 
