#include<iostream>

using namespace std;


typedef struct node node;

struct node{
	int data;
	node *next;
	//node *left;
	//node *right;
};

void insert(node **head, int key){
	if(*head==NULL){
		node *temp = new node();
		temp->data=key;
		temp->next=NULL;
		//temp->right=NULL:

		*head=temp;
		//cout<<(*head)->data;
		//return head;
	}

	else{
		node *temp=new node();
		temp->data=key;
		temp->next=*head;
        *head=temp;

	}
}

void print(node *head){
	while(head!=NULL){
		cout<<head->data;
		head=head->next;
	}
	cout<<"\n";
}

main(){
	node *head=NULL;
	insert(&head,1);
	insert(&head,2);
	insert(&head,3);

	print(head);

}