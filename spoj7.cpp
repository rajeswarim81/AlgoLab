#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

int Count(int x, int y){
	//int x=a[t], y=b[t];

	if(x==y){
		if(x%2==0)
			return 2*x;
		else
			return 2*x-1;
	}

	else if(x==y+2 && x>=2){
		if(x%2==0)
			return 2*x-2;
		else
			return 2*x-3;
	}

	return -1;

}


main(){
	int t;
	cin>>t;
    int x[t],y[t],i;
	for(i=0;i<t;i++){
		cin>>x[i]>>y[i];
	    //cout<<x[i]<<y[i];
	}
    int k;
    for(i=0;i<t;i++){
       k=Count(x[i],y[i]);
       if(k==-1)
       	cout<<"No Number"<<"\n";
       else
       	cout<<k<<"\n";
    	//cout<<"\n";
    }

}