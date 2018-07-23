#include<iostream>

using namespace std;

int pow(long long a, long long b)
{
    if(a == 0 && b == 0)    return 0;
    int ans = 1;
    while(b > 0)
    {
        if(b%2 == 1)
            ans *= a;
        a *= a;
        a %= 10;
        ans %= 10;
        b /= 2;
        if(ans == 0)    break;
    }
    return ans;
}
main(){
	int t;
	cin>>t;
	while(t--){
		long long a,b;
		cin>>a>>b;
		cout<<pow(a,b)<<"\n";
	}
}