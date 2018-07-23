#include<iostream>
#include<cmath>

using namespace std;

int Count(int n){
	int i;
	int ans=0;
	for(i=1;i<=sqrt(n);i++){
       ans+=(n/i)-i+1;
	}
	return ans;

}

main(){
	int n;
	cin>>n;
	cout<<Count(n)<<"\n";
}