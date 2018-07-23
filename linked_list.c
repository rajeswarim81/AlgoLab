#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct List{
	int data;
	struct list *next;
}list;

list *head,*tail,*temp;

void insert(int n)
{
	temp=(list*)malloc(sizeof(list));
	temp->data=n;
	if(head==NULL){
		head=temp;
		head->next=NULL;
		tail=head;
	}

	else{
		tail->next=temp;
		tail=temp;
		tail->next=NULL;
    }

}

void delete(){
	if(head==NULL){
		return;
	}

	else if(head==tail){
		head=NULL;
		tail=head;
	}
	else{
		head=head->next;
	}
}

void traverse(){
	if(head==NULL){
		return;
	}
	else{
		temp=head;
		while(temp!=NULL){
			printf("%d->",temp->data);
			temp=temp->next;
		}
	}
}


main()
{
  list *l1;
  head=NULL;
  tail=NULL;
  temp=NULL;

  int n, data;

  printf("1.INSERT\n2.DELETE\n3.TRAVERSE\n4.QUIT\n");
  scanf("%d",&n);

  switch(n)
  {
  	case 1:
  	  printf("\nEnter data:\t");
  	  scanf("%d",&data);
  	  insert(data);
  	  break;

  	case 2:
  	  delete();
  	  break;

  	case 3:
  	  traverse();
  	  break;

  	case 4:
  	  return;
  }
  //l1 = newnode(5);

}