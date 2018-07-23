#include<iostream>

using namespace std;

main(){
	int t,a,b,c,d;
	cin>>t;
	while(t--){
		cin>>a>>b>>c>>d;

		if(a==b && c==d)
			cout<<"YES\n";
		else if(a==c && b==d)
			cout<<"YES\n";
		else if(a==d && b==c)
			cout<<"YES\n";
		else
			cout<<"NO\n";

	}
}