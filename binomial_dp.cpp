#include <iostream>
#include <cstdlib>
using namespace std;

int binomial(int n, int k){
	//int **dp;
		//dp=(int **)malloc((n+1)*(k+1)*sizeof(int**));

    int dp[k+1][n+1];
	int i,j;

	//initial states
	for(i=0;i<=k;i++){
		for(j=0;j<=n;j++){
			if((i==j) || (i==0))
				dp[i][j]=1;

			else if(i<j)
			    dp[i][j]= dp[i-1][j-1] + dp[i][j-1];
		}
	}

/*	for(i=0;i<=k;i++){
		for(j=0;j<n;j++){
			  if(i<j)
			    dp[i][j]= dp[i-1][j-1] + dp[i-1][j];
		}
	}


*/

	//print_dp(k+1,n+1);
	//cout<<dp[0][0]<<dp[1][4];
	return dp[k][n];

}


main(){
	cout<<"\nEnter n: ";
	int n;
	cin>>n;

	cout<<"\nEnter k: ";
	int k;
	cin>>k;

	cout<<"\nThe binomial coefficient is: "<<binomial(n,k)<<"\n";
}