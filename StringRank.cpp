/*

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
*/

#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int find_rank(string s, int n){
	int count=0,i,j;

	vector <string> v;

	for(i=0;i<=n;i++){
		for(j=0;j<=(n-i);j++){
			v.push_back(s.substr(j,i));
			cout<<v[count++]<<"\n";
		}
	}
    string temp;
    for(i=0; i<v.size()-1; ++i)
    {
        for(j=i+1; j< v.size(); ++j)
        {
            if(v[i] > v[i+1])
            {
             swap(v[i], v[j]);
            }
        }

    }
    for(i=0;i<=count;i++){
    	cout<<"\n"<<v[i];
    }


}

main(){
	string s="eren";
	string v= "bnmn";
	cout<< strcmp(s,v);
	//cout<<s.substr(1,2);
	int n=find_rank(s, s.length());
}