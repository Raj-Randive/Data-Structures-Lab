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


struct Node * deleteFirstNode(struct Node * head){
    
    struct Node * ptr = head;
    head = head->next;
    free(ptr);

    return head; 
}

struct Node * deleteAtIndex(struct Node * head, int index){

    struct Node * p = head;
    struct Node * q = head->next;

    int i=0;
    while (i != index-1)
    {
        p = p->next;
        q = q->next;
        i++;
    }

    p->next = q->next;
    free(q);

    return head;
}


struct Node * deleteEndNode(struct Node * head){

    struct Node * p = head;
    struct Node * q = head->next;

    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);

    return head;
}

struct Node * deleteWithGivenValue(struct Node * head, int value){

    struct Node * p = head;
    struct Node * q = head->next;

    while (q->data != value  && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    if (q->data == value){
        p->next = q->next;
        free(q);
    }
    else{
        printf("\nThe value NOT found in the linked list.\n");
    }
    
    return head;
}

int main()
{

    struct Node * head = createNode();
    struct Node * second = createNode();
    struct Node * third = createNode();
    struct Node * fourth = createNode();
    struct Node * fifth = createNode();
    struct Node * sixth = createNode();
    
    head->data = 18;
    head->next = second;

    second->data = 12;
    second->next = third;

    third->data = 53;
    third->next = fourth;

    fourth->data = 35;
    fourth->next = fifth;  
    
    fifth->data = 78;
    fifth->next = sixth;  
    
    sixth->data = 81;
    sixth->next = NULL;  

    // Simple Traversal
    printf("\nLinked List Traversal\n");
    LinkedListTraversal(head);
    printf("\n");

    // Delete the first Node.
    printf("\nLinked List deletion at Start.\n");
    head = deleteFirstNode(head);
    LinkedListTraversal(head);
    printf("\n");

    // Delete the a Node at index.
    printf("\nLinked List deletion at Index.\n");
    head = deleteAtIndex(head, 2);
    LinkedListTraversal(head);
    printf("\n");

    // Delete the end Node.
    printf("\nLinked List deletion at the end.\n");
    head = deleteEndNode(head);
    LinkedListTraversal(head);
    printf("\n");

    // Delete a Node with given Value.
    printf("\nLinked List deletion with a given value.\n");
    head = deleteWithGivenValue(head, 78);
    LinkedListTraversal(head);
    printf("\n");

    return 0;
}