//Binary Search Tree
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
 struct node *llink;
 int info;
 struct node *rlink;
 };
 typedef struct node* NODE;

 NODE getnode()
 {
  NODE x;
  x=(NODE)malloc(sizeof(struct node));
  if(x==NULL)
  {
     printf("Out of memory\n");
     exit(0);
  }
  return x;
}

void freenode(NODE x)
{
   free(x);
}

void preorder(NODE root)
{
  if(root!=NULL)
  {
     printf("%d ",root->info);
     preorder(root->llink);
     preorder(root->rlink);
  }
}
 void inorder(NODE root)
{
  if(root!=NULL)
  {

      inorder(root->llink);
      printf("%d ",root->info);
      inorder(root->rlink);


  }
}
 void postorder(NODE root)
{
  if(root!=NULL)
  {

     postorder(root->llink);
     postorder(root->rlink);
     printf("%d ",root->info);
  }
}

void display(NODE root, int i)
{
  int j;
  if(root!=NULL)
  {
    display(root->llink,i+1);
    for(j=1;j<=i;j++)
    printf(" ");
    printf("%d",root->info);
    display(root->rlink,i+1);
  }
}

NODE insert(NODE root)
{
  NODE temp,cur,prev;
  int item;
  temp=getnode();
  printf("Enter the item to be inserted\n");
  scanf("%d",&item);
  temp->info=item;
  temp->llink=temp->rlink=NULL;
 
  if(root==NULL) 
   return temp;
 
   prev=NULL;
  cur=root;
  while(cur!=NULL)
  {
    prev=cur;
    if(item<cur->info)
    cur=cur->llink;
    else
    cur=cur->rlink;
  }
  if(item<prev->info)
   prev->llink=temp;
   else
   prev->rlink=temp;
   return root;
}
NODE delete_item(int item, NODE root)
{
 NODE cur,parent,suc,q;
 if(root==NULL)
 {
  printf("\nTree is empty\n");
  return root;
 }
 parent=NULL, cur=root;
 while(cur!=NULL && item!=cur->info)
 {
  parent=cur;
  cur=(item<cur->info)?cur->llink:cur->rlink;
  }
  if(cur==NULL)
  {
   printf("Item not found\n");
   return root;
  }
  if(cur->llink==NULL)
  q=cur->rlink;
  else if(cur->rlink==NULL)
  q=cur->llink;
  else
  {
   suc=cur->rlink;
   while(suc->llink!=NULL)
    suc=suc->llink;
    suc->llink=cur->llink;
    q=cur->rlink;
    }
    if(parent==NULL)
    return q;
    if(cur==parent->llink)
      parent->llink=q;
      else
        parent->rlink=q;
        free(cur);
        return root;
 }       
      
  
NODE search(char item, NODE root)
{ 
  NODE temp;
  temp=root;
  while(temp!=NULL && item!=temp->info)
  {
  temp=(item<temp->info)?temp->llink:temp->rlink;
  }
  return temp;
  }

int main()
{
NODE root=NULL,temp;
int choice,flag;
int item;
for(;;)
{
  printf("\n1: Insert    2: Preorder\n");
  printf("3: postorder 4: Inorder\n");
  printf("5: search    6: Delete    7. exit\n");
  printf("Enter the Choice\n");
  scanf("%d",&choice);
  switch(choice)
  {
	case 1:
		
		root=insert(root);
		break;

	case 2:
		if(root==NULL)
		  printf("Tree is empty\n");
		else
		 {
		  printf("The given tree is\n");
		  display(root,1);
		  printf("\nThe preorder traversal is\n");
		  preorder(root);
		  printf("\n");
		 }
		 break;
	case 3:
		if(root==NULL)
		  printf("Tree is empty\n");
		else
		 {
		  printf("The given tree is\n");
		  display(root,1);
		  printf("\nThe postorder traversal is\n");
		 postorder(root);
		  printf("\n");
		 }
		 break;

	 case 4:
		if(root==NULL)
		  printf("Tree is empty\n");
		else
		 {
		  printf("The given tree is\n");
		  display(root,1);
		  printf("\nThe inorder traversal is\n");
		  inorder(root);
		  printf("\n");
		 }
		 break;


	 case 5:
		 if(root==NULL)
		  {printf("Tree is empty\n"); break;}
		else
		{
		  printf("Enter the item to be searched\n");
		  scanf("%d",&item);
		  temp=search(item,root);
		 if(temp==NULL)
		    printf("Search Unsuccessful\n");
		  else
		    printf("Search successful\n");
		}
		break;
         case 6:  printf("\n Enter the element to be deleted\n");
                 scanf("%d",&item);
                 delete_item(item,root);
                 break;
	 default: exit(0);
      }
    }
  }
