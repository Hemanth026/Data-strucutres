/* CIRCULAR DOUBLY LINKED LIST WITH HEADER NODE*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
 int info;
 struct node *llink;
 struct node *rlink;
};

typedef struct node * NODE;

NODE creat()
{
 NODE x;
 x=(NODE)malloc(sizeof(struct node));
 if(x==NULL)
 {
    printf("Out of memory");
    exit(0);
 }
   x->llink=NULL;
   x->rlink=NULL;
 return x;
}

NODE insert(NODE first,int ch)
 {
  NODE temp,pre,cur;
  int val;
  temp=creat();
  if(first==NULL)
  {
   printf("First entry\n Enter an integer\n");
   scanf("%d",&temp->info);
   
   first=temp;
   return first;
  }

  if(ch==1)                   //Insert Front
  {
   printf("Enter the integer\n");
    scanf("%d",&temp->info);
    
    temp->rlink=first;
    first->llink=temp;
    first=temp;
  }

  else if(ch==2)              //Insert to the left of a key
  {
   printf("Enter the key value :");
   scanf("%d",&val);
   if(val==first->info)
   return insert(first,1);     // Same a inserting in the front end
   printf("Enter the integer\n");
   scanf("%d",&temp->info);
   for(cur=first;  (cur!=NULL) && (val!=cur->info); pre=cur,cur=cur->rlink);
   if(cur!=NULL)        // inbetween two nodes
   {
    temp->llink=pre;
    temp->rlink=cur;
    pre->rlink=temp;
    cur->llink=temp;
   }
   else
    printf("Invalid Key\n");
  }
  else if(ch==3)                 //Insert Rear
  {
   NODE cur,temp=creat();
   printf("Enter the integer\n");
   scanf("%d",&temp->info);
   cur=first;
   while(cur->rlink!=NULL)
   {
    cur=cur->rlink;
    }
    cur->rlink=temp;
    temp->llink=cur;
   }  
  return first;
}


NODE del(NODE first,int ch)
{int id;
 NODE temp,cur,pre;
  if(first==NULL)
 {
  printf("List empty\n");
  return first;
 }
  
 if(ch==1)             // Delete Front
 {
   first=first->rlink;
   return first;
 }
 
 else if(ch==2)        //Delete Rear
 {
  temp=first;
  while(temp->rlink!=NULL)
  {
   temp=temp->rlink;
  }
  pre=temp->llink;
  pre->rlink=NULL;
  free(temp);
  return first;
 } 
     
 if(ch==3)              //Delete the left of a key
 { 

 printf("\nEnter the key value:");
 scanf("%d",&id);
 for(temp=first;(temp!=NULL) && (id!=temp->info); temp=temp->rlink);
 if(temp!=NULL)
 {
  printf("Deleted integer is : %d\n",temp->info);
   if(temp==first)
   {
     if(first->rlink==NULL) /* if the list contains only one node and */
      first=NULL;           /* if the id match with that node */
     else
     {
      first=first->rlink;  /* if the id matches with the value of first node*/
      first->llink=NULL;
     }
   }

   else
     if(temp->rlink==NULL)  /* if the node to be deleted is the last node*/
     { pre=temp->llink;
      pre->rlink=NULL; }
     else
     {
       pre=temp->llink;
       cur=temp->rlink;
       pre->rlink=cur;    /* middle of the list */
       cur->llink=pre;
     }
     free(temp);
  }
  else
   printf("invalid key number\n");
  } return first;
}


void display(NODE  first)
{
 NODE temp;
 if(first==NULL)
 {
  printf("List empty\n");
  return;
 }
 else
 {
 printf("\n CONTENTS OF THE LIST IS \n");
 for(temp=first;temp!=NULL;temp=temp->rlink)
 printf("%d\t",temp->info);
 }
}


main()
{
 NODE first=NULL;
 int choice,ch;

 for(;;)
 {
  printf("\n1: INSERT\n2: DELETE\n3: DISPLAY\n");
  printf("Enter your choice :\n");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1: printf("\nSELECT TO INSERT AT :\n1. Front end\n2: To the left of key \n3. Rear end\n");
	   printf("Enter your choice :\n");
	   scanf("%d",&ch);
	   printf("\n");
	   switch(ch)
	   {
	     case 1:
	     case 2:
	     case 3:first=insert(first,ch);
		    break;
	     default: printf("Wrong entry\n");
		      
	   }
	   break;
   case 2: printf("\nSELECT TO DELETE AT :\n1. Front end\n2. Rear end\n3. The given key\n");
	   printf("Enter your choice :\n");
	   scanf("%d",&ch);
	   printf("\n");
	   switch(ch)
	   {
	     case 1:
	     case 2:
	     case 3: first=del(first,ch);
	             break;
	             default: printf("Wrong entry\n");
		      
	   } break;
   case 3: display(first);
	   break;
   default:exit(0);
  }
 }
}
