#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void MinWindow(char *x, char *y){
	int xlen=strlen(x);
	int ylen=strlen(y);

	int hashx[26], hashy[26];
	int i;

	for(i=0;i<26;i++){
		hashx[i]=0;
		hashy[i]=0;
	}

	for(i=0;i<ylen;i++){
		hashy[ y[i]-'a']++;
	}

    char *res=(char *)malloc(sizeof(char));
    int j=0; 
    int start=0, window=10000, flag=-1; int count=0;
	for(i=0;i<xlen;i++){
		hashx[x[i]-'a']++;

		if(hashy[x[i]-'a'] && (hashx[x[i]-'a'] <= hashy[x[i]-'a'])) //do count++ for only one appearance of the literal
			count++;

		if(count == ylen){
			flag=1;

		while(hashy[ x[start]-'a' ]==0 || hashx[ x[start]-'a'] > hashy[ x[start]-'a']){
			hashx[ x[start]-'a']--;
			start++;
		}

		if( i-start < window)
			window= i-start;
		
	
		}
    }

    if(flag == -1)
    	printf("-1");
    else
    {
    	for(i=start-1; i<= start+window-1; i++)
    		printf("%c\t", x[i]);
    }



}

main(){
	char x[]="timetopractice";
	char y[]="tore";

	 MinWindow(x,y);
}