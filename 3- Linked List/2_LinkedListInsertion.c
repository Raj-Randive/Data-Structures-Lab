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

struct Node * insertAtFirst( struct Node * head, int data){

    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;

    return ptr;
}


struct Node * insertAtIndex( struct Node * head, int data, int index){
    struct Node * p1 = (struct Node *)malloc(sizeof(struct Node));
    
    struct Node * p = head;
    int i=0;
    while ( i != index-1 )
    {
        p = p->next;
        i++;
    }
    
    p1->data = data;
    p1->next = p->next;
    p->next = p1;

    return head;
}

struct Node * insertAtEnd( struct Node * head, int data){

    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    
    struct Node * p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }

    p->next = ptr;
    ptr->data = data;
    ptr->next = NULL;

    return head;
}

struct Node * insertAfterNode( struct Node * head, struct Node * prevNode, int data){

    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
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

    // Simple Traversal
    printf("\nLinked List Traversal\n");
    LinkedListTraversal(head);
    printf("\n");

    // // Insert at Start/First Node
    // printf("\nLinked List insertion at Start.\n");
    // head = insertAtFirst(head, 78);
    // LinkedListTraversal(head);
    // printf("\n");

    // Insert at index
    printf("\nLinked List insertion at index.\n");
    head = insertAtIndex(head, 83, 2);
    LinkedListTraversal(head);
    printf("\n");

    // // Insert at end
    // printf("\nLinked List insertion at the end.\n");
    // head = insertAtEnd(head, 69);
    // LinkedListTraversal(head);
    // printf("\n");

    // // Insert after a Node
    // printf("\nLinked List insertion after a Node.\n");
    // head = insertAfterNode(head, second, 99);
    // LinkedListTraversal(head);
    // printf("\n");

    return 0;
}
