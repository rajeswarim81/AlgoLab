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

bool check(int *l, int sum, int n){
	if(n==1)
		if(l[0]==sum)
			return true;
		else
			return false;

	int i, j;

	bool dp[sum+1][n+1];

	for(i=0;i<=n;i++)
		dp[0][i]=true;

	for(i=1;i<=sum;i++)
		dp[i][0]=false;

	for(i=1;i<=sum;i++){
		for(j=1;j<=n;j++){
			if(i >= l[j-1])
				dp[i][j]= dp[i][j-1] || dp[i-l[j-1]][j];

			else
			  dp[i][j]=dp[i][j-1];	

			  cout<<dp[i][j]<<"\t"; 
		}

		cout<<"\n";
	}
	
return dp[sum][n];
}

main(){
	int l[]={3,34,4,12,5,2};
	int sum=15;
	int n=sizeof(l)/sizeof(int);
	bool ans=check(l,sum,n);
	cout<<ans<<"\n";
}