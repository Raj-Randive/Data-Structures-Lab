/*

--> Binary Trees (Stack Data Structure is used.)
    1. Preorder --> Rlr
    2. Inorder --> lRr
    3. Postorder --> lrR

*/

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

int main()
{
    struct node * p = createNode(6); // Creating Root Node
    struct node * p1 = createNode(9); // Creating left Node
    struct node * p2 = createNode(3); // Creating right Node
    struct node * p3 = createNode(8);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    

    return 0;
}