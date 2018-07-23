#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct node{
	int data;
	struct node *next;
}node;

node *head; 

void push(int i){

    struct node *temp = (node*) malloc(sizeof(node*));
	temp->data=i;

	if(head==NULL){
		head=temp;
		head->next=NULL;
		return;
	}

	//struct node *temp = (node*) malloc(sizeof(node*));
	//temp->data=i;
	temp->next=head;
	head=temp;
}

void print(){
	struct node *temp=(node*) malloc(sizeof(node*));
	temp=head;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	return;
}

void rotate(int k){
	if( (!k) || (!head))
		return;
	/*if(!head)
		return;
*/
	int count=0;

	struct node *current=(node*) malloc(sizeof(node*));
	current=head;

	while(count<k && current!=NULL){
		current=current->next;
		count++;
	}

	if(current==NULL)
		return;
    
    struct node *knode=(node*) malloc(sizeof(node*));
    knode=current->next;
    current->next=NULL;
    struct node *temp=(node*) malloc(sizeof(node*));
   // node *prev = (node*) malloc(sizeof(node*));

    temp=head;
    head=knode;
    current=head;
   

    while(current->next != NULL)
    	{
    		//prev=current;
    		current=current->next;
    	}

    current->next=temp;
	 
}

void main(){

	head=NULL;

	int i;

	for(i=0;i<6;i++){
		push(i);
	}
	print();
	printf("\n");

	rotate(2);
	print();
  

}
