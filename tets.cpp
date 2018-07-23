#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

int min(int a, int b){
	return (a<b)?a:b;
}

int Count(int n){
	int flag=n;
	int a[200],i=0,rem;
	while(flag){
		a[i]=flag%10;
		flag=flag/10;
		i++;
	}

	int size=i;
	//int ans[200];


    int carry=0, x=0,index=0;
	for(i=2;i<n;i++){
        carry=0;
		for(index=0; index<size; index++){
			//cout<<"checklfsd";
            x=a[index]*i+carry;
            a[index]=x%10;
            carry=x/10;
          //  cout<<carry;
		}

		while(carry!=0){
			a[index]=carry%10;
			carry=carry/10;
			//cout<<a[index];
			index++;
			size++;
		}

	}

	for(i=size-1;i>=0;i--)
		cout<<a[i];
	cout<<"\n";

	return 0;
	
}

main(){
	int t;
	cin>>t;
    int n[t],i;
	for(i=0;i<t;i++)
		cin>>n[i];
	//cout<<"\n";
    
    for(i=0;i<t;i++){
    	Count(n[i]);
    	//cout<<"\n";
    }

}