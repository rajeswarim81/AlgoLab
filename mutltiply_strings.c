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
#include <string>

using namespace std;

string multiply(string s, string r){
	int c1,c2,i;
    c1=0,c2=0;
	for(i=0;i<strlen(s);i++){
		c1=c1*10+s[i];
	}

	for(i=0;i<strlen(r);i++){
		c2=c2*10+s[i];
	}

	int mm=c1*c2;
	int m=mm;

	int n=0;
	while(m){
		n++;
		m=m/10;
	}

	string sm[n];

	for(i=0;i<n;i++)
      {
      	sm[i]=m%10;
      	m=m/10;
      }

      return sm;
}

main(){
	string ch="33";
	string ch2="2";

	string n=multiply(ch1,ch2);

	cout<<n<<"\n";
}