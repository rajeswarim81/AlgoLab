#include <iostream>
#include <cstdlib>

using namespace std;


main(){
	
    int a[3][3];
    
	int i,j,n=3;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){

			cin>>a[i][j];
		}
	}

	//nt i,j;

	i=n/2;
	j=i;
	int count=1;
	int k;
	int p;
	p=1;

	while(p<=9){
		
		for(k=0;k<count;k++){
			j--;
			cout<<"\t"<<a[i][j];
			p++;
		}

		for(k=0;k<count;k++){
			i++;
			cout<<"\t"<<a[i][j];
			p++;
		}

		for(k=0;k<=count;k++){
			j++;
			cout<<"\t"<<a[i][j];
			p++;

			if(i==0 && j==0)
				return 0;
		}

		for(k=0;k<=count;k++){
			i--;
			cout<<"\t"<<a[i][j];
			p++;
		}


	}
}