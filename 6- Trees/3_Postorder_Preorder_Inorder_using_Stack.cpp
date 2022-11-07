#include <iostream>
#include <stack>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *n; // Node pointer
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}

void preorder(struct node *root)
{
    stack<node *> s1;
    node *ptr = root;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        if (ptr->right != NULL)
        {
            s1.push(ptr->right);
        }
        if (ptr->left != NULL)
        {
            ptr = ptr->left;
        }
        else if (!s1.empty())
        {
            ptr = s1.top();
            s1.pop();
        }
        else
        {
            break;
        }
    }
}

void inorder(struct node *root){

    stack<node *> s2;
    node *ptr = root;
    
    label:
    while (ptr != NULL)
    {
        s2.push(ptr->left);
        s2.top() = ptr;
        ptr = ptr->left;
    }

    ptr = s2.top();
    s2.pop();

    while(ptr != NULL){

        cout << ptr->data << " ";
        
        if(ptr->right != NULL){
            ptr = ptr->right;
            goto label;
        }

        ptr = s2.top();
        s2.pop();
    }

}

void postorder(struct node *root){

    stack<node*> s3;
    node *ptr = root;

    label:
    while(ptr != NULL){
        s3.push(ptr->left);
        s3.top() = ptr;
        if (ptr->right != NULL){
            s3.push(NULL);
        }
        ptr = ptr->left;
    }

    ptr = s3.top();
    s3.pop();

    while(ptr != NULL && !(s3.empty())){
        cout << ptr->data << " ";
        ptr = s3.top();
        s3.pop();
    }
    if(!(s3.empty())){
        ptr = s3.top();
        ptr = ptr->right;
        goto label;
    }
    else{
        cout << ptr->data << " ";
    }

}


int main()
{
    struct node *p = createNode(4);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(5);
    struct node *p4 = createNode(2);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    cout << "\nPostorder Traversal: ";
    postorder(p);

    cout << "\nPreorder Traversal: ";
    preorder(p);

    cout << "\nInorder Traversal: ";
    inorder(p);


    return 0;
}

/*
           tree:

             4
           /   \
          1     6
         / \
        5   2

*/