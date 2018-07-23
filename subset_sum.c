/*Given a set of numbers, check whether it can be partitioned into two subsets such that the sum of elements in both subsets is same or not.

Input:The first line contains an integer 'T' denoting the total number of test cases. Each test case constitutes of two lines. First line contains 'N', representing the number of elements in the set and the second line contains the elements of the set.
Output: Print YES if the given set can be partioned into two subsets such that the sum of elements in both subsets is equal, else print NO.*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void merge(int *arr, int i,int m, int j){
	int n1=m-i+1;
	int n2=j-m;

	int p,q;
	int l[n1],r[n2];
	for(p=0;p<n1;p++)
		l[p]=arr[i+p];
	for(p=0;p<n2;p++)
		r[p]=arr[m+p];
    
    p=0; q=0;

    int k=i;

    while(p<n1 && q<n2){
    	if(l[i] < r[j])
    		arr[k++]=l[i++];
    	else if(l[i] > r[j])
    		arr[k++]=r[i++];
    	else{
    		arr[k++]=l[i++];
    		j++;
    	}

    }

    if(i<n1){
    	while(i<n1)
    	  arr[k++]=l[i++];
    }
    

    else{
    	while(j<n2)
    		arr[k++]=r[j++];
    }
    
}

void traverse(int *arr, int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");
}

void merge_sort(int *arr, int i, int j){
	if(i<j){
		int m=(i+j)/2;
		merge_sort(arr,i,m);
		merge_sort(arr,m+1,j);
		merge(arr,i,m,j);
	}

}
int subset(int *arr,int n){
	
}

main(){
	printf("\nEnter array size and the array:\n");
	int n;
	scanf("%d", &n);
	int i,arr[n];
	for(i=0;i<n;i++)
		scanf("%d", &arr[i]);

	//int subset(arr,n);
	merge_sort(arr,0,n-1);
	traverse(arr,n);
	
}