#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<cstdlib>
using namespace std;

int min(int a, int b){
	return (a<b?a:b);
}

int seq(int *l, int n, int *max){

	if(n==1)
		return n;

	int res,i, maxend=1;

	for(i=1;i<n;i++){

		res=seq(l,i,max);
		if(l[i-1] < l[n-1] && res+1 > maxend)
			maxend=res+1;
	}

	if(*max <maxend)
		*max=maxend;

	return maxend;
}

int maxseq(int *l, int n){
	int max=1;
	seq(l,n,&max);
	return max;
}

main(){
	int l[]={10,22,9,33,21,50,41,60,80};
	int n= sizeof(l)/sizeof(int);

	int p=maxseq(l,n);
	cout<<p<<"\n";
}