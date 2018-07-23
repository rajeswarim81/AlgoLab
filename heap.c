#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int heap[100], n; //heap array, number of nodes

int insert(int num)
{
  
  if(n==100)
  {
  	printf("\nOVERFLOW");
  	return;
  }	

  int i= n;
  int temp;
  heap[++i]=num;
  n++;

  while(i)
  {
      if(heap[i] < heap[i/2])  // i/2 refers to the parent node
      {
          temp = heap[i/2];
          heap[i/2] = heap[i];
          heap[i] = temp;
      }

      i=i/2;
  }
  
  return;
}

int traverse()
{
	int i=n;
	if(n==0)
	{
		printf("\nUNDERFLOW");
		return;
	}
	printf("\n");
	while(i)
	{
        printf("%d\t",heap[n-i+1]);
		i--;
	}
	return;
}

void findmin()
{
	printf("\nThe minimum element is:\t%d", heap[1]);
}

void delete()
{
	//int i=n;
	heap[1] = heap[n];
	n--;
	heapify(1);

}



int heapify(int p)
{   
	static int count=0;
	count++;
	if(count-1 == (int)(log(n)/log(2)))
	{
		return;
	}
  int i= p;
  int temp;
  int j=(heap[2*i] < heap[2*i+1] ? 2*i : 2*i+1);
  if(heap[i] > heap[j])
  {
     temp= heap[i];
     heap[i]=heap[j];
     heap[j]=temp;
  }
  
  heapify(j);
  
}


main()
{
	n=0;
	heap[0]= -9999;
    int choice,no;
 while(1)
 {
 	printf("\nEnter choices:\n1.Insert\n2.Delete\n3.Traverse\n4.Find min\n5.Exit\n");
 	scanf("%d", &choice);
 	switch(choice)
 	{
 		case 1: printf("\nEnter the number:\t");
 		        scanf("%d", &no);
 		        insert(no);
 		        break;

 		case 2: delete();
 		        break;

 		case 3: traverse();
 		        break;

 		case 4: findmin();
 		        break;        

 		case 5: return; 
 		        break;

 		default: printf("\nInvalid choice!!");        

    }
 }
}