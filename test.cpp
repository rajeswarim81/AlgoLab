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

main(){
	int i,n,a;
	a=1;
	queue<int> q;
	while(1){
		cin>>a;
		if(a==42)
			break;
		q.push(a);
	}
    cout<<"\n";
	while(!q.empty()){
		cout<<q.front()<<"\n";
		q.pop();
	}

}