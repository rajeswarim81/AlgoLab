/*Two player X and Y are playing a game in which there are pots of gold arranged in a  line, each containing some gold coins. They get alternating turns in which the player can pick a pot from one of the ends of the line. The winner is the player who has a higher number of coins at the end. The objective is to maximize the number of coins collected by X, assuming Y also plays optimally. You are required to complete the method maxCoins which returns an integer denoting the max coins X could get while playing the game. You may assume that X starts the game. 

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an integer denoting the no of gold pots. Then in the next line are N space separated values denoting the values (A[]) of gold coins in each pot.

Output:
For each test case in a new line print the maximum amount of money X can collect.
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int find_max(int *arr, int n){
	int i,j;
	int count=0;
	i=0;j=n-1;
    while(i<=j){
    	if(arr[i] > arr[j]){
    		count+=arr[i++];

    		if(arr[i] > arr[j])
    			i++;
    		else
    			j--;

    	}
    	else{
    		count+=arr[j++];
    		if(arr[i] > arr[j])
    			i++;
    		else
    			j--;

    	}

    }

    return count;
}

main(){
	int arr[]={8,15,2,7,29,5,6,3};
	int n=sizeof(arr)/sizeof(int);

	int nm=find_max(arr,n);
	printf("%d\n",nm);
}