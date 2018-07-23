#include <iostream>

using namespace std;

struct node{
	int data;
	struct node *next;
} *head;

node *insert(int n){
	if(head==NULL){
		head->data=n;
		head->next=NULL;

		return head;
	}


	node *temp=new node();
	temp->data=n;
	temp->next=head;
	head=temp;

	return head;

}

main(){
	
    head=NULL;
	head=insert(5);
	head=insert(6);
	head=insert(7);
}

