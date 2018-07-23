#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<list>
#include<queue>
#include<stack>
using namespace std;

int min(int a, int b){
	return (a<b?a:b);
}

int max(int a, int b){
	return (a>b?a:b);
}

bool check10(int n){
	if(n%10 !=0 || n==0)
		return false;
	else if(n==10)
		return true;
	else
		return check10(n/10);
}

int dig(int n){
	if(check10(n))
		return ceil(log(n)/log(10))+1;
	else
		return ceil(log(n)/log(10));
}

int IsAll9(string l, int n){
	int i;
	//cout<<n;
   
	for(i=0;i<n;i++){
		//cout<<l[i];
		if(l[i]!='9')
			return 0;
	}
   // cout<<"chevk";
	return 1;
}



void func(string l){
	//int p=dig(n);

	int p=l.length();
	//cout<<p;

	bool leftsmaller=false;

	int i,j,k,q;   

    //cout<<"ckehcjf";
	if(IsAll9(l, p)){
		//cout<<"check";
		cout<<"1";
		 for(q=1;q<p;q++)
		 	cout<<"0";
		 cout<<"1";

		// cout<<"check";
        return;
	
	}
//	for(i=0;i<p;i++)
//		cout<<l[i];
	int midi, midj;

	i=p/2-1;
	j=(p%2)?(p/2+1):(p/2);

	midi=(p%2)?(p/2):(p/2)-1;
	midj=p/2;

	while(i>=0 && (l[i]==l[j]))
		i--, j++;

	if(i<0 || l[i]<l[j])
		leftsmaller=true;

	while(i>=0){
		l[j]=l[i];
		i--;
		j++;
	}

	if(leftsmaller==true){
		int carry=1;

		if(p%2==1){
			l[midi]+=carry;
			carry=(l[midi]-48)/10;
			l[midi]=(l[midi]-48)%10 +48;
			i=p/2-1;
		    j=p/2+1;
		}
		else{
			i=p/2-1;
			j=p/2;
		}
		

		while(i>=0){
			l[i]+=carry;
			carry=(l[i]-48)/10;
			l[i]=(l[i]-48)%10+48;
			l[j]=l[i];
			j++;
			i--;
		}
	}


	for(i=0;i<p;i++)
		cout<<l[i]-48;



}



main(){
	int t;
	

	int k,i;
	cin>>t;
	string n[t];
    
	for(k=0;k<t;k++){
         cin>>n[k];
      }
	cout<<"\n";
	for(k=0;k<t;k++){
		//cout<<n[k]<<"\n";
		func(n[k]);
		cout<<"\n";
	}
	
}