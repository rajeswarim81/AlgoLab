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

int prio(char ch){
	switch(ch){
		case '+':return 1;
		case '-':return 2;
		case '*':return 3;
		case '/':return 4;
		case '^':return 5;

		default: return -1;
	}
}

void func( int n, string l){
	int i;

	stack<char> s;
	for(i=0;i<n;i++){
       
       if((l[i]>='a' && l[i]<='z') || (l[i]>='A' && l[i] <='Z'))
       	cout<<l[i]; 

       else if(l[i]=='(')
       	s.push(l[i]);

       else if(l[i] == ')'){
       	while(s.top() != '('){
       		cout<<s.top();
       		s.pop();
       	}
       	s.pop();
       }

       else{
       	if(prio(s.top()) > prio(l[i]))
       		cout<<l[i];
       	else
       		s.push(l[i]);
       }
       
	}
	//cout<<"\n";
}

main(){
	//string l;
	int t,k=0;
	cin>>t;
	string entry[t];
	int lengths[t];

    cin.ignore();
	for(k=0;k<t;k++){
		//cin.ignore();
        getline(cin, entry[k]);
        lengths[k]=entry[k].size();
       
    }

	for(k=0;k<t;k++){
        func(lengths[k],entry[k]);
		cout<<"\n";
	}


	//cout<<"\n";
}