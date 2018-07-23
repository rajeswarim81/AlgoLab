#include <iostream>

using namespace std;
int array[100];
int n1=0;
int n2=99;

void insert(int n){
	if(n2==n1+1)
		return;
	if(n==1)
	{
		array[n1]=n1;
		n1++;
		return;
	}

	array[n2]=n2;
	n2--;
	return;
}

void delete(int n){
	if(n==1 && n1==0)
		return;
	else if(n==2 && n2==9)
		return;
	if(n==1)
		n1--;
	else
		n2++;
}

void show(int n){
	int i;
	if(n==1){
		i=n1;
		while(i >=0 ){
		cout<<array[n1-i];
		i--;
	    }

	}
	else{
		i=n2;
		while(i==99){
			cout<<array[i];
			i++;
		}
	}
}

main(){
	//int array[100];
	int ans=0;
	int n,opt;

	do{

		cout<<"Insert stack number: ";
		cin>>n;
		cout<<"\nMenu:\n1.Insert\n2.Delete\n3.Show\n4.Quit";
		cin>>opt;

		switch(opt){
			case 1:
			   insert(n);
			   break;

			case 2:
			   delete(n);
			   break;

			case 3:
			   show(n);
			   break;

		}



	}while(ans != 4);
}