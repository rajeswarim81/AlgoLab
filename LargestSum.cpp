#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

int min(int a, int b){
	return (a<b) ? a:b;
}

int ugly(int n){
	vector<int> v;
	v.push_back(1);

    int i2=0, i3=0, i5=0;
	int n2=2, n3=3, n5=5;

	int i,j;
	    n2=v[i2]*2;
		n3=v[i3]*3;
		n5=v[i5]*5;
	for(i=1;i<n;i++){

		j=min( min(n2,n3), n5);
		v.push_back(j);

		if(j==n2){
			i2++;
			n2=v[i2]*2;
		}

		if(j==n3){
			i3++;
			n3=v[i3]*3;
		}

		if(j==n5){
			i5++;
			n5=v[i5]*5;
		}
       cout<<"\n"<<v.back()<<"\n";

	}

      // cout<<"\n"<<v.back()<<"\n";


}

main(){

 ugly(10);

}