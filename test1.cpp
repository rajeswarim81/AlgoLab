#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<list>
#include<queue>
using namespace std;

main(){
	list<int> l;
	l.push_back(5);
	l.push_back(6);
	l.push_back(7);
	l.push_back(8);
	l.push_back(9);
	l.push_back(10);


	list<int>::iterator i;

	for(i=l.begin();i!=l.end();i++){
		cout<<l.front()<<"\n";
		l.pop_front();
	}

	cout<<"\n";
}