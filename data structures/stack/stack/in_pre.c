#include<stdio.h>
#include<string.h>
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
  char in[50],pos[50],inf[50],pre[50];
  int i,j=0,k;
  push(&s,'#');
  printf("\nEnter the infix expression\n");
  scanf("%s",inf);
  
  for(i=0;inf[i]!='\0';i++){}
  i--;
  
  for(k=0;i>=0;i--,k++)
  in[k]=inf[i];
  in[k]='\0';
  
  printf("%s",in);
  j=0;
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
   
  for(i=0;pos[i]!='\0';i++){}
  i--;
  for(k=0;i>=0;i--,k++)
  pre[k]=pos[i];
  pre[k]='\0';
   //strrev(pos);
   printf("\n postfix expression is : %s\n\n",pre);
   }             
                   
     
     
