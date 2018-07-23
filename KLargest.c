/**/


#include <iostream>
#include <vector>

using namespace std;

main(){
	int arr[]={5,6,4,2,3,9,6,5};

	vector <int> v;
	int i;

	int n=sizeof(arr)/sizeof(int);

	for(i=0;i<n;i++)
		v.push_back(arr[i]);

	sort(arr.begin(), arr.end());

	for(i=0;i<5;i++)
		cout<<v[i];
}