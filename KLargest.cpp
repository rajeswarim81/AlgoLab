/**/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

main(){
	int n;
	
	cin>>n;
	vector <int> v(n);
	int i;

	for(i=0;i<n;i++){
		cin>>v[i];
	}

	sort(v.begin(), v.end());

	for(i=0;i<3;i++)
		cout<<v[i];
}