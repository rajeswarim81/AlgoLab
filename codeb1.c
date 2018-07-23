#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int check(char[][2], int);

main()
{
   int n;
   scanf("%d\n", &n);

   int i,j,k,result[n];
   int count[n];
   char cell[][2];

   for(i=0;i<n;i++)
   {
     scanf("%d\n", &count[i]);
     
     
    for(k=0;k<2;k++)
     { 
           for(j=0;j<count[i];j++)
           {
                scanf("%c\t", &cell[j][k]);
           }
     } 

     result[i] = check(cell,count[i]);

   }


	return 0;
}

int check( char cell[][2], int c)
{
	int i,j;
	int h=0,v=0;

	//for(i=0;i<2;i++)
	//{
	for(j=0;j<c;j++)
	{
       if(cell[j][0]=='*')
       {
       	 if(cell[j][1] == '*' | cell[j+1][1] == '*')
       	 	h=1;

       	 if(cell[j+1][0] == '*')
       	 	v++;
       }
	}

    return (h+v) ;
}