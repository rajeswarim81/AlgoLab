#include<stdio.h>
#include<math.h>
#include<complex.h>
#include<stdlib.h>

double complex polynomial(int p[], double complex n,int d); //function for dc method
void horners(int p[],double complex n,int d); //function for horners method

void main()
{

int d,i,n;

//read the value of d
printf("Enter the value of d in 3^d:");
scanf("%d",&d);
n=pow(3,d)-1;
   
//initialising roots of unity and coefficients
double complex ur[n+1],y;
int* coeff=(int*)malloc((n+1)*sizeof(int));

//printing random coefficients 
printf("\n\n\nThe coefficients of this polynomial generated randomly are:");
for(i=0;i<=n;i++)
{
 coeff[i]=10*cos(i); //cosine of the index multiplied by 10, as random coefficient
 printf("a%d = %d\t",i,coeff[i]);
}

//defining the roots of unity
for(i=0;i<=n;i++)
{
ur[i]=cos((2*M_PI*i)/(n+1)) + (sin((2*M_PI*i)/(n+1))*I);
}

printf("\nThe values of the polynomial are to be found at the unitary roots using two different methods.\n");
//printing the values at those points
printf("\n\nThe value of the polynomial at those points by **DC method** are:\n");
for(i=0;i<=n;i++)
  {
    y=polynomial(coeff,ur[i],n+1);
    printf("%lf + %lf i\n", creal(y), cimag(y));
  }

//using Horner's method to find out the same
   printf("The values at the polynomial at those points by **Horner's method** are:\n");
   for(i=0;i<=n;i++)
   {
     horners(coeff,ur[i],n);
   }

}

double complex polynomial(int p[], double complex n,int d)
{
int p1[d/3], p2[d/3], p3[d/3];
int i=0,j=0,k=0,l=0;

if(d==1)
{ 
return p[0];
}

//dividing the polynomial into three parts
for(i=0;i<d;i++)
{
if(i%3==0)
p1[j++]=p[i];
           else if(i%3==1)
             p2[k++]=p[i];
           else
             p3[l++]=p[i];
}


//resursion
return polynomial(p1,cpow(n,3),d/3)+n*polynomial(p2,cpow(n,3),d/3)+cpow(n,2)*polynomial(p3,cpow(n,3),d/3);
}


void horners(int p[],double complex n,int d)
      {
          int i;
          double complex sum=0;
          for(i=d;i>=0;i--)
          {
              sum=(sum+p[i])*n;
          }
          sum=sum/n;
          printf("%lf + %lf i\n",creal(sum),cimag(sum));
          return;

      }

