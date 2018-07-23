/*Given a binary tree and two node values your task is to find the minimum distance between them.

Input:
The task is to complete the fuction findDist which takes 3 argument, the  root of the  Binary Tree and two node values a and b .
There are multiple test cases. For each test case, this method will be called individually.*/


#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node *create(int n){
	node *temp=(node*)malloc(sizeof(node));
	temp->data=n;
	temp->left=NULL;
    temp->right = NULL;
	return temp;
}

node *distance(node *root, int a, int b, int &d1, int &d2, int &dist, int level){
	if(root== NULL)
		return NULL;
	else if(root->data == a){
		d1=level;
		return root;
	}
	else if(root->data == b){
		d2=level;
		return root;
	}
	else{

		node *leftlca=distance(root->left,a,b,d1,d2,dist,level+1);
		node *rightlca=distance(root->right,a,b,d1,d2,dist,level+1);

		if(leftlca && rightlca){
			dist= d1+d2 - 2*level;
			//cout<<level;
			return root;
		}

		else if(!leftlca)
			return leftlca;
		else
			return rightlca;
	}
}

int findLevel(node *root, int k, int level)
{
    // Base Case
    if (root == NULL)
        return -1;
 
    // If key is present at root, or in left subtree or right subtree,
    // return true;
    if (root->data == k)
        return level;
 
    int l = findLevel(root->left, k, level+1);
    return (l != -1)? l : findLevel(root->right, k, level+1);
}


int find_dist(node *root, int a, int b){
	int d1,d2,dist,level;

	d1=-1;
	d2=-1;
	level=0;
	//dist=0;

	node *lca= distance(root, a,b,d1,d2,dist,1);
	//if(!lca)
	// cout<<5;

	//cout<<dis;

	if(d1 != -1 && d2 != -1){
		//return dist;
		//cout<<dist;
		return dist;
	}

	 if (d1 != -1)
    {
        dist = findLevel(lca, b, 0);
        cout<<dist;
        return dist;
    }
 
    // If n2 is ancestor of n1, consider n2 as root and find level 
    // of n1 in subtree rooted with n2
    if (d2 != -1)
    {
        dist = findLevel(lca, a, 0);
        cout<<dist;
        return dist;
    }

    cout<<"\nend\n";
    return -1;
}

main(){
	node*head=create(2);
	head->left=create(1);
	head->right=create(4);
	//head->right->right=create(16);
	head->right->right=create(3);

	//in n= findDist(head,2,3);
	int n=find_dist(head,1,3);
	cout<<"\n";
	cout<<n;

}