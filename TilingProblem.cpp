/*Given a “2 x n” board and tiles of size “2 x 1”, count the number of ways to tile the given board using the 2 x 1 tiles. A tile can either be placed horizontally i.e., as a 1 x 2 tile or vertically i.e., as 2 x 1 tile. */

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

int count(int n){
	int dp[n+1];

	dp[0]=0;
	dp[1]=1;
	dp[2]=2;

    int i;

	for(i=3;i<=n;i++){
		dp[i]=dp[i-1]+dp[i-2];
	}

	return dp[n];
}

main(){
	int n=4;

	cout<<count(n)<<"\n";
}