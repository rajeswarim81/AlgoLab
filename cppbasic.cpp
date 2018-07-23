#include <iostream>
#include <vector>
using namespace std;

main(){

	vector <int> g1;

    vector <int> :: iterator i;
    vector <int> :: reverse_iterator ir;

	for (int j = 1; j <= 5; j++)
        g1.push_back(j);

 /*   for(i=q.begin(); i != q.end();i++){
    	cout<< *i<<"\t";
    }

    cout<<"\nCapacity: "<<q.empty();
*/

    cout << "Reference operator [g] : g1[2] = " << g1[2];
    cout << endl;
    cout << "at : g1.at(4) = " << g1.at(4);
    cout << endl;
    cout << "front() : g1.front() = " << g1.front();
    cout << endl;
    cout << "back() : g1.back() = " << g1.back();
    cout << endl;
 
    return 0;
}