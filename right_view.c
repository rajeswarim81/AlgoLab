#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
	struct node *nextright;
}node;

node *newNode(int n){
	node *temp=( node*)malloc(sizeof(node));
	temp->data=n;
	temp->left=NULL;
    temp->right = NULL;
    temp->nextright=NULL;

	return temp;
}

void print(node *root, int level, int *maxlevel){

	if(root == NULL)
		return;
	if(level > *maxlevel)
	{
		printf("\n%d\n", root->data);
		*maxlevel = level;

	}

	print(root->right, level +1, maxlevel);
	print(root->left, level+1,maxlevel);

}

void rightview(node *root){
	int maxlevel=0;
	print(root, 1, &maxlevel);
}
main(){
	node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->right->left  = newNode(6);
    root->right->right = newNode(7);
    root->left->right->right=newNode(11);

    //level_traverse(root,0);

    rightview(root);
    void free();
}