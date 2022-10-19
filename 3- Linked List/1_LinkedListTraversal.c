#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void LinkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        if (ptr->next == NULL){
            printf("%d -> NULL", ptr->data);
        }
        else{
            printf("%d -> ", ptr->data);
        }
        
        ptr = ptr->next;
    }
}

struct Node * createNode(){

    // Allocate memory for nodes in the linked list in Heap.
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    return newNode;
}

int main()
{

    struct Node * head = createNode();
    struct Node * second = createNode();
    struct Node * third = createNode();
    struct Node * fourth = createNode();
    
    head->data = 18;
    head->next = second;

    second->data = 12;
    second->next = third;

    third->data = 53;
    third->next = fourth;

    fourth->data = 35;
    fourth->next = NULL;  

    printf("\n");
    LinkedListTraversal(head);
    printf("\n\n");

    return 0;
}