#include<iostream>
#include<utility>
#include<vector>
#include<list>
#include<iterator>
#include<deque>

using namespace std;

void showdq( deque<int> dq){
	deque<int> ::iterator i;
	for(i=dq.begin();i!=dq.end();i++)
		cout<<"\t"<<*i;
	cout<<"\n";
}

main(){
	deque<int> dq;
	dq.push_back(1);
	dq.push_front(2);
	dq.push_back(3);
	dq.push_front(4);

    //cout<<dq[2]<<"\n";
    dq.pop_front();
	showdq(dq);
}

