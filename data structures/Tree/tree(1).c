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
  char direction[10];
  int item;
  int i,n;
  temp=getnode();
  printf("Enter the item to be inserted\n");
  scanf("%d",&item);
  temp->info=item;
  temp->llink=temp->rlink=NULL;
  if(root==NULL) return temp;
  printf("\n Enter the direction\t");
  scanf("%s",direction);
  prev=NULL;
  cur=root;
  for(i=0;(i<strlen(direction) && cur!=NULL);i++)
  {
    prev=cur;
    if(direction[i]=='l')
    cur=cur->llink;
    else
    cur=cur->rlink;
  }
  if(cur!=NULL || i!=strlen(direction))
  {
    printf("Insertion not possible\n");
    freenode(temp);
    return root;
  }
  if(direction[i-1]=='l')
  prev->llink=temp;
  else
  prev->rlink=temp;
  return root;
}

void search(int item, NODE root)
{ int flag=0;
 while(root!=NULL)
 {
   search(item,root->llink);
   if(item==root->info)
   {
     flag=1;
     return;
   }
   search(item,root->rlink);
 }
  if(flag)
  {
    printf("Search Successful!!\n");
    }
}

int main()
{
NODE root=NULL;
int choice,flag;
int item;
for(;;)
{
  printf("\n1: Insert    2: Preorder\n");
  printf("3: postorder 4: Inorder\n");
  printf("5: search    6: exit\n");
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
		  flag=0;
		  search(item,root);
		/*  if(flag==1)
		    printf("Search successful\n");
		  else
		    printf("Search unsuccessful\n");*/
		}
		break;

	 default: exit(0);
      }
    }
  }
