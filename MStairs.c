#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int stairs(int n, int m){
	
 if(n <=1)
		return n;
	
		int i;
		int res=0;
		for(i=1;i <=m && i<=n;i++){
			res+=stairs(n-i,m);
		}
		return res;
	
}

main(){

	int n=4;
	int m=2;
	int p=stairs(n+1,m);
	printf("%d\n", p);
}