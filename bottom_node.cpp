#include <iostream>
using namespace std;


struct node{

int data;
struct node *next;
struct node *bottom;
};

node *create(int k){
	node *temp= new node;
	temp->data=k;
	temp->next=NULL;
	temp->bottom=NULL:

	return temp;
}

struct stack{
int data;
struct stack *next;
};

stack *create_stack(int n){

	stack *temp=new stack;
	temp->data=n;
	temp->next=NULL;

	return temp;
}

void push(stack *top, int n){
    if(top==NULL){
	  top=create_stack(n);
	  return;
    }
    else{
    	node *temp=create_stack(n);
    	temp->next=top;
    	top=temp;
    }
}

void pop(stack *top){
	if(top==NULL)
		return;
	else{
		node *temp=top;
		top=top->next;
		delete(temp);
	}
}
void print(node *head){
	node *temp=head;
	node **stackheads;
	int i=0;
	while(temp!=NULL){
		*stackheads[i]=temp;
		 push(*stackheads[i])


	}

}

main(){

	struct node* head;
	head=create(7);
	head->bottom=create(8);
	head->bottom->bottom=create(30);

	head->next=create(10);
	haed->next->bottom=create(20);

	head->next->next=create(19);
	head->next->next->bottom=create(22);
	head->next->next->bottom->bottom=create(50);

	print(head);
	


}