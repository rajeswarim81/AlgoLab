#include <iostream>
#include <cstdlib>

using namespace std;

int max(int a, int b){
	return (a>b?a:b);
}



void lis(int n, int *arr){

	int l[n],i;
	for(i=0;i<n;i++)
		l[i]=1;

	int j=0;
	i=1;
	int maxhere=1;

	while(i<n){
		j=0;
		maxhere=1;

		while(j<i){



		    if(arr[i] > arr[j]){

                 if(l[j]+1 > maxhere){
			        l[i]=l[j]+1;
			        maxhere=l[i];
			        }
             
		    }
            // cout<<i<<j<<"\t";
		    j++;

	    }
     //   cout<<i;
		i++;


	}

	for(i=0;i<n;i++)
		cout<<l[i]<<"\t";

}

main(){

	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr)/sizeof(arr[0]);
    lis(n, arr);
   // printf("Length of lis is %dn", lis( n, arr ));
    return 0;

}