#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int min(int a, int b){
  if(a<b)
    return a;
  else
    return b;
}

int edits(char *a, char *b, int an, int bn){
  int dp[bn+1][an+1];
  int i,j;

  for(i=0;i<=bn;i++){
    for(j=0;j<=an;j++){
      if(i==0)
        dp[i][j]=j;
      else if(j==0)
        dp[i][j]=i;
    }
  }

  for(i=1;i<=bn;i++){
    for(j=1;j<=an;j++){
      if(a[j] != b[i]){
        dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j-1],dp[i-1][j]));
      }
      else{
        dp[i][j]=dp[i-1][j-1];
      }
    }
  }

  return dp[bn][an];
}

main(){
  char a[]="abcdef";
  char b[]="abdefgh";

  int an=strlen(a);
  int bn=strlen(b);

  int n=edits(a,b,an,bn);

  printf("%d\n", n);
}