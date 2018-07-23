#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int isPalindrome(char *arr, int i, int j){
	if(i>=j)
		return 1;
	if(arr[i] != arr[j])
		return -1;
	else
		return isPalindrome(arr, i+1, j-1);
}

void print(char *arr, int n){
	
		int i,j,k;
		for(i=1;i<=n;i++){

			for(j=0;j<=n-i;j++){
				//printf("%d",j);

				if( isPalindrome(arr,j,j+i-1)==1 ){

					for(k=j; k<=j+i-1; k++)
						printf("%c",arr[k]);
					printf("\n");
				}
			}
		}

    
}

main(){
	char arr[]="nitin";
	//printf("%d\n", isPalindrome(arr,0,4));

	int n=sizeof(arr)/sizeof(char)-1;
	//printf("%d",n);
	print(arr,n);
}