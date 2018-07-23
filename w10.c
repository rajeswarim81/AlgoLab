#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(int argc, char *argv[])
{
	char *name= argv[1];
	FILE *fp= fopen(name, "r");

	if(!fp)
	{
		printf("ERROR!!!!");
		return;
	}

	

	int n1,n2; //variable to store node valueues

	int value, max=0; // variable to store component valueues

	char comp; // varibale to store type of component

	int n;

	while(!feof(fp))
	{
       fscanf(fp,"%d %d %c %d", &n1,&n2,&comp,&value);
        
       if(n1 > n2)
       {
       	if(n1>max)
       	{
       		max=n1;
       	}
       }

       else if(n2>n1)
       	     {
       	     	if(n2>max)
       	     	{
       	     		max=n2;
       	     	}
       	     }



	}


	 n=max+1;

	int am[n][n]; //adjacent matrix 
	int current=0;

	int v[n][n];
	int *i[n]; //size of current matrix is unkown
	int r[n][n]; //resistors matrix
	int d[n][n]; //diodes matrix

	fclose(fp);

	int p,q;

	for(p=0;p<n;p++)
     {
         for(q=0;q<n;q++)
	      {
	      	d[p][q] = -1; 
	        am[p][q] = 0;
	        r[p][q] = -1;
	        v[p][q] = -1;
	        
	      }
     }

	FILE *f=fopen(name, "r"); //open the file again read mode to open it from index 0 again

    if(!f)
	{
		printf("ERROR!!!!");
		return;
	}

	while(!feof(f))
	{
		fscanf(f,"%d %d %c %d", &n1,&n2,&comp,&value);

		  


		am[n1][n2]=1;

		for(p=0;p<n;p++)
        {
	        for(q=0;q<=p;q++)
	        {
		        if(am[p][q]==1)
		          current ++;
	        }
        }


        for(p=0;p<n;p++)
        {
	         for(q=0;q<current;q++)
	         {
		         i[p][q] = 0;
             }
        }


        if(comp == 'R')
		{
           r[n1][n2]=value;
		}

		else if(comp == 'D')
		     {
                d[n1][n2]=value;
		     }

		else if(comp == 'V')
		      {
                  v[n1][n2]=value;
		      }

		      




	}


}