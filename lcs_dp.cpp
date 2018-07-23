#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;


int lcs(char a[], char b[], int m, int n){
	if(m==0 || n==0)
		return 0;
	else if(a[m-1] == b[n-1])
		return 1+ lcs(a,b,m-1,n-1);
	else
		return max(lcs(a,b,m-1,n),lcs(a,b,m,n-1));

}

main(){
	char a[]="abcdefg";
	char b[]="ade";
	int m=strlen(a);
	int n=strlen(b);
	int p=lcs(a,b,m,n);
	cout<<"\n"<<p<<"\n";
}