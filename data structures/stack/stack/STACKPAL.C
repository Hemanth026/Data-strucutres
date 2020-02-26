#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int top=-1;
void display(char s[30])
{ int i;
 for(i=0;i<=top;i++)
  printf("%c",s[i]);
}
void push(char s[20],char ch)
{
 s[++top]=ch;
}

char pop(char s[30])
{
 return(s[top--]);
 }

int main()
{
 char s[30],in[30],ch;
 int i=0,j,flag=0,n;
 printf("Enter the string\n");
 scanf("%s",in);
 while(in[i]!='\0')
{
 push(s,in[i]);
  i++;
}
  j=0;
 while(top!=-1)
 {
  if(pop(s)!=in[j])
  {
   flag=1;
   break;
  } 
  j++;
  }
  if(flag==0)
  printf("palindrome\n");
  else
  printf("not a palindrome\n");
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
