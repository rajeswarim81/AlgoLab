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

int nextlarge(int *arr, int i, int n){
  int j;
  for(j=i;j<n;j++){
    if(arr[j] > arr[i])
      return arr[j];

  }
  
    return -1;

}


main(){
  int arr[]={5,2,3,1,4,7};
  int n=sizeof(arr)/sizeof(int);
  
  int result[n];
  int i;
  for(i=0;i<n;i++){
    result[i]=nextlarge(arr,i,n);

  }

  for(i=0;i<n;i++){
    printf("%d\t", result[i]);

  }

  printf("\n");



}