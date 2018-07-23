/*Given two numbers ‘a’ and b’. Write a program to count number of bits needed to be flipped to convert ‘a’ to ‘b’. */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int bits(int a, int b){
  int n=a^b;

  int count=0;
  while(n){
    count += n&1;
    n=n>>1;
  }
  return count;
}

main(){
  int a=10, b=20;

  printf("%d\n", bits(a,b));
}