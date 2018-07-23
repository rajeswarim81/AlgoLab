#include <iostream>
using namespace std;

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *create(int n){
	node *temp=new node;
	temp->data=n;
	temp->left=NULL;
    temp->right = NULL;
	return temp;
}


int sum(node *root){

	int s;
	s=0;
	if((!root->left ) && (!root->right))
		return root->data;
	else{

		int ls=sum(root->left);
		int rs=sum(root->right);

		s=ls+rs;
		cout<<"\t"<<s;

		if(root->data == s)
			return 2*s;
		else 
			return -1;

	}
}

main(){
	node *head=new node;
	head=create(26);
	head->left=create(10);
	head->right=create(3);
	head->left->left=create(4);
	head->left->right=create(6);
	head->right->left=create(1);
	head->right->right=create(2);

	if(2*(head->data) == sum(head))
		cout<<"\nSum TREE!!\n";
	else
		cout<<"\nNot a sum tree!!\n";
}