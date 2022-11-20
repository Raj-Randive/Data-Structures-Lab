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

struct Node * deleteFirstNode(struct Node * head){
    
    struct Node * ptr = head;
    head = head->next;
    free(ptr);

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
    printf("\n Stack Traversal\n");
    LinkedListTraversal(head);
    printf("\n");

    // Push Operation
    printf("\n Push from Start Operation using List insertion.\n");
    head = insertAtFirst(head, 78);
    LinkedListTraversal(head);
    printf("\n");

    // Pop Operation
    printf("\n Pop from Start Operation using List insertion.\n");
    head = deleteFirstNode(head);
    LinkedListTraversal(head);
    printf("\n");


    return 0;
}
