/*Given a sorted and rotated array (rotated at some point) A[ ], and given an element K, the task is to find the index of the given element K in the array A[ ]. The array has no duplicate elements. If the element does not exist in the array, print -1.
 

Input:
The first line of the input contains an integer T, depicting the total number of test cases. Then T test cases follow. Each test case consists of three lines. First line of each test case contains an integer N denoting the size of the given array. Second line of each test case contains N space separated integers denoting the elements of the array A[ ]. Third line of each test case contains an integer K denoting the element to be searched in the array.


Output:

Corresponding to each test case, print in a new line, the index of the element found in the array.  If element is not present, then print -1.*/





#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void reverse(int *arr, int i, int j){
	int temp;
	while(i<=j){
		int temp= arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
		i++;
		j--;

	}
}
void rotate(int *arr, int n, int p){
	p=p%n;

	reverse(arr,0,p-1);
	reverse(arr,p,n-1);
	reverse(arr,0,n-1);

}

void traverse(int *arr, int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d\t", arr[i]);
	}
	printf("\n");
}

int find_k(int *arr,int n){
	int i;
	for(i=0;i<n-1;i++){
		if(arr[i+1] < arr[i])
			return i+1;
	}
}
int bin_search(int *arr, int i, int j, int key){
	if(i>j)
		return -1;
	else{
		int m=i+(j-i)/2;
		if(arr[m] == key)
			return m;
		else if(key < arr[m])
			return bin_search(arr,i,m,key);
		else
			return bin_search(arr,m+1,j,key);
	}
}

int search(int *arr,int n, int key){
	int k=find_k(arr,n);
	if(key<arr[0])
		return bin_search(arr,k,n-1,key);
	else
		return bin_search(arr,0,k-1,key);
}

main(){
	printf("\nEnterthe number of elements and the sorted array:\n");
	int n;
	scanf("%d", &n);
	int arr[n],i;

	for(i=0;i<n;i++)
		scanf("%d", &arr[i]);
	int k;
	printf("\nEnter the rotation factor:\t");
	scanf("%d", &k);

	rotate(arr,n,k);

	traverse(arr,n);

	printf("\nEnter the element to b searched:\t");
	int m;
	scanf("%d", &m);

	int nm=search(arr,n,m);
	printf("Index: %d\n", nm);
	

	
}