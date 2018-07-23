#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct list{
	int data;
	struct list *next;
}node;

node *create(node *head, int data){

	if(!head){
		head->data=data;
		head->next=NULL;
	}

	node *temp=(node*)malloc(sizeof(node));
	temp->data=data;
	temp->next=head;
	head=temp;

	delete(temp);
	return head;

}

main(){

	node *head=NULL;
	head=create(head,9);
	head=create(head,19);
	head=create(head,92);
	head=create(head,29);
	head=create(head,39);

	head=reverse(head);


}