#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<complex.h>

double fft(double complex *a, double complex n, int d)
{
 double complex p1[d/2], p2[d/2];
int i=0,j=0,k=0,l=0;

if(d==1)
{ 
return a[0];
}

//dividing the polynomial into 2 parts
for(i=0;i<d;i++)
{
if(i%2==0)
p1[j++]=a[i];
  else if(i%2==1)
       p2[k++]=a[i];
          
}


return fft(p1,cpow(n,2),d/2)+n*fft(p2,cpow(n,2),d/2);
}

void ifft(double complex *a, int n)
{
 int i;
 
 for(i=0;i<=n;i++)
  a[i]=conj(a[i]);
  
  double complex ur[n+1];
  for(i=0;i<=n;i++)
   ur[i]=cos((2*M_PI*i)/(n+1)) + (sin((2*M_PI*i)/(n+1))*I);
   
  
  for(i=0;i<=n;i++) 
   a[i]=fft(a,ur[i],n+1);
   
   for (i=0; i<=n; i++)
         a[i] = conj(a[i])/n;
}


int main()
{
int d,i,n;

//read the value of d
printf("Enter the value of d in 2^d:");
scanf("%d",&d);
n=pow(2,d)-1;
   
//initialising roots of unity and coefficients
double complex ur[2*n+2],y;
//int* acoeff=(int*)malloc((2*n+2)*sizeof(int));
//int* bcoeff=(int*)malloc((2*n+2)*sizeof(int));

double complex acoeff[2*n+1], bcoeff[2*n+1];
double complex temp;

printf("\nEnter the coefficients of A matrix");

//taking input from the user
for(i=0;i<=n;i++)
{
 scanf("\n%lf",&temp);
 acoeff[i]=temp;
 acoeff[i+n+1]=0;
}

printf("\nEnter the coefficients of B matrix");

//taking input from the user
for(i=0;i<=n;i++)
{
 scanf("\n%lf",&temp);
 bcoeff[i]=temp;
 bcoeff[i+n+1]=0;
}

/*//printing random coefficients 
printf("\n\n\nThe coefficients of this polynomial generated randomly are:");
for(i=0;i<=n;i++)
{
 acoeff[i]=15*cos(i);
 acoeff[i+n+1]=0;
 bcoeff[i]=15*sin(i);
 bcoeff[i+n+1]=0;
  //cosine of the index multiplied by 10, as random coefficient
 //printf("a%d = %d\t",i,coeff[i]);
}*/

/*printf("\nCoefficients of A matrix:");
for(i=0;i<=n;i++)
{
 printf("\n%lf",creal(acoeff[i]));
}

printf("\nCoefficients of B matrix:");
for(i=0;i<=n;i++)
{
 printf("\n%lf",creal(bcoeff[i]));
}*/

//defining the roots of unity
for(i=0;i<2*n+2;i++)
{
ur[i]=cos((2*M_PI*i)/(2*n+2)) + (sin((2*M_PI*i)/(2*n+2))*I);
}

double complex ffta[2*n+2],fftb[2*n+2],fftc[2*n+2];

//fft of a matrix
for(i=0;i<=2*n+1;i++)
  {
    ffta[i]=fft(acoeff,ur[i],2*n+2);
   // ffta[i+n+1]=0;
   // printf("%lf + %lf i\n", creal(y), cimag(y));
  }
  
  //fft of b matrix
  for(i=0;i<=2*n+1;i++)
  {
    fftb[i]=fft(bcoeff,ur[i],2*n+2);
   // printf("%lf + %lf i\n", creal(y), cimag(y));
  }
  
  //c matrix in fourier domain
for(i=0;i<=2*n+1;i++)
  {
    fftc[i]=ffta[i]*fftb[i];
   // printf("%lf + %lf i\n", creal(y), cimag(y));
  }
  
  ifft(fftc,2*n+1);
  
  printf("\n Coeff of the multiplied matrix: \n");
  for(i=0;i<=2*n+1;i++)
   printf("%d. %lf\n",i+1,creal(fftc[i]));
  
}
