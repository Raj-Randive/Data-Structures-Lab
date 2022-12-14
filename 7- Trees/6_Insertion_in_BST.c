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

void insert(struct node * root, int key){
    struct node * prev =  NULL;

    while (root != NULL){
        prev = root;
        if (key == root->data){
            return;
        }
        else if(key < root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }

    struct node * new = createNode(key);
    if (key < prev->data)
    {
        prev->left = new;
    }
    else{
        prev->right = new;
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

    printf("\n -> Inorder Traversal : ");
    inorder(p);


    printf("\n\n -> Inorder Traversal after insertion: ");
    insert(p, 2);
    inorder(p);
    // printf("\n\n%d " , p->right->right->data);

    return 0;
}