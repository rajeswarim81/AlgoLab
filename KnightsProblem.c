#include <stdio.h>

int n=8;
void printsol(int sol[n][n]);

int check(int nextx, int nexty, int sol[n][n]){
	if(nextx >=0 && nexty >=0 && nextx<n && nexty <n && (sol[nextx][nexty] == -1))
			return 1;

	else
	 return 0;	
}

int util(int xi, int yj, int move, int x[8], int y[8], int sol[n][n]){
	if(move == n*n)
		return 1;
	
		int k;
		int nextx, nexty;

		for(k=0; k<8; k++){

			nextx=xi+ x[k];
			nexty=yj +y[k];

			if(check(nextx, nexty, sol)){
				sol[nextx][nexty]=move;

				if( util(nextx, nexty, move+1, x,y,sol))
					return 1;
				else
					sol[nextx][nexty]=-1;

			}


		}

		return 0;
	
}

void solveKT(){
	int sol[n][n];

	int i,j;

	for(i=0; i<n;i++){
		for(j=0;j<n;j++){
			sol[i][j]=-1;
		}
	}

	int x[]={1,2,2,1,-1,-2,-2,-1};
	int y[]={2,1,-1,-2,-2,-1,1,2};

	sol[0][0]=0;

	if(util(0,0,1,x,y,sol) == 0)
		printf("\\nsoln doesn't exist! \n");
	else
		printsol(sol);
}

void printsol(int sol[n][n]){
	int i,j;


	for(i=0; i<n;i++){
		for(j=0;j<n;j++){
			printf("%d\t", sol[i][j]);
		}
		printf("\n");
	}

}

main(){
	solveKT();
	return 0;

}