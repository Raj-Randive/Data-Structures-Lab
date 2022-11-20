#include<iostream>
using namespace std;

struct node{
    int data;
    struct node * left;
    struct node * right;

};

struct node * createNode(int data){
    struct node * n;  // Node pointer
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}

void preorder(struct node * root){
    if(root != NULL){
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node * root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

void inorder(struct node * root){
    if(root != NULL){
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main()
{
    struct node * p = createNode(4);
    struct node * p1 = createNode(1);
    struct node * p2 = createNode(6); 
    struct node * p3 = createNode(5);
    struct node * p4 = createNode(2);
    struct node * p5 = createNode(8);
    struct node * p6 = createNode(2);
    struct node * p7 = createNode(7);
    struct node * p8 = createNode(9);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p2->right = p6;
    p3->left = p7;
    p3->right = p8;

    cout << "\nPreorder Traversal: ";
    preorder(p);

    cout << "\nPostorder Traversal: ";
    postorder(p);

    cout << "\nInorder Traversal: ";
    inorder(p);
    
    return 0;
}

/* 
           tree:

             4
           /   \
          1     6
         / \   / \
        5   2 8   2
       / \  
      7   9
      
*/