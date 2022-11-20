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

struct node * search(struct node * root, int key){
    if (root == NULL){
        return NULL;
    }
    if( root->data == key){
        return root;
    }
    else if( key < root->data){
        return search(root->left , key);
    }
    else{
        return search(root->right , key);
    }  
} 

struct node * searchIter(struct node * root, int key){
    while(root != NULL){
        if( key == root->data){
        return root;
        }
        else if( key < root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }

    }
    return NULL;
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

    // struct node * pointer = search(p, 8);
    struct node * pointer = searchIter(p, 10);

    if ( pointer != NULL){
        printf("\n -> Found : %d ", pointer->data);
    }
    else{
        printf("\n -> Element NOT found");
    }

    return 0;
}