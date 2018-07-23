#include <stdio.h>
#include <stdlib.h>


typedef struct node{
	int data;
	struct node *next;

}node;

node *newnode(int n){
	node *temp=(node*)malloc(sizeof(node));
	temp->data=n;
	temp->next=NULL;

	return temp;
}

node *findloop(node *head){

	if(!head || !head->next)
		return NULL;

	node *slow=head;
	node *fast=head->next;
	//printf("\n %d %d \n", slow->data, fast->data);
	while(fast){

		//printf("\n %d %d \n", slow->data, fast->data);
		if(slow->data == fast->data)
			return slow;
		else
		{
			slow=slow->next;
			fast=fast->next->next;
		}
	}
	return NULL;

}

int looplength(node *root){

	node *temp = findloop(root);
	if(!temp)
		return 0;

	node *circ=(node*)malloc(sizeof(node));
	circ=temp->next;
	int count=1;

	while(circ->data != temp->data){
		count++;
		circ=circ->next;
	}

   return count;
}

main(){

	node *head=newnode(1);
	head->next=newnode(2);
	//node **temp = &(head->next);
	head->next->next=newnode(3);
	head->next->next->next=newnode(4);
	head->next->next->next->next=newnode(5);
	head->next->next->next->next->next=head->next;

	//printf("%d",head->next->next->next->next->next->data);

    int check=looplength(head);

   // printf("\n%d\n",5);

	if(check==0)
		printf("\n NO LOOP\n");
	else
		printf("\n%d\n",check);


}