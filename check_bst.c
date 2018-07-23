/**/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node *create(int n){
	node *temp=(node*)malloc(sizeof(node));
	if(!temp){
		printf("\nError");
	    return NULL;
	}
	temp->data=n;
	temp->left=NULL;
    temp->right = NULL;
	return temp;
}

int max(int a, int b){
	if(a>b)
		return a;
	else
		return b;
}


int min(int a, int b){
	if(a<b)
		return a;
	else
		return b;
}

int maxvalue(node *head){
	if(!head)
		return -9999;
	if( !head->left && !head->right){
		return head->data;
    }

    return max(max(head->data,maxvalue(head->left)), maxvalue(head->right));
}

int minvalue(node *head){
	if(!head)
		return 9999;
	if( !head->left && !head->right){
		return head->data;
    }

    return min(min(head->data,minvalue(head->left)), minvalue(head->right));
}

int check_bst(node *head){

	if(!head)
		return -1;

	if(!head->left && !head->right)
		return 1;

	if((head->left != NULL) && maxvalue(head->left) > head->data)
	     return 0;

	if((head->right != NULL) && minvalue(head->right) < head->data)
	     return 0;

	if( !check_bst(head->left) || !check_bst(head->right))
		return 0;
	else
		return 1;
    
}


main(){
	node *head=create(8);
	head->left=create(5);
	head->right=create(13);
	head->left->right=create(6);
	//head->right->left=create(7);

	int n=check_bst(head);
	printf("\n%d \n",n);

}