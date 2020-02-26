#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int s[40];
int top=-1;

void disp()
{ int i;
 for(i=top;i>=0;i--)
 printf("%d",s[i]);
 printf("\n\n");
}


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
  int n,dig;
  printf("\nEnter an integer\n");
  scanf("%d",&n);
  while(n>0)
  {
  dig=n%2;
  push(dig);
  n=n/2;
  }
  
printf("\nBinary equivalent is :");
 disp();
}  
