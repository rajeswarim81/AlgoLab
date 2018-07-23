/*Given an integer N, how many structurally unique binary search trees are there that store values 1...N?*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



int bst(int n, int *sol){
  
  if(n<0)
    return 0;
  if(n==1 || n==0)
    return 1;

  else{
      int pos=0,i;

      for(i=0;i<n;i++){

        if(sol[i] == -1)
             sol[i]=bst(i,sol);

        if(sol[n-1-i] == -1)
             sol[n-1-i]=bst(n-1-i, sol);

        pos+=sol[i]*sol[n-1-i];         

        
      }

      return pos;
  }

}
main(){

  int k=3;
  int sol[k];
  int i;
  for(i=0;i<k;i++)
    sol[i]=-1;

  int n=bst(k,sol);
  //int n= k^k;
  printf("%d\n", n);
}