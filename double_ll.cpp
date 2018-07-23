#include<iostream>

using namespace std;

typedef struct node{
	int data;
	struct node *next;
	struct node *prev;
}node;

node *head;

void push(int i){

	node *temp = new node();
	if(!head){
		temp->data=i;
		temp->next=NULL;
		temp->prev=NULL;

		head=temp;
		return;
      }

      
      temp->data=i;
	  temp->next=head;
	  head->prev=temp;
	  temp->prev=NULL;
	  head=temp;

}

void print(){
	node *temp =new node();
	temp=head;
	while(temp!=NULL){
		cout<<temp->data;
		temp=temp->next;
	}
}

 void delete_node(int k){
	node *temp=new node();
	node *back=new node();
	node *fwd=new node();

	temp=head;
	back=NULL;
	//fwd=head->next;
	int count=0;

	while(count<k-1){
		back=temp;
		fwd=temp->next->next;
		temp=temp->next;
		count++;
	}

	back->next=fwd;
	fwd->prev=back;
	delete(temp);


}

main(){
	head=NULL;
     
    int i;
	for(i=0;i<6;i++){
		push(i);
	}
    
    print();
    cout<<"\n";
    delete_node(3);
    print();
    cout<<"\n";


}