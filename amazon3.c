#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int FindSum(int *arr, int n, int k){
	int i=0;
	int count=0;
	int flag= -1; int ans=0;

    for(i=0;i<n;){
    	count=0;
    	flag=-1;

    	while(arr[i] <=k){
    		count++;
    		if(arr[i] == k)
    			flag=1;
    		i++;
    	}

    	if(flag)
    		ans+=count;

    	while(arr[i] >k)
    		i++;
    }

	return ans;
}


main(){
	printf("\nEnter size and the array:");
	int n;
	scanf("%d\n", &n);

	int i; int arr[n];
	//int *arr=(int *)malloc(sizeof(int));
	for(i=0;i<n;i++){
		scanf("%d", &arr[i]);
		//printf("%d\n", arr[i]);
	}

	/*for(i=0;i<n;i++){
		printf("%d\n", arr[i]);
		//printf("%d\n", arr[i]);
	}*/

	int m=FindSum(arr, n, 3);
	printf("\n%d\n",m);
	

}