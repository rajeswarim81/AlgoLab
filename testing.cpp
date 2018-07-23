#include <iostream>

using namespace std;

 struct node{
	int data;
	struct node *next;
} ;

node *insert(node *head, int n){
	if(head==NULL){
		head=new node();
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

void print(node *head){

	node *temp=head;
	//cout<<"\n";
	while(temp !=NULL){
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<"NULL"<<"\n";

}

node *delete_key(node *head, int n){

	node *temp=head;

	if(temp->data == n){
		head=head->next;
		return head;
	}

	while(temp->next->next != NULL){
		if(temp->next->data==n){
			delete(temp->next);
			temp->next=temp->next->next;
			
			return head;
		}
		temp=temp->next;
	}
    

    if(temp->next->data==n){
           delete(temp->next);
           temp->next=NULL;
           return head;
    }
    else
    	cout<<"Key not found\n";

}

int ll_length(node *head, int *count){
    if(head->next ==NULL)
    	return (*count)++;
    else{
    	(*count)++;
    	return ll_length(head->next, count);
    }

}


node *swap_xy(node *head, int x, int y){
	
	if(x==y)
		return head;
	node *prevx=NULL, *currx=head, *prevy=NULL, *curry=head;

	while(currx && currx->data != x){
		prevx=currx;
		currx=currx->next;
	}

	while(curry && curry->data != y){
		prevy=curry;
		curry=curry->next;
	}

	if(currx ==NULL || curry == NULL){
		return head;
	}

	if(prevx!=NULL)
		prevx->next=curry;
	else
		head=curry;

	if(prevy!=NULL)
		prevy->next=currx;
	else
		head=currx;

	node *temp=curry->next;
	curry->next=currx->next;
	currx->next=temp;

	return head;

}

void find_middle(node *head){
	node *slow=head,*fast=head->next;

	while(fast && fast->next){
		slow=slow->next;
		fast=fast->next->next;
	}
	cout<<slow->data<<"\n";
}

node *reverse(node *head){
	node *prev=NULL, *curr=head, *next=head->next;

	while(next){
		curr->next=prev;
        prev=curr;
		curr=next;
		next=curr->next;
	}
	curr->next=prev;
	prev=curr;

	head=prev;
	return head;

}

boolean detect_loop(node *head){

	node *slow=head, *fast=head;
	while(slow && fast && fast->next){

		if(slow->data == fast->data)
			return true;
		slow->slow->next;
		fast=fast->next->next;
	}

	return false;

}


main(){
	
   node *head=NULL;
   head=insert(head, 5);
   head=insert(head,6);
   head=insert(head, 7);
   head=insert(head,8);
   head=insert(head, 9);
   head=insert(head,10);
   print(head);
  // head=reverse(head);
   //print(head);
  // find_middle(head);
  // head=swap_xy(head, 9,6);
  // print(head);
   /*
   int count=0;
   ll_length(head, &count);

   cout<<"Length:"<<count<<"\n";
   //head=delete_key(head, 6);
   //print(head);*/
}

