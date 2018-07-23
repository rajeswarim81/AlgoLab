#include<iostream>
#include<cstring> // for int,char macros
//#include<float.h>

using namespace std;

void reverse(char str[]);
void add(char str1[], char str2[]);
void div(char str[]);
void subtract(char a[], char b[]);

main(){
	int t=10;
	char sum[103];
	char diff[103];
	
	while(t--){
       cin>>sum;
       cin>>diff;

       reverse(sum);
       reverse(diff);

       add(sum, diff);

       div(sum);
       reverse(sum);
       cout<<sum<<"\n";

       reverse(sum);
       subtract(sum,diff);
       reverse(sum);
       cout<<sum<<"\n";

    }

}

void subtract(char str1[], char str2[]){
	int i,c=0;

	int n1=strlen(str1),
	    n2=strlen(str2);

	    
	    for(i=n2;i<n1;i++)
	    	str2[i]='0';
        
        int d=0;
	    for(i=0; i<n1 ; i++){
	    	d=(str1[i]-'0'-c) - (str2[i]-'0');

	    	if(d<0){
	    		d+=10;
	    		c=1;
	    	}

	    	else
	    		c=0;
	    	str1[i]='0'+d;
	    }



	    i=n2-1;
	    str2[n2]='\0';
	    while(str1[i]=='0' && i>0)
		    i--;
        
        str1[i+1]='\0';
	    


}

void div(char str[]){
	int i, carry=0,temp;
	int n=strlen(str);
	for(i=n-1; i>=0;i--){
		temp=10*carry + (str[i]-'0');
        carry=temp%2;
        str[i]='0'+temp/2;
	}

    i=n-1;
	while(str[i]=='0' && i>0)
		i--;

	str[i+1]='\0';
	
}

void add(char str1[], char str2[]){
	int carry=0;
	int i;
	int n1=strlen(str1),
	    n2=strlen(str2);

	    for(i=n1; i <n2;i++)
	    	str1[i]='0';
	    for(i=n2;i<n1;i++)
	    	str2[i]='0';

	    for(i=0; i<n1 || i<n2; i++){
	    	int sum=(str1[i]-'0') + (str2[i]-'0')+carry;
	    	carry=sum/10;
	    	sum%=10;
	    	str1[i]='0'+sum;
	    }

	    while(carry){
	    	str1[i]= '0'+ (carry%10);
	    	carry/=10;
	    	i++;
	    }
	    str1[i]='\0';
	    str2[n2]='\0';
}

void reverse(char str[]){
	int i;
	int n=strlen(str);

	char cc;
	for(i=0;i<n/2;i++){
		cc=str[i];
		str[i]=str[n-i-1];
		str[n-i-1]=cc;
	}
}