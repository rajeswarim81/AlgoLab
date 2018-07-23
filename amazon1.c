#include <iostream>
#include <stack>
#include <vector>

using namespace std;


stack <int> min;
stack <int> push( stack <int> s, int k){
	s.push(k);

	if(a<min.top() || min.empty()){
		min.push(a);

	}
	return s;
}

void showstack(stack <int> sq){

	stack <int> s=sq;
	while(!s.empty()){
		cout<<s.top()<<"\t";
		s.pop();
	}
}

stack <int> pop(stack <int> sq){
	
	s.pop();

	if(a==min.top() || !min.empty()){
		min,pop();
	}
	return s;
}

void find

main(){

	//stack <int> minstack;
	stack <int> s;
	s=push(5);
	s=push(s,6);
	s=push(s,65);
	s=pop(s);
	showstack(s);
}