#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node{
    char data;
    struct node *left;
    struct node *right;
   // struct node *nextright;
}node;

struct node *newNode(char n){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=n;
    temp->left=NULL;
    temp->right = NULL;
  //  temp->nextright=NULL;

    return temp;
}

int min(int x,int y){
 /*   if(a<b)
        return a;
    else
        return b;
        */
    return (x < y)? x :y;
}

int closestDown( node *root){
    if(root==NULL)
        return 0;
    else if( !root->left && !root->right)
        return 0;
    else
        return 1+min(closestDown(root->left), closestDown(root->right));
}

int util(node *root, char key, int index, node *ancestors[]){
    if(root==NULL)
        return 9999;

   // printf("enterer");
    if(root->data == key){
        printf("enterer");
       int res=closestDown(root);
       printf("%d",res);


       int i;
       for(i=0;i<index;i++){
        res=min(res, index-i+closestDown(ancestors[i]));
        return res;
       }

       ancestors[index] = root;
       return min(util(root->left, key, index+1, ancestors),
                util(root->right, key, index+1, ancestors));
    }
}

int findClosest(node *root, char key){
    node *ancestors[100];

    return util(root, key, 0, ancestors);
}

main(){
    node *root        = newNode('A');
    root->left               = newNode('B');
    root->right              = newNode('C');
    root->right->left        = newNode('E');
    root->right->right       = newNode('F');
    root->right->left->left  = newNode('G');
    root->right->left->left->left  = newNode('I');
    root->right->left->left->right = newNode('J');
    root->right->right->right      = newNode('H');
    root->right->right->right->left = newNode('K');

    char k='H';
    char t='C';
    printf("%d\n",findClosest(root, k));
   // printf("%d", k==t);
}