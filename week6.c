#include<stdlib.h>
#include<stdio.h>


#include<stdio.h>
#include<stdlib.h>

struct list
{
 int data;
 struct list *next;
 struct list *prev;
}*head;

void push(int data)
{
  struct list *temp=(struct list *)malloc(sizeof(struct list));
 if(head==NULL)
  {
  	temp->data=data;
  	temp->next=NULL;
  	temp->prev=NULL;
  	head=temp;
    /*temp->next=head;
    head=temp;
    temp->data=data;
    temp->prev=NULL;*/
  }
  
 else
 {
  
  temp->data=data;
  temp->next=head;
  head=temp;
  temp->next->prev=temp;
  //free(temp);
 }
}

void pop()
{
 if(head==NULL)
  return;
  
 else
 {
  //struct list *temp=head;
 // temp=top;
 // head->next->prev=NULL;
  head=head->next;
  head->prev=NULL;

  //free(temp);
 } }

 int traverse(int j)
 {
  int i;
  if(head==NULL)
  	return;
  struct list *temp=head;
  for(i=0;i<j;i++)
  {
     temp=temp->next;
  }
  return temp->data;
 }

 int length()
 {
   struct list *temp=head;
   int count=0;
   while(temp!=NULL)
   {
    count++;
    temp=temp->next;
   }
   return count;
 }

 void printpath(int j)
 {
   int i=j;
   struct list *temp=head;
   for(i=0;i<j;i++)
   {
     temp=temp->next;
   }
   printf("\nPath:");

  while(temp!=NULL)
   {
    printf("%d-->",temp->data);
    temp=temp->prev;
   }
   printf("NULL");
   printf("\n");

 }


//declare the structure
struct bt
{
 int data;
 struct bt *left;
 struct bt *right;
};

//function to print the constructed tree inorder
//void printtree(struct bt *node);

//function to create a new node
struct bt *create(int x)
{
 struct bt *node=(struct bt *)malloc(sizeof(struct bt));\
 node->data=x;
 node->left=NULL;
 node->right=NULL;
 
 return node;
}

//function to search a data in inorder array
int search(int *a, int data, int l,int r)
{
 int i=0;
 for(i=l;i<=r;i++)
 {
  if(a[i]==data)
   return i; 
 }
 
 
}

void printtree(struct bt *node);

//function to construct the binary tree
struct bt *reconBinTree(int *in,int *pre, int l, int r)
{
 static int index=0;
 if(l>r)
 {
 	//printf("\nFound a leaf at:\t %d",new->data);
  return NULL;
  }
  
 struct bt *new=create(pre[index++]); 
 
 if(l==r)
  return new;
  
  
 int indexi=search(in, new->data, l, r); 
  
 new->left=reconBinTree(in,pre,l,indexi-1);
 new->right=reconBinTree(in, pre, indexi+1,r);
 
 printf("\nFound a node at:\t");
 
 printf("%d", new->data);
 printf("\tLeft child:\t %d",new->left->data);
 printf("\tRight child:\t %d",new->right->data);

// if((new->left==NULL) /*&& (new->right==NULL)*/)
 //	printf("\nFound a leaf at:\t %d",new->data);

printf("\n"); 
printf("The corresponding sub-tree traversed inorder:\n");
printtree(new);
printf("\n");
 
  return new;
}


//function to print the tree inorder
void printtree(struct bt *node)
{
 if(node==NULL)
  return;

 printtree(node->left);
 printf("\t%d", node->data);
 printtree(node->right); 

}


void enumSumPaths(struct bt *root, int k)
{
  if(root==NULL)
    return;

  push(root->data);
  enumSumPaths(root->left,k);
  enumSumPaths(root->right,k);

  int sum=0,j;
  for(j=0;j<length();j++)
  {
     sum+=traverse(j);
     if(sum==k)
      printpath(j);
  }
pop();

}

//main function
void main(int argc, char *argv[])
{
 int v=atoi(argv[1]);
 printf("%d",argc);
 
 head=NULL;
 int n;
 printf("\nEnter the number of elements in the binary tree:\t");
 scanf("%d",&n);
 
 int pre[n];
 int in[n];
 int i=0; 
 
 printf("\nEnter the preorder traversal:\t");
/* do
 {
  scanf("%d",);
 }while(pre[i]!='\n');*/
 for(i=0;i<n;i++)
 {
  scanf("%d",&pre[i]);
 }

 printf("\nEnter the inorder traversal:\t");
  for(i=0;i<n;i++)
 {
  scanf("%d",&in[i]);
 }

struct bt *root_node=reconBinTree(in, pre,0,n-1);

printf("\n****************BINARY TREE*****************");
printf("\nThe constructed tree traversed inorder:\n");
printtree(root_node);
printf("\n");

enumSumPaths(root_node,v);

}

