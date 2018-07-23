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

int hasPathSum(node *head, int sum){
	if(!head)
		return 0;
	if(head->data > sum)
		return 0;
	if( !head->left && !head->right && (head->data==sum))
		return 1;
	else
	   return(hasPathSum(head->left,sum-head->data) || hasPathSum(head->right,sum-head->data));
}

main(){
	node *head=create(8);
	head->left=create(5);
	head->right=create(13);
	head->left->right=create(6);
	head->left->left=create(1);
	//head->right->left=create(7);

	int n=hasPathSum(head,14);
	printf("\n%d \n",n);

}