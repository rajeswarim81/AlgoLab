#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void showqueue(queue <int> gq)
{
    queue <int> g = gq;
    int i=0;
    while (!g.empty())
    {
        cout << '\t' << g.back();
        g.pop();
    }
    cout << '\n';
}
main(){
/*	stack <int> qs;
	qs.push(5);
	qs.push(6);
	qs.push(56);
	qs.push(45);

	showstack(qs);
*/
	queue <int> qs;
	qs.push(5);
	qs.push(6);
	qs.push(56);
	qs.push(45);

	showqueue(qs);
}