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
   x->llink=x;
   x->rlink=x;
 return x;
}

NODE insert(NODE head,int ch)
 {
  NODE temp,pre,cur;
  int val;
  temp=creat();
     
   if(ch==1)                   //Insert Front
  {
   printf("Enter the integer\n");
    scanf("%d",&temp->info);
    cur=head->rlink;
    temp->rlink=cur;
    cur->llink=temp;
    temp->llink=head;
    head->rlink=temp;
    return head;
    }

  else if(ch==2)              //Insert to the left of a key
  {
   printf("Enter the key value :");
   scanf("%d",&val);
   if(val==(head->rlink)->info)
   return insert(head,1);     // Same a inserting in the front end
   printf("Enter the integer\n");
   scanf("%d",&temp->info);
   for(cur=head->rlink;  (cur!=head) && (val!=cur->info);cur=cur->rlink);
   if(cur!=NULL)        // inbetween two nodes
   {
    pre=cur->llink;
    temp->llink=pre;
    temp->rlink=cur;
    pre->rlink=temp;
    cur->llink=temp;
    return head;
   }
   else
    printf("Invalid Key\n");
  }
  else if(ch==3)                 //Insert Rear
  {
   NODE cur,temp=creat();
   printf("Enter the integer\n");
   scanf("%d",&temp->info);
   cur=head->llink;
  
    cur->rlink=temp;
    temp->llink=cur;
    temp->rlink=head;
    head->llink=temp;
    return head;
   }  
  
}


 NODE del(NODE head,int ch)
{int id;
 NODE temp,cur,pre;
  if(head->rlink==head)
 {
  printf("List empty\n");
  return head;
 }
  
 if(ch==1)             // Delete Front
 {
   
   temp=head->rlink;
   if(temp->rlink==head)
   {
     head->rlink=head->llink=head;
     return head;
   }   
   head->rlink=temp->rlink;
   (temp->rlink)->llink=head;
   free(temp);
   return head;
 }
 
 else if(ch==2)        //Delete Rear
 {
  temp=head->llink;
  
  pre=temp->llink;
  pre->rlink=head;
  head->llink=pre;
  free(temp);
  return head;
 } 
     
 if(ch==3)              //Delete the left of a key
 { 

 printf("\nEnter the key value:");
 scanf("%d",&id);
 for(temp=head->rlink;(temp!=head) && (id!=temp->info); temp=temp->rlink);
 if(temp!=head)
 {
  printf("Deleted integer is : %d\n",temp->info);
   if(temp==head->rlink)
   {
     if(temp->rlink==head) /* if the list contains only one node and */
     head->rlink=head;           /* if the id match with that node */
     else
     {
      head->rlink=temp->rlink;  /* if the id matches with the value of first node*/
      (temp->rlink)->llink=head;
     }
   }

   else
     if(temp->rlink==head)  /* if the node to be deleted is the last node*/
     { pre=temp->llink;
      pre->rlink=head; 
      head->llink=pre;}
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
  } return head;
}


void display(NODE  head)
{
 NODE temp;
 if(head->rlink==head)
 {
  printf("List empty\n");
  return;
 }
 else
 {
 printf("\n CONTENTS OF THE LIST IS \n");
 for(temp=head->rlink;temp!=head;temp=temp->rlink)
 printf("%d\t",temp->info);
 }
}


main()
{
 NODE head;
 head=creat();
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
	     case 3:head=insert(head,ch);
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
	     case 3: head=del(head,ch);
	             break;
	             default: printf("Wrong entry\n");
		      
	   } break;
   case 3: display(head);
	   break;
   default:exit(0);
  }
 }
}
