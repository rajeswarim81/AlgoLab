/*Given a sequence, find the length of the longest increasing subsequence from a given sequence .
The longest increasing subsequence means to find a subsequence of a given sequence in which the subsequence's elements are in sorted order, lowest
to highest, and in which the subsequence is as long as possible. This subsequence is not necessarily contiguous, or unique.

Note: Duplicate numbers are not counted as increasing subsequence.

For example:
 length of LIS for 
{ 10, 22, 9, 33, 21, 50, 41, 60, 80 } is 6 and LIS is {10, 22, 33, 50, 60,*/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int lis(int *arr, int n){
  int lis[n];
  int i,j;

  for(i=0; i<n; i++)
    lis[i]=1;

  for(i=1; i<n; i++){
    for(j=0; j<i; j++){
      if( (arr[j] < arr[i]) && (lis[i] < lis[j]+1)){
          lis[i]=lis[j]+1;
      }
    }
  }

  int max=0;

  for(i=0;i<n;i++){
    if(max<lis[i])
      max=lis[i];
  }

  return max;
}


main(){
  int arr[]={5,2,3,1,4,7};
  int n=sizeof(arr)/sizeof(int);
  
  int l=lis(arr,n);
  printf("%d\n",l);

}