#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int count=0;

int find_disc(int *arr, int n, int i){
	if(i == n-1)
		return 0;
	else{
		int temp=arr[i];
		int min=arr[i];
		for(i=i+1;i<n;i++)
			if(arr[i] < min)
				{
					min=arr[i];
					break;
				}
        if(temp==min)
        	return 0;
        else
		    return min;
	}

}
void disc(int *arr, int size,int n){

if(size==0)
	return ;
if(n==1)
	printf("%d\n%d", arr[0], arr[0]);
else
{
	int total =0;
	int i,d,disc[n];
	for(i=n-1;i>=0;i--){
		d=find_disc(arr,size,i);
		if(d==0){
			//(disc+count)=(int*)malloc(sizeof(int));
			 disc[count++]=arr[i];
		}

		total += arr[i]-d;



	}

	printf("\n%d\n", total);
	for(i=count-1 ; i>=0;i--)
		printf("%d\t", disc[i]);
}

}

main(){
	printf("\nEnter the number of elements and the array:\t");
	int n;
	scanf("%d", &n);
	int arr[n],i;

	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
    }

    disc(arr,n,n);

}