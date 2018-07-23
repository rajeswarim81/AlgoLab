/*Given two numbers as stings s1 and s2 your task is to multiply them. You are required to complete the function multiplyStrings which takes two strings s1 and s2 as its only argument and returns their product as strings.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow . Each test case contains two strings s1 and s2 .

Output:
For each test case in a new line the output will be a string denoting the product of the two strings s1 and s2.

Constraints:
1<=T<=100
1<=length of s1 and s2 <=100*/

#include <iostream>
#include <stack>
#include <queue>
#include <cstring>
#include <cstdlib>

using namespace std;

void multiply(string sm,string s, string r){
	int c1,c2,i;
    c1=0,c2=0;
    int c112=0;
    int sum=0;

    int n1=s.length();
    int n2=r.length();
	for(i=0; i<n1;i++){
		sum=atoi(s[i]);
		cout<<sum;
	}
	for(i=0;i<n2;i++){
		c2=c2*10+r[n2-1-i];
	}
    
   // cout<<s<<"\t"<<n1<<"\t"<<c1;
	int mm=c1*c2;
	int m=mm;

	int n=0;
	while(m){
		n++;
		m=m/10;
	}

	//stringsm[n];

	for(i=0;i<n;i++)
      {
      	sm[i]=mm%10;
      	mm=mm/10;
      }
    cout<<sm<<"\n";
     // return sm;
}

main(){
	string ch="33";
	string ch2="2";
	string s;

	multiply(s,ch,ch2);

	cout<<s<<"\n";
}