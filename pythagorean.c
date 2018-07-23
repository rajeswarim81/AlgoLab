#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int *stockspan(int *s,int *arr, int n){
	//int s[n];
	s[0]=1;
    
    int i,j;
	for(i=1;i<n;i++){
			s[i]=1;
			for(j=i-1; (j>=0) && (arr[j] < arr[i]);j--)
               s[i]++;
    }

    return s;
}

main(){
	int arr[]={10, 4, 5, 90, 120, 80};
	int n=sizeof(arr)/sizeof(int);

	int *r=(int *)malloc(sizeof(int));
	r=stockspan(r,arr,n);

	int i;

	for(i=0;i<n;i++)
		printf("%d\t", r[i]);

	printf("\n");
}