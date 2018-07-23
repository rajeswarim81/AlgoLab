#include<iostream>

using namespace std;


int rev(int s1){
	//int n=s1.length();
	int k=0;
	while(s1){
		k=k*10+(s1%10);
		s1=s1/10;
	}
	return k;
}

main(){
	int t;
	cin>>t;
	int k;
	int n1[t], n2[t];
	for(k=0;k<t;k++){
		cin>>n1[k]>>n2[k];
	}
	cout<<"\n";
	for(k=0;k<t;k++){
		cout<<rev(rev(n1[k]) + rev(n2[k]))<<"\n";
	}
	
}