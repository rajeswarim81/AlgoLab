#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int check(char[][100], int, int);

main()
{
  int n,i=0,j=0,c;
  scanf("%d\n", &n);

  char a[n][100];
  for(i=0;i<n;i++)
  {
  	j=0;
    do
    {
    	scanf("%c",&a[i][j++]);

    }while(a[i][j-1] != '\n');
  }

  printf("\n");

  for(i=0;i<n;i++)
  {
    c = check(a,i,j);
    if(c==0)
    	printf("tie\n");
    else if(c==1)
    	printf("snakes\n");
    else
    	printf("mongooses\n");
  }

  return 0;
}

int check(char a[][100],int k,int j)
{
  int counts=0, countm=0,i;

  for(i=0;i<j;i++)
  {
    if(a[k][i] == 'm')
    {
    	countm++;
    	
    	
    	if(a[k][i-1] == 's')
        {
    		 a[k][i-1]=0;
    		 counts--;
   	    }
        

    	else if(a[k][i+1]=='s')
    	{
    		a[k][i+1]=0;
    		//counts--;
    	}
    }
    else if(a[k][i] == 's')
    {
    	counts++;
    }
  }

  if(counts > countm)
  	return 1;
  else if(counts < countm)
  	return 2;
  else if(counts==countm)
  	return 0;
}