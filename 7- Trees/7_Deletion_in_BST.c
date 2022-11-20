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

struct node * inOrderPredecessor(struct node * root){
    root = root->left;
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

struct node * deleteNode(struct node * root, int value){

    struct node * iPre;

    if(root == NULL){
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    

    // Search for the node to be deleted.
    if (value < root->data){
        deleteNode(root->left, value);
    }
    else if(value > root->data){
        deleteNode(root->right, value);
    }

    // Deleting the Node
    else{
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
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

    printf("\n -> Inorder Traversal : ");
    inorder(p);


    printf("\n\n -> Inorder Traversal after deletion: ");
    deleteNode(p, 6);
    inorder(p);
    // printf("\n\n%d " , p->right->right->data);

    return 0;
}