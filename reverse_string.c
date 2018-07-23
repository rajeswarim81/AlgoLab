/**/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void reverse(char *arr, int i, int j){
	if(i==j)
		return;
	//printf("%d", i);

	char temp;

	while(i<=j){
		temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
		i++;
		j--;
    }
}

void reversedots(char *str, int n){

	reverse(str,0,n-1);
	printf("\n%s\n",str);
	int count=0,i;

	for(i=0;i<n;i++){
		if(str[i] != '.'){
			count++;
		
		//printf("%d",count);
	}
		else{
			reverse(str,i-count,i-1);
			count=0;
		}

	}


}
main(){
	char str[]="i.love.dogs";
	//printf("\nEnter dot separated strings: ");
	//int i;
	//scanf("%s", str);
	
	//reversedots(str,strlen(str));
	int t=strlen(str);
	//printf("%d\n",t);
	reversedots(str,t);
	printf("%s\n", str);
}