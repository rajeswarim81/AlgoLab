#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct ll{
  int data;
  struct ll *next;
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

int find_middle(node *head){
  node *slow, *fast;
  slow=head;
  fast=head;
  int s=0, f=0;

  while(fast->next != NULL){
    fast=fast->next; f++;
    printf("\nFast is at %d \n", f);
    if(fast->next !=NULL)
    {
      slow=slow->next;s++;
      fast=fast->next;f++;

       printf("\nSlow is at %d \n", s);
        printf("\nFast is at %d \n", f);
    }
  }

  printf("\n%d %d\n", s, f);

  return slow->data;
}

main(){
  node *head=(node*)malloc(sizeof(node));
  head=NULL;
  head=push(head,5);
  head=push(head,156);
  head=push(head,7);
  head=push(head,79);
  head=push(head,1);
  head=push(head,12);
  printList(head);
    printf("\n%d\n", find_middle(head));

}