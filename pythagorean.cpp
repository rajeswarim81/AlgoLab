#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int find(int *arr, int n){
	vector <int> v(n);
	int i;

	for(i=0;i<n;i++)
		v[i]=arr[i]*arr[i];

	sort(v.begin(), v.end());

	vector<int>::iterator it;

    int temp;

	int j;
	for(i=0;i<n-2;i++){
		for(j=0;j<n-1;j++){
			temp=v[i]+v[j];
			it=find(v.begin(), v.end(), temp);
			if(it != v.end())
				return 1;
		}
	}

	return 0;
}

main(){
	int arr[]={2,3,4,5,6,7};
	int t=find(arr,6);

	cout<<t<<"\n";
}