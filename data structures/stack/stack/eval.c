#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int s[40];
int top=-1;

void push(int ele)
{
 top=top+1;
 s[top]=ele;
}

char pop()
{
 return(s[top--]);
}


 int main()
 {
 char pos[40];
 int i,res,op1,op2;
 printf("\nEnter the postfix expression\n");
 scanf("%s",pos);
 i=0;
 while(pos[i]!='\0')
 {
  if(isdigit(pos[i]))
  push(pos[i]-'0');
  else
  { 
    op2=pop();
    op1=pop();
    
    switch(pos[i])
    {
    case '+': res=op1+op2;
              push(res);
              break;
              
    case '-': res=op1-op2;
              push(res);
              break;
    
    case '*': res=op1*op2;
              push(res);
              break;
    
    case '/': res=op1/op2;
              push(res);
              break;
              
    case '$': res=pow(op1,op2);
              push(res);
              break;
    default: printf("invalid operator!!!!!\n");
             exit(0);
    }
   }
   i++;
  }
printf("\nThe value of the expression is %d\n\n",res);

 } 
             
  
  
