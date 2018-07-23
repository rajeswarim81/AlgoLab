#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;



int find_coeff(int n,int k){

	if(n<k)
		return -1;

	int dp[k+1][n+1];
    int i,j;

    for(i=0;i<=k;i++)
      {
      	for(j=0;j<=n;j++){
      		if((i==j) || (i==0))
      			dp[i][j]=1;
      	}	
      }

     for(i=1;i<=k;i++){
     	for(j=i+1; j<=n;j++){
     		dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
     	}
     }
      	
     return dp[k][n];
}

main(){
	int n,k;
	n=7;
	k=2;
	int p=find_coeff(n,k);
	cout<<"\n"<<p<<"\n";
}