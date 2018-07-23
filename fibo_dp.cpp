#include <iostream>
using namespace std;

int *dp;

void initialize(int n){
	dp=new int[n+1];
	int i;
	for(i=0;i<=n;i++){
		dp[i]= -1;
	}

	dp[0]=dp[1]=1;
}

int fib_lookup(int n){
	if(n<2){
		return dp[n];
	}
	else if(dp[n] != -1)
		return dp[n];
	else
		return (fib_lookup(n-1)+fib_lookup(n-2));
}

int fib_tabulation(int n){
	int i;
	for(i=2;i<=n;i++){
		dp[i]=dp[i-1]+dp[i-2];
	}

	return dp[n];
}

main(){
	int n;
	cout<<"\nEnter the number: ";
	cin>>n;
	cout<<"\n";
	initialize(n);
	cout<<"Fibonaaci: "<<fib_lookup(n)<<"\n";
}