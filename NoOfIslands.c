#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


void coverAll(int n, int arr[n][n], int visited[n][n], int i, int j){
	if(i >= n || i<0 ||j<0 || j>=n)
		return ;

	visited[i][j]=1;
	int r[]={-1,-1,-1,0,1,1,1,0};
	int c[]={-1,0,1,1,1,0,-1,-1};

	int k;
	for(k=0;k<8;k++)
	{
		if(arr[i+r[k]][j+c[k]] && !visited[i+r[k]][j+c[k]])
			coverAll(n, arr, visited, i+r[k], j+c[k]);
			
	}

}

int Islands(int n, int arr[n][n]){
	int visited[n][n];
	int i,j;
    int count=0;

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			visited[i][j]=0;
		}
	}

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			
			if(arr[i][j] && !visited[i][j]){
				count++;
				coverAll(n,arr, visited, i, j);

			}
		}
	}

	return count;
}

main(){
	printf("\nEnter the size nd the array: ");
	int n;
	scanf("%d\n", &n);

	int arr[n][n];
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d", &arr[i][j]);

		}
	}

	int p=Islands(n,arr);
	printf("Islands: %d\n", p);
}