#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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

void find(node *head, int *min, int *max, int hd){
	if(!head)
		return;
	else{
		if(*min > hd)
			*min=hd;
		if(*max < hd)
			*max=hd;

		find(head->left, min, max, hd-1 );
		find(head->right, min, max, hd+1);
	}
}

void print(node *head, int i, int hd){
	if(!head)
		return;
	if(i==hd)
		cout<<head->data<<"\t";
	
		print(head->left, i, hd-1);
		print(head->right,i,hd+1);
	
}

void verticalPrint(node *head){
	
	if(!head)
		return;

	else{
		int min=0, max=0;
		find(head, &min, &max, 0);

		int i;

		for(i=min; i <=max; i++){
			print(head,i,0);
		}
	}

}

main(){
	node *head=NULL;
	head=bstInsert(head, 5);
	head=bstInsert(head, 45);
	head=bstInsert(head, 6);
	head=bstInsert(head, 3);
	head=bstInsert(head, 4);

	verticalPrint(head);
}