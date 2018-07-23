#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void MinWindow(char *x, char *y){
	int xlen=x.length();
	int ylen=y.length();

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
    int start=0, window=10000; flag=-1;
	for(i=0;i<xlen;i++){
		hashx[x[i]-'a']++;

		if(hashy[x[i]-'a'] && (hashx[x[i]-'a'] <= hashy[x[i]-'a'])) //do count++ for only one appearance of the literal
			count++;

		if(count == ylen){
			flag=1;

		while(hashy[ x[start]-'a' ]==0 || hashx[ x[start]-'a'] > hashy[ x[start]-'a']){
			hash[ x[start]-'a']--;
			start++;
		}

		if( i-start+1 < window)
			window= i-start+1;
		
	
		}
    }

    if(flag == -1)
    	cout<<flag;
    else
    {
    	for(i=start; i<= start+window; i++)
    		cout<<x[i];
    }



}

main(){
	char x[]="timetopractice";
	char y[]="toc";

	void MinWindow(x,y);
}