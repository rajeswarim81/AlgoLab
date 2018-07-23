#include<iostream>
#include<deque>

using namespace std;

void fib(int n, int *dp){
	int i;
	for(i=0;i<=n;i++)
		dp[i]=-1;
    dp[0]=1;
    dp[1]=1;
	
	for(i=2;i<=n;i++){
		if(dp[i]==-1)
			dp[i]=dp[i-1]+dp[i-2];
	}

	cout<<"\n"<<dp[i-1]<<"\n";
}
main(){
  int n=6;
  int *dp=new int(n+1);

  fib(n,dp);
}