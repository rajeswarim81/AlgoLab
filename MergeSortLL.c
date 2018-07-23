#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct ll{
	int data;
	struct ll *next;
}node;

//node *head=NULL:

node *push(node *head, int n){
	node *temp=(node*)malloc(sizeof(node));
	temp->data=n;
	temp->next=head;
	head=temp;

    return head;
}

void printList(node *node1)
{
  while(node1!=NULL)
  {
   printf("%d ", node1->data);
   node1 = node1->next;
  }
}

void split(node *head, node **a, node **b){
	node* slow, *fast;

	if(!head || !head->next){
		*a=head;
		*b=NULL;

		return ;
	}

    else{
	  slow=head;
	  fast=head->next;

	  while(fast){
		fast=fast->next;
		while(fast){
			fast=fast->next;
			slow=slow->next;
		}
	  }

	  *a=head;
	  *b=slow->next;
	   slow->next=NULL;
    }
}

node *sorted_merge(node *a, node *b){
	if(!a && !b)
		return a;
	else if(!a)
		return b;
	else if(!b)
		return a;
	else{
		node *result=NULL;
		if(a->data > b->data){
			result=a;
			result->next=sorted_merge(a->next,b);
		}
		else if(a->data < b->data){
			result=b;
			result->next=sorted_merge(a,b->next);
		}

		else{
			result=a;
			result->next=sorted_merge(a->next,b->next);

		}
		return result;
	}
}

node *mergesort(node *head){
	if(!head || !head->next)
		return head;

	node *a, *b;

	split(head, &a, &b);

    a=mergesort(a);
    b=mergesort(b);

    head=sorted_merge(a,b);
    return head;
}

main(){

	node *head=(node*)malloc(sizeof(node));
	head=NULL;
	head=push(head,5);
	head=push(head,10);
    head=push(head,7);
    head=push(head,79);
    head=push(head,1);

    head=mergesort(head);

    printList(head);
}