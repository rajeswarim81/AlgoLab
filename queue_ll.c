
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct LinkedList{
  int data;
  struct LinkedList *next;
}node;

node *head, *tail;

node *newNode(int n){
  node *temp=(node*)malloc(sizeof(node));
  temp->data=n;
  temp->next=NULL;

  return temp;
}
void insert(int n){
  if(!head){
    head=newNode(n);
    tail=head;
    return;
  }

  node *temp=newNode(n);
  tail->next=temp;
  tail=temp;
  //delete(temp);
}

void delete(){
  if( !head)
    return ;
  else{

    int data=head->data;
    head=head->next;
   // return data;
  }
}

void traverse(){
  node *temp=head;
  while(temp != NULL){
    printf("%d\t", temp->data);
    temp=temp->next;
  }
}
main(){
  head=NULL;
  tail=NULL;
  insert(1);
  insert(2);
  insert(3);
  traverse();
  delete();
  traverse();

}