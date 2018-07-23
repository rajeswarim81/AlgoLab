/*Given N, count all ‘a’ and ‘b’ that satisfy the condition a^3 + b^3 = N.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains integer n.

Output:
Count all 'a' and 'b' that satisfy the above equation.*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int GetMin(int *arr, int k){
   int min=9999;
   int i;
   int mini=0;
   for(i=0;i<k;i++){
   	if(arr[i] < min){
   		mini=i;
   		min=arr[i];
   	}
   }
   return min;
}

int GetMax(int *arr, int k){
   int min=-9999;
   int mini=0;
   int i;
   for(i=0;i<k;i++){
   	if(arr[i] > min){
   		min=arr[i];
   		mini=i;
   	}
   }
   return mini;
}


int GetMinDiff(int *arr, int n, int k){
	int max=GetMax(arr,n);
	int min=GetMin(arr,n);

	if(arr[max] < k){
		arr[max]+=k;
    }
    else
    	arr[max]-=k;

    return arr[max] - arr[min] -k;
}

main(){
	int arr[]={1,5,8,10};

	int k=6;
	int n=GetMinDiff(arr,4,k);
	printf("%d\n", n);
}