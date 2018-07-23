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

int count(int *l, int m, int n){
	if(n==0)
		return 1;
	if(n<0)
		return 0;
	if(m<=0 && n>0)
		return 0;

	
	return count(l,m,n-l[m-1]) + count(l,m-1,n);

}

int count1(int *l, int m, int n){
	int dp[n+1][m];
	int i,j;
	int x,y;

	for(i=0;i<m;i++)
		dp[0][i]=1;

	for(i=1;i<=n;i++){
		for(j=0;j<m;j++){

			if(i>=l[j])            //including l[j]
				x=dp[i-l[j]][j];
			else
				x=0;

			if(j>=1)                   //excluding l[j]
			    y=dp[i][j-1];
			else
			    y=0;

			dp[i][j]=x+y;                   
			
		}
	}

	return dp[n][m-1];
}

main(){
	int l[]={1,2,3};
	int n=4;
    int m=sizeof(l)/sizeof(int);
	int k=count1(l,3,n);
	cout<<k<<"\n";
}