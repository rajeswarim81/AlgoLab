#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

int min(int a, int b){
	return (a<b)?a:b;
}

int Count(long n){
	int i=1;
	int c=0;

	while(n>=pow(5,i)){
		c=c+n/(int)pow(5,i);
		i++;
	}

	return c;


}

main(){
	int t;
	cin>>t;
	long n[t],i;
	for(i=0;i<t;i++)
		cin>>n[i];
	//cout<<"\n";
    
    for(i=0;i<t;i++){
    	cout<<Count(n[i])<<"\n";
    }

}