#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int sub_str(char *s, char *x){
	int len=strlen(s);
	int i=0;

	for(i=0;i<len;i++){
		if(s[i] == *x)
			x=x+1;
	}
	if(*x == '\0')
		return 1;
	else 
		return 0;
}
main(){

	char s[]="abcde";
	char x[]="bcbd";
	int n=sub_str(s,x);
	printf("%d",n);

}