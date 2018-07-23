#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int isPrime(int n){
	int i, j=sqrt(n);
	for(i=2; i<=j; i++){
		if(n%i == 0)
			return 0;
	}
	return 1;
}

int printPrime(int n){
	int count =0,i;
	for(i=2;i<=n;i++){
		if(isPrime(i))
			count+=i;
	}

	return count;
}
main(){

	printf("%d\n", printPrime(5));

}