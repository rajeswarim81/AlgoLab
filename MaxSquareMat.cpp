#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<cstdlib>
using namespace std;

int min(int a, int b){
	return (a<b?a:b);
}

void func(vector<vector<int> > mat){
	//cout<<"check_inside funccccc";
	int n=mat.size();
	int dp[n][n];
	int i,j;

	for(i=0;i<n;i++){
		dp[i][0]=mat[i][0];
		dp[0][i]=mat[0][i];
		//cout<<dp[i][0];
	}


	for(i=1;i<n;i++){
		for(j=1;j<n;j++){
			if(mat[i][j]==0)
				dp[i][j]=0;
			else{
				dp[i][j]=min(min(mat[i-1][j], mat[i][j-1]), mat[i-1][j-1])+1;
			}
		}
	}

	int maxs, maxi, maxj;
	maxs=dp[0][0];
	maxi=0;
	maxj=0;

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			//cout<<dp[i][j];
			if(dp[i][j] >= maxs){

				maxs=dp[i][j];
				maxi=i;
				maxj=j;
			}
		}
	}

	//cout<<"\n"<<maxs<<maxi<<maxj;

	for(i=maxi-maxs+1;i<=maxs;i++){
		for(j=maxj+1-maxs;j<=maxs;j++){
			//cout<<"check";
			cout<<dp[i][j]<<"\t";
		}
		cout<<"\t";
	}

 cout<<"\n";

}

void showv(vector<vector<int> > v){
/*	while(!v.empty()){
		cout<<v[0][0]<<v[0][1]<<"check"<<v[1][0]<<v[1][1];
		v.pop_back();
	}
*/	cout<<v.size();
}

main(){
	cout<<"Enter the matrix size:\t";
	int n;
	cin>>n;

	cout<<"\nEnter the matrix:\n";
	//int **mat;
	int j,i,k;

	vector< vector<int> > mat;
    vector<int> v;

	for(i=0;i<n;i++){
        for(j=0;j<n;j++){
			cin>>k;
			v.push_back(k);
		}
		mat.push_back(v);
		v.clear();
		
    }

	func(mat);	

}