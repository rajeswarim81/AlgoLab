#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;


int min(int a, int b, int c){
	if((a<b) && (a<c))
		return a;
	else if((b<a) && (b<c))
		return b;
	else 
		return c;
}
int ugly(int n){
	int ugly[n];
	ugly[0]=1;

	int i2=0,i3=0,i5=0;
	int next2=2, next3=3, next5=5;
	int uglynext;

	for(int i=1;i<n;i++){
     
     uglynext=min(next2, min(next3,next5));

     ugly[i]=uglynext;
     
     if(ugly[i]==next2){
     	i2++;
     	next2=ugl[i2]*2;

     }

      
    }
    return ugly[2];
}

main(){
	int n=ugly(7);
	cout<<"\n"<<n<<"\n";
}