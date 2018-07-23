#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct node{
  int data;
  struct node *next;
}node;


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

node *reverse(node *head, int k){
	node *prev=NULL, *fwd=head, *curr=head;
	int i;
	for(i=0;i<k;i++){
		if(!curr)
			break;
		fwd=fwd->next;
		curr->next=prev;
		prev=curr;
		curr=fwd;
	}
    if(curr !=NULL)
	  head->next=reverse(curr,k);

	return prev;
}

main(){

  //node *head=(node*)malloc(sizeof(node));
  node *head=NULL;
  head=push(head,1);
  head=push(head,2);
  head=push(head,3);
  head=push(head,4);
  head=push(head,5);
  head=push(head,6);
  head=push(head,7);
  head=push(head,8);
  head=push(head,9);
  head=push(head,10);

  printList(head);
  printf("\n");

  head=reverse(head, 3);
  printList(head);
}