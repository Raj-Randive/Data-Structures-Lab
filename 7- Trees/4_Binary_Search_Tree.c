// BINARY SEARCH TREE
/*
           tree:

             5
           /   \
          3     6
         / \
        1   4

*/

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * left;
    struct node * right;
};

struct node * createNode(int data){
    struct node * newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inorder(struct node * root){
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int isBST(struct node * root){
    static struct node * prev = NULL;
    if (root != NULL)
    {
        if ( !isBST(root->left) ){
            return 0;
        }
        if (prev != NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
       
    }
    else{
        return 1;
    }
    
}


int main(){

    struct node * p = createNode(5);
    struct node * p1 = createNode(3);
    struct node * p2 = createNode(6);
    struct node * p3 = createNode(1);
    struct node * p4 = createNode(4);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    printf("\n");
    inorder(p);

    if (isBST(p) == 1)
    {
        printf("\n\nIt is a Binary Search Tree.");
    }
    else{
        printf("\n\nIt is NOT a Binary Search Tree.");
    }
    

    return 0;
}