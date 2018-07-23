#include<iostream>
#include<string>

using namespace std;

main(){
	int t;
	int column;
	cin>>column;
	while(column !=0){
		string s;
		cin>>s;
		int size=s.length();
		int row=size/column;

		int i,j;

		for(j=0;j<column;j++){
			for(i=0;i<row;i++){
				if(i%2==0)
				   cout<<s[column*i+j];
				else
					cout<<s[column*i + (column-1-j)];

			}
		}
		cout<<"\n";

		cin>>column;
	}
}