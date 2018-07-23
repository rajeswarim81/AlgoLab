#include<iostream>
#include<utility>
#include<vector>
#include<list>
#include<iterator>
#include<deque>
#include<queue>

using namespace std;

void showq(priority_queue<int> q){
	priority_queue<int> qq=q;
	while( !qq.empty()){
		cout<<qq.top()<<"\t";
		qq.pop();
	}
	cout<<"\n";
}

main(){
	priority_queue<int> q;

	q.push(43);
	q.push(59);
	q.push(2);
	q.push(109);
	q.push(6);

	showq(q);
}

