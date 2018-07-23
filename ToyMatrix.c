#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* Given a matrix representing which child likes which toy.
matrix[i][j]=1 represents that child i likes toy j. One child can get only 1 toy and one toy can be assigned to only 1 child.Find maximum number of children who can get the toy they wished

*/

int findToy(int *arr, int n, int k){
  int i,j;
  int *priority[n][k]=(int*)malloc(sizeof(int)*n*k);
  int *row[n]=(int*)malloc(sizeof(int)*n);
  int *column[k]=(int*)malloc(sizeof(int)*k);



  for(i=0;i<n;i++){
    row[i] = 0;
    for(j=0;j<k;j++){
      if(arr[i][j]==1)
        *row[i]++;

    }
  }

  for(i=0;i<n;i++){
    *column[i]=0;
    for(j=0;j<k;j++){
      if(arr[i][j]==1)
        *column[j]++;

    }
  }

  for(i=0;i<n;i++0){
    for(j=0;j<k;j++){
      if(arr[i][j] == 1){
        *priority[i][j]= *row[i] + *column[j];

      }
    }
  }
}