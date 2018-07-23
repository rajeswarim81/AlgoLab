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


void swap(char *a, char *b){
  char temp= *a;
  *a=*b;
  *b=temp;
}

/*void print(char *arr,int l, int r){

  if( l==r)
    printf("%s\n",arr);
  else{
    int i;
    for(i=l;i<=r;i++){

      swap((arr+l),(arr+i));
      print(arr,l+1,r);
      swap((arr+i),(arr+l));

    }
  }

}
*/

void permute(char *a, int l, int r)
{
   int i;
   if (l == r)
     printf("%s\t", a);
   else
   {
       for (i = l; i <= r; i++)
       {
          swap((a+l), (a+i));
          permute(a, l+1, r);
          swap((a+l), (a+i)); //backtrack
       }
   }
}
main(){

  char arr[]="abc";
  int n=strlen(arr);
 // int n=sizeof(arr)/sizeof(char);
  printf("%d\n", n);
  permute(arr,0,n-1);

  printf("\n");



}