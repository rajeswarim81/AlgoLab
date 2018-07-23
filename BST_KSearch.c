#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

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

node *bstInsert(node *head, int n){
	if(!head){
		head=newNode(n);
		return head;
	}
	else{
		if(n == head->data)
			return head;
		else if(n < head->data)
			head->left=bstInsert(head->left, n);
		else
			head->right=bstInsert(head->right, n);

		return head;
	}
}

main(){
	node *head=NULL;
	head=bstInsert(5);
	head=bstInsert(45);
	head=bstInsert(6);
	head=bstInsert(3);
	head=bstInsert(4);

	int n=ksearch(head,2);
}