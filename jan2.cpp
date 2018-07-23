#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;

main(){
	int t;
	cin>>t;
	long long n;
	int i,j;
	long long max,prev;
	while(t--){
		
		cin>>n;
		max=0;
		prev=LONG_MAX;

		long long arr[n][n];
		long long index[n];

		for(i=0;i<n;i++)
			index[i]=n-1;

		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				cin>>arr[i][j];

		for(i=0;i<n;i++)
			sort(arr[i], arr[i]+n);
        
		for(i=n-1;i>=0;i--){
			while(arr[i][index[i]] > prev)
				index[i]--;
			if(index[i]<0)
				max=-1;
			else{
			max+=arr[i][index[i]];
			prev=arr[i][index[i]];
		    }
		}
		cout<<max<<"\n";
    }
}