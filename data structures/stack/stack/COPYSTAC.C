#include<stdio.h>
#include<stdlib.h>
#define size 10
struct stack
{
 int s[size];
 int top;
};
typedef struct stack ST;


void push(ST *st,int item)
{
 if(st->top==size-1)
 {
  printf("Stack full\n");
  return;
 }
 st->top++;
 st->s[st->top]=item;

}

int pop(ST *st,int top)
{
 int item;
 if(st->top==-1)
 {
  printf("Stack empty\n");
  return 0;
 }
 item = st->s[st->top];
 st->top--;
 return item;
}


void copystack(ST *src,ST *dst,ST *temp)
{

 int i,j,item;

for(i=src->top;i>=0;i--)
{
item=pop(src,src->top);
push(temp,item);
}

for(j=temp->top;j>=0;j--)
 {
 item=pop(temp,temp->top);
 push(dst,item);
 }
}

void display(ST *st)
{
 int i;
 if(st->top==-1)
 {
  printf("\nStack empty nothing to display\n");
  return;
  }
  printf("\nContents of the stack are\n");
 for(i=st->top;i>=0;i--)
 printf("\n%d",st->s[i]);

}



int main()
{
ST src,dst,temp;
int choice,item;
char ch;
src.top=-1;dst.top=-1;temp.top=-1;
for(;;)
{
printf("\n1.push to source");
printf("\n2.copy to dest");
printf("\n3.display source");
printf("\n4.display destination");
printf("\nEnter your choice\n");
scanf("%d",&choice);


switch(choice)
{
 case 1: printf("\nEnter the elemen t");
	 scanf("%d",&item);
	 push(&src,item);
	 break;

 case 2: copystack(&src,&dst,&temp);
	 break;
 case 3: printf("\n\nContents of Source");
	 display(&src);
	 break;
 case 4: printf("\n\nContents of Destination");
	 display(&dst);
	 break;

 default :exit(0);
 }

 
 scanf("%c",&ch);


}

}
