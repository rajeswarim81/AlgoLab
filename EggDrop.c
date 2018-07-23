
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int max(int a, int b){
  if(a < b)
    return b;
  else
    return a;
}

int eggdrop(int n, int k){
  int dp[n+1][k+1];
  int i,j;

  for(i=0;i<=n;i++){
    dp[i][1]=1;
    dp[i][0]=0;
  }

  for(i=0;i<=k;i++){
    dp[1][i]=i;
  }

   int res,x;

  for(i=2;i<=n;i++){
    for(j=2;j<=k;j++){

      dp[i][j]=999;
      for(x=1;x<=j;x++){
        res=1+max(dp[i-1][x-1], dp[i][j-x]);
        if(res<dp[i][j])
          dp[i][j]=res;
      }
      
    }
  }

  return dp[n][k];
}
main(){
  int n=2, k=36;
  int p=eggdrop(n,k);
  printf("%d\n", p);
}