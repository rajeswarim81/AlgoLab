#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node{
	int data;
	struct node *next;
}node;

int length(node *p){
	node *temp=p;
	int count=0;
	while(p!=NULL){
		p=p->next;
		count ++;
	}
	return  count;
}

int find_intersection(node *p, node *q){

	node *large=p;
	node *small=q;

	int l=length(p);
	int s=length(q);

	if(l<s){
		node *temp=large;
		large=small;
		small=large;

		int t=l;
		l=s;
		s=l;
	}

    int d= l-s;

    while((l-d)>0)
    	large=large->next;
    

    while((s-d)>0)
    	small=small->next;

    if(large->data == small->data)
    	return large->data;
    else 
    	return -1;

}

struct node *create(int n){
	node *temp=(node *)malloc(sizeof(node*));
	temp->data=n;
	temp->next=NULL;
	return temp;
}

main(){
	node *head1=NULL;
	head1=create(5);
	head1->next=create(6);

	node *head2=NULL;
	head2=create(2);

	node *head3=NULL;
	head3=create(3);
	head3->next=create(1);

	head1->next->next=head3;
	head2->next=head3;

	printf("%d", find_intersection(head1,head2));

}