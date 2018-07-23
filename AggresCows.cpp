#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int check(int mid, int *pos, int n, int c){
  int max=-9999;
  int cows=1;

  int i,lastpos=arr[0];
  for(i=1;i<n;i++){
    if(pos[i]-lastpos >=mid){
      if(++cows == c)
        return 1;
      lastpos=pos[i];
    }
  }
  return 0;
}

void find_d(int *pos, int n, int c){
 
 int start=0;
 int end=pos[n-1] - pos[0];

 int mid;

 while(start < end){
  mid= start +(end-start)/2;

  if(check(mid, pos, n, c))
    start=mid;
  else
    end=mid;
 }
}

main(){
  int arr[]={1,2,4,8,9};
  int c=3;
  int n=sizeof(arr)/sizeof(int);
  find_d(arr,n,c);
}