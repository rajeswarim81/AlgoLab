/**/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int minjumps(int *arr, int i, int j){
	if(i == j)
		return 0;
	if(arr[i] == 0)
		return 9999;
	if(arr[i]==1)
		return 1+minjumps(arr+1,i,j);
	else{
		int k;
		int min=9999;int p;
		for(k=i+1; k<=j && k<= arr[i]; k++){
			p=minjumps(arr,k,j);
			if( p !=9999 && p<min)
				min=p+1;


		}
		return min;

          
	}
}
main(){


	printf("\nEnter size and arrray: ");
	int n;
	scanf("%d", &n);
	int i; int arr[n];
	for(i=0;i<n;i++){
		scanf("%d", &arr[i]);
	}

	int nm=minjumps(arr,0,n);
	printf("%d\n",nm);
}