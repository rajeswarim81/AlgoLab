#include <iostream>
#include <vector>

//sums subsequence


using namespace std;

void subset( vector<int> v, int n, int k){

	bool mat[k+1][n+1];
	int i,j;

	for(j=0;j<=n;j++)
		mat[0][j]=true;

	for(i=1;i<=k;i++)
		mat[i][0]=false;

	

	for(i=1;i<=k;i++){
		for(j=1;j<=n;j++){

			if(v[j-1] > i)
				mat[i][j]=mat[i][j-1];
			else if( i >= v[j-1] )
				mat[i][j]= mat[i][j-1] || mat[i-v[j-1]][j-1];
		}
	}


    
	if(mat[k][n]==true)
		cout<<"yes\n";
	else
		cout<<"no\n";

}

main(){
	vector<int> series;
	int i,t;
	for(i=0;i<5;i++){
		cin>>t;
		series.push_back(t);
	}
	cout<<"\n"; int k;
	cin>>k;

	subset(series, series.size(),  k);
}

