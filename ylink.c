#include <stdio.h>
#include <stdlib.h>
//#include <math.h>

struct node{
	int data;
	struct node *next;
};

int lengthf(struct node *p){
	struct node *temp=p;
	int count=0;
	while(p!=NULL){
		p=p->next;
		count ++;
	}
	return  count;
}

int find_intersection(struct node *p, struct node *q){

	struct node *large=p;
	struct node *small=q;

	int l=lengthf(p);
	int s=lengthf(q);
	printf("\n%d",l);

/*	if(l<s){
		struct node *temp=large;
		large=small;
		small=large;

		int t=l;
		l=s;
		s=l;
	}
*/
    int d= l-s;

    while((l-d)>1)
    	large=large->next;
 /*   

    while((s-d)>1)
    	small=small->next;
    if((!large->data) || (!small->data))
    	return -1;

    if(large->data != small->data)
    	return -1;
    else
    	return large->data;
 */   

}

struct node *create(int n){
	struct node *temp=(struct node *)malloc(sizeof(struct node*));
	temp->data=n;
	temp->next=NULL;
	return temp;
}

main(){

	printf("f1");
	struct node *head1;//=NULL;
	head1=create(5);
	//head1=create(6);

	printf("f2");

	struct node *head2;//=NULL;
	head2=create(2);

	struct node *head3;//=NULL;
	head3=create(3);
	head3->next=create(1);

	head1->next=head3;
 	head2->next=head3;

 	int data=0;
 	data=find_intersection(head1,head2);

//	printf("%d", data);

}