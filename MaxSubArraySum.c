#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int max(int a, int b){
  if(a>b)
    return a;
  else 
    return b;
}

int maxsum(int *arr, int n){
  int maxend=0;
  int maxhere=0;
  int i;
  for(i=0;i<n;i++){
    //maxhere+=arr[i];
      maxhere=max(arr[i], maxhere+arr[i]);
      maxend=max(maxend, maxhere);
     // printf("%d\n", maxend);
  }

  return maxend;
}

main(){
  int arr[]={5,2,3,-5,-9,5,8,4,-7};
  int n=sizeof(arr)/sizeof(int);

  int np=maxsum(arr, n);
  printf("\n\n%d\n",np);
}