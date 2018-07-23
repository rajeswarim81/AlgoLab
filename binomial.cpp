#include<iostream>
#include<string>
using namespace std;

int max(int a, int b){
	return (a>b) ? a:b;
}

int subs(string a, int na){

	int dp[na+1][na+1];
	int i,j;
	for(i=0;i<na;i++){
		dp[i][0]=0;
		dp[0][i]=0;
		dp[i][i]=0;
	}

	cout<<"\n";

	for(i=0;i<na;i++){
		for(j=i+1;j<na;j++){
			if(a[i]==a[j]){
				dp[i][j]=dp[i-1][j-1]+1;
				cout<<a[i];
			}
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			
		}
	}
	cout<<"\n";

	//cout<<"\n"<<dp[na][nb]<<"\n";
}

main(){

	cout<<"check\n";
	
	string a;

	cout<<"\nEnter first string:\t";
	getline(cin, a);

	/*cout<<"\nEnter second string:\t";
	getline(cin, b);
*/
	int na=a.length();
//	int nb=b.length();

	int p=subs(a,na);



}