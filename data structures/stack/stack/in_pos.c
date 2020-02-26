#include<stdio.h>
#define size 50

struct stack
{
 int st[size];
 int top;
 };
 
 typedef struct stack S;
 
 void push(S *s,char ch)
 {
  s->top=s->top+1;
  s->st[s->top]=ch;
 }
 
 char pop(S *s)
 {
  return(s->st[s->top--]);
 }
 
 int prec(char ch)
 {
   if(ch=='(' || ch=='#') return 1;
   if(ch=='+' || ch=='-') return 2;
   if(ch=='*' || ch=='/') return 3;
   if(ch=='^' || ch=='$') return 4;
 }
 
 int main()
 {
  S s;
  s.top=-1;
  system("clear");
  char in[50],pos[50];
  int i,j=0;
  push(&s,'#');
  printf("\nEnter the infix expression\n");
  scanf("%s",in);
  for(i=0;in[i]!='\0';i++)
  {
   if(isalnum(in[i]))
   {
     pos[j++]=in[i];
   }
   else if(in[i]=='(')
        push(&s,in[i]);
        else if(in[i]==')')
             {
              while((s.st[s.top])!='(')
              {
               pos[j++]=pop(&s);
              } 
               pop(&s);
             }
             else
             {
              while(prec(s.st[s.top])>=prec(in[i]))
              pos[j++]=pop(&s);
              push(&s,in[i]);
             }
   }
   while(s.st[s.top]!='#')
   pos[j++]=pop(&s);
   pos[j]='\0';
   printf("\n postfix expression is : %s\n\n",pos);
   }             
                   
     
     
