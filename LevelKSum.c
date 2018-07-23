#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
	struct node *nextright;
}node;

struct node *newNode(int n){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=n;
	temp->left=NULL;
    temp->right = NULL;
    temp->nextright=NULL;

	return temp;
}

int LevelSum(node *root, int i, int k){
	int count=0;
	if(!root)
		return 0;
	
	if(i == k)
		count+=root->data;
	else{
		count+=LevelSum(root->left,i+1,k);
		count+=LevelSum(root->right, i+1,k);

		return count;
	}

}

main(){
	struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->right->left= newNode(11);
    root->left->right = newNode(5);
     
    int k=2;
    int n=LevelSum(root,0,k);

    printf("%d\n",n);
}