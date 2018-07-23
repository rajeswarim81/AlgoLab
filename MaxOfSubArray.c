#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int max(int a, int b){
  if(a>b)
    return a;
  else
    return b;
}

int *maxele(int *arr, int n, int k){
  // int i;
   //for(i=0;i<n;i++)
     // printf("%d\t", arr[i]);

    //printf("\n");

  if(k==1)
    return arr;
  else if(n==k)
    return arr;
  else{
    int i;
    int *temp=(int *)malloc(sizeof(int));
    temp=arr;

    for(i=0;i<n-1;i++)
      temp[i]=max(temp[i],temp[i+1]);

     // printf("%d\t%d\n", n, arr[n-2]);

    return maxele(temp,n-1,k-1);
  }

}


main(){
  int arr[]={1,2,3,1,4,5,2,3,6}; int k=3;

  int *res=(int *)malloc(sizeof(int));
  int p=sizeof(arr)/sizeof(int);
  res=maxele(arr,p,k);

  int i;
  int n=sizeof(res)/sizeof(int);
  
  //printf("%d\n\n", p);

  for(i=0;i<p-k+1;i++){
    printf("%d\n", res[i]);
  }

  //printf("%d\n", n);
}