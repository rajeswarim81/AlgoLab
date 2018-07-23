//#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void makepairs(vector <pair<int, int> > v, int n){

	vector<int> lis(n,1);

	int i,j;

	for(i=1; i<n;i++){
		for(j=0;j<i;j++){
			if(v[i].first > v[j].second && lis[i]< lis[j]+1){
				lis[i]++;
				//cout<<lis[i]<<"\n";

			}
		}
	}

	sort(lis.begin(), lis.end());
    cout<<lis[n-1]<<"\n";

}

main(){ 
	vector< pair<int,int> >v;
	v.push_back(make_pair(1,2));
	v.push_back(make_pair(4,10));
	v.push_back(make_pair(2,3));
	v.push_back(make_pair(5,18));
	v.push_back(make_pair(20,21));
	v.push_back(make_pair(4,15));

	int n= v.size();

/*	for(int i=0;i<n;i++){
     	cout<<v[i].first<<"\n";
      }
*/
    

    makepairs(v,n);
}