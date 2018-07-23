/*You are given two integer numbers , the base a (number of digits d, such that 1 <= d <= 1000) and the index b (0 <= b <= 922*10^15). You have to find the last digit of a^b.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int power(int a, int b){
  int c=b%4;
  int k=a%10;
  int d=pow(k,c);
  return d%10;
}

main(){

  int a=59,b=3;
  printf("%d\n", power(a,b));
}