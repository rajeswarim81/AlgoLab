/*#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<string.h> */
#include<iostream>
#include<climits>
#include<cmath>
#include<cstring>

using namespace std;

//int heap[100];
static int n, heap[100];
void heapify(int);

void swap(int *a, int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

void insert(){
	int m;
	cout<<"\nEnter the number you want to enter:\t";
	cin>>m;

	n++;
	if(n==100){
		cout<<"overflow";
		return;
	}

	int i=n;
	heap[i]=m;

	while(i){
		if(heap[i]<heap[i/2]){
			swap(&heap[i],&heap[i/2]);
		}
		i=i/2;
	}
	return;
}


void delete_min(){

	heap[1]=heap[n];
	n--;
	heapify(1);
}

void heapify(int i){

	int h= (int)((log(n))/(log(2)));
	static int count=0;
	//cout<<"count="<<count;
	
	if(count==h)
		return;
    count++;

	int l=2*(i);
	int r=2*(i)+1;

	int j=(heap[l]<heap[r] ? l : r);

	if(heap[j]<heap[i]){
		swap(heap[j], heap[i]);
	}
	heapify(j);
   
   // count--;
}

void traverse(){
	int i=1;
	cout<<"\n";
	while(i<=n){
		
		cout<<"\t"<<heap[i];
		i++;
	}
}


main()
{
	n=0;
	heap[0]= INT_MIN;
	int choice;

    cout<<"***********MIN HEAP***********\n";


	while(1){
		
		cout<<"\nEnter choices:\n1.Insert\n2.Delete\n3.Traverse\n4.Exit\n";
		cin>>choice;

		switch(choice){
			case 1:
			  insert();
			 // cout<<heap[1];
			  break;
			case 2:
			  delete_min();
			break;

			case 3:
			traverse();
			break;

			case 4:return 0;

			default:
			 cout<<"\nWrong choice!!";
		}
	}
}