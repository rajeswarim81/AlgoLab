#include<stdio.h>

int findf(int n);

void main()
{
	int n,f,i,j,k;
	printf("Enter the number:");
	scanf("%d",&n);
	printf("\nEnter the method(Enter serial number):\n1.Matrix Power\n2.Reverse odd even\n");
	int d;
	scanf("%d",&d);
	if(d==2)
	{
	f=findf(n);
    printf("\n\nThe fibonacci number is:%d",f);
	}
	else
	{
	  if(n==0)
	{
		printf("The fibonacci number is %d",n);
	}
	
	//initialize the matrices
	int p[2][2]={1,0,0,1};
	int t[2][2]={1,1,1,0};
	int a[2][2],b[2][2];
	int count=0;
	while(n>0)
	{
		printf("\n\nStep %d:",++count);
		printf("\nP matrix:\n");
			for(i=0;i<2;i++)
			{
			
			 for(j=0;j<2;j++)
		{
			  	  printf("%d\t",p[i][j]);
		} printf("\n");
		}
		
		printf("T matrix:\n");
			for(i=0;i<2;i++)
			{
			
			 for(j=0;j<2;j++)
		{
			  	  printf("%d\t",t[i][j]);
		} printf("\n");
		}
		
		if(n%2==1)//taking the remainder
		{
			for(i=0;i<2;i++)
			 for(j=0;j<2;j++)
			  {
			  a[i][j]=p[i][j];//store p in a matrix
			  p[i][j]=0; //reset values to 0
		}
			for(i=0;i<2;i++)
			 for(j=0;j<2;j++)
			  for(k=0;k<2;k++)
			   p[i][j]+=a[i][k]*t[k][j]; //p=p*t
			
			}
			
		
			for(i=0;i<2;i++)
			 for(j=0;j<2;j++)
			 {
			   b[i][j]=t[i][j];//store t in b matrix
			   t[i][j]=0; //reset values to 0
		}
		    for(i=0;i<2;i++)
			 for(j=0;j<2;j++)
			  for(k=0;k<2;k++)
			   t[i][j]+=b[i][k]*b[k][j];//t=t^2	
	n=n/2; //binary
				  
	}
	
		printf("The fibonacci number is: %d",p[0][1]);
	
}
	
	
}

int findf(int num)
{
  int i,a[12];
  int q=num;
  if(num==0)
  return num;
  else if(num==1)
  return num;
  else
  {
  
  int fk=0,fk1=1,f2k1,f2k2,f2k; int j;
  //store binary
  for(i=0;num!=0;i++)
  {
  	a[i]=num%2;
  	num=num/2;
  }
  
  printf("\nBinary representation of the number: \t %d");
  for(j=i-1;j>=0;j--)
  printf("%d",a[j]);
  
  
  //printf("%d",a[0]);
  //run the algorithm
  int k=0,n=1;
  for(j=i-1;j>=0;j--)
  {
  	n=2*k+a[j];
  	printf("\n\nStep:%d",i-j);
  	printf("\nb=%d",a[j]);
  	printf("\nn= %d",n);
  	f2k1=fk*fk+fk1*fk1;
  	f2k=fk*(2*fk1-fk);
  	f2k2=f2k+f2k1;
  	printf("\nFk=%d \nFk+1=%d \nF2k=%d \nF2k+1=%d \nF2k+2=%d",fk,fk1,f2k,f2k1,f2k2);
  	
  	if(a[j]==1)
  	{
  		fk1=f2k2;
  		fk=f2k1;
  		printf("\nValues carried to the next step are Fk+1=%d and Fk=%d",fk1,fk);
	  }
	  
	else if(a[j]==0)
	{
		fk=f2k;
		fk1=f2k1;
			printf("\nValues carried to the next step are Fk+1=%d and Fk=%d",fk1,fk);
	}
	k=n;
  }
  
  
  if(k%2==1)
  return f2k1;
  else if(k%2==0)
  return f2k;
  else return 100;
  
}
}
