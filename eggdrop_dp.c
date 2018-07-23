#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int max(int a,int b){
	if (a > b)
		return a;
	else 
		return b;
}

int eggdrop1(int n,int k){

	if(k==1 | k==0)
		return k;

	if(n==1)
		return k;
	else{

		int i;
		int res, min;
		min=99999;
		for(i=1;i<=k;i++){
         res=max(eggdrop(n-1,i-1),eggdrop(n,k-i));
         if(res<min)
         	min=res;
        }
        return min+1;
	    }
}

int eggdrop(int n,int k){
	
}

main(){

	int m=2,k=10;
	int n=eggdrop1(m,k);
	printf("\n%d\n",n);
}