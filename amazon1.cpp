/*http://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1  */

#include <iostream>
#include <vector>
#include <stack>
#include <cstdlib>

using namespace std;

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
   cout<<node1->data<<"\t";
   node1 = node1->next;
  }
}

node *add(node *l1, node *l2){
	stack <int> s;
	int sum, rem;
	rem=0;sum=0;

	while( l1 && l2){
		sum= rem+(l1->data+l2->data);
		rem=sum/10;
		sum=sum%10;

        s.push(sum);
        l1=l1->next;
        l2=l2->next;

	}
	while(l1){
		sum=rem+l1->data;
		rem=sum/10;
		sum=sum%10;
		s.push(sum);

		l1=l1->next;

	}

	while(l2){
		sum=rem+l2->data;
		rem=sum/10;
		sum=sum%10;
		s.push(sum);

		l2=l2->next;

	}
	//cout<<s.size()<<"\n";

	int i;node *res=NULL;
	for(i=0; !s.empty();i++){
      res=push(res, s.top()) ;
      s.pop(); 
   
	}

	return res;
} 

main(){

	node *l1=NULL, *l2=NULL;

	l1=push(l1,5);
	l1=push(l1,4);
	l2=push(l2,5);

	//printList(l1);
	//printList(l2);

	node *res=add(l1, l2);

	printList(res);
	cout<<"\n";

}