#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int *nextl(int *r,int *arr, int n){
  int i,j;
  r[n-1]=-1;
  for(i=n-2; i>=0;i--){
    if(arr[i]<arr[i+1])
      r[i]=arr[i+1];
    else{
      for(j=i+1 ; j<n && arr[i] > arr[j]; j++);
        if(j==n)
          r[i]=-1;
        else
          r[i]=arr[j];

      //  printf("%d\t", r[i]);

       }
  }

  return r;
}

main(){
  int arr[]={10, 4, 5, 90, 120, 80};
  int n=sizeof(arr)/sizeof(int);

  int *r=(int *)malloc(sizeof(int));
  r=nextl(r,arr,n);

  int i;

  for(i=0;i<n;i++)
    printf("%d\t", r[i]);

  printf("\n");
}