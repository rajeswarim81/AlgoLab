#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<cstdlib>
using namespace std;

int min(int a, int b){
	return (a<b?a:b);
}

int max(int a, int b){
	return (a>b?a:b);
}

int count(int *l,int k, int n){
	if(k>=n-1)
		return 0;
	if(l[k]==0)
		return 0;
	int i,t;
	int min=9999;

	for(i=1;i<=l[k];i++){
		t=count(l, k+i, n);
		if(min > t)
			min=t;
	}

    return 1+min;    
}

int countdp(int *l, int n){
	int dp[n];
	dp[n-1]=0;
	int i,j;
	//int min;

	dp[0]=0;

	for(i=1;i<n;i++){

		dp[i]=9999;
		for(j=0;j<i;j++){
			if(i<=j+l[j] && dp[j]!=9999){
				dp[i]= min(dp[i], (dp[j]+1));

				break;
			}
		}
	}
	
  return dp[n-1];

}

main(){
	int l[]={1, 3, 6, 3, 2, 3, 6, 8, 9, 5};
	//int l[]={2,3,1};
    int n=sizeof(l)/sizeof(int);

	int k=countdp(l,n);
	cout<<k<<"\n";
}