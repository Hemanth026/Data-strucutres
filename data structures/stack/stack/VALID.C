#include<stdio.h>

char s[40];
int top=-1;

void disp()
{ int i;
 for(i=0;i<=top;i++)
 printf("%c",s[top]);
}


void push(char ch)
{
 top=top+1;
 s[top]=ch;
}

char pop()
{
 return(s[top--]);
}


 int main()
 {
 char in[40],ch;
 int i,j,flag=0;
 //system("clear");
 printf("Enter the parenthised expression\n");
 scanf("%s",in);
 for(i=0;in[i]!='\0';i++)
 {
  if(in[i]=='(' || in[i]=='[' || in[i]=='{')
   push(in[i]);
  else if(in[i]==')' || in[i]==']' || in[i]=='}')

	if(top==-1)

       flag=1;
      else
      {
       ch=pop();

      if( (ch=='(' && in[i]!=')') || (ch=='{'&& in[i]!='}') || (ch=='[' && in[i]!=']'))
       flag=1;
       }
     }
   if(top!=-1)
    flag=1;
    if(flag==0)
    printf("%s is a valid expression",in);
    else
    printf("%s is not a valid expression",in);
  }
