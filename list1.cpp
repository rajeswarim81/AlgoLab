#include<iostream>
#include<utility>
#include<vector>
#include<list>
#include<iterator>
#include<dequeue>

using namespace std;

void showlist(list<int> l);

main(){

	list <int> l1;
	int i;

	for(i=0;i<5;i++)
		l1.push_front(2*i);

    cout<<"\nList:\t";
	showlist(l1);

	l1.sort();
	showlist(l1);

    
  /*  cout<<"\nafter pop front:\n";
	l1.pop_front();
    showlist(l1);

    cout<<"\nafter pop back:\n";
    l1.pop_back();
    showlist(l1);
*/

	
}

void showlist(list<int> l){
	list<int> :: iterator i;

	for(i=l.begin(); i!= l.end();i++)
		cout<<"\t"<<*i;

	cout<<"\n";
}