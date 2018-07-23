#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
	struct node *nextright;
};

struct node *newNode(int n){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=n;
	temp->left=NULL;
    temp->right = NULL;
    temp->nextright=NULL;

	return temp;
}

int max(int a,int b){
	if(a>b)
		return a;
	else
		return b;
}

int height(struct node *root){
	if(root==NULL)
		return 0;
	else{
		int l=height(root->left);
		int r=height(root->right);

		int h=max(l,r);
		return h+1;
	}
}

void traverse(struct node *root, int n, int rem){

	if(root==NULL)
		return;
	if(n==0)
		printf("%d",root->data);
	else if(rem==1)
		{
			traverse(root->left,n-1,rem);
	        traverse(root->right,n-1,rem);
        }
        else{
        	traverse(root->right,n-1,rem);
	        traverse(root->left,n-1,rem);

        }
}

void level_traverse(struct node *root, int n){
	int h=height(root);
	int i;
	for(i=0;i<h;i++){

		traverse(root,i,i%2);
    }

}

main(){
	struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->right->left  = newNode(6);
    root->right->right = newNode(7);

    level_traverse(root,0);
    void free();
}