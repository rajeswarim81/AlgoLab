#include<iostream>
#include<utility>
#include<vector>
using namespace std;

main(){

	vector<int> v;
	vector<int> :: iterator i;
	vector<int> :: reverse_iterator ir;

     //v.resize(4);
	for(int i=0; i<5;i++)
		v.push_back(i);

	cout<<"Containers of the vector: ";
	//v.resize(4);

	for(i=v.begin(); i!=v.end();i++)
		cout<<*i<<"\t";
	cout<<"\n";

	i=v.begin()+1;

	v.insert(i,5);

	for(i=v.begin(); i!=v.end();i++)
		cout<<*i<<"\t";
	cout<<"\n";

	/*v.pop_back();

	for(i=v.begin(); i!=v.end();i++)
		cout<<*i<<"\t";
	cout<<"\n";
*/

	//v.resize(4);
	//cout<<v[17]<<"\n";

	/*cout << "Size : " << v.size();
    cout << "\nCapacity : " << v.capacity();
    cout << "\nMax_Size : " << v.max_size();
*/
}