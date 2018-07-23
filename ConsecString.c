#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void remove_dup( char *str, int n){
	int i,j;
	for(i=0;i<n && str[i] != '\0';i++){
		if(str[i]==str[i+1]){
			for(j=i+1; str[j] != str[i];j++);
		
		      (str+i)=(str+j);
		       i-=2;
		}      		

	}
}

main(){
	char str[]="dfaaafp";
	int n=strlen(str);
	remove_dup(str,n);
	printf("%s\n",str);
}