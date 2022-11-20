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
    int n1, n2, n3, n4;

    struct Node * head = createNode();
    struct Node * second = createNode();
    struct Node * third = createNode();
    struct Node * fourth = createNode();

    printf("Enter the element - 1 of the Linked List: ");
    scanf("%d", &n1);
    printf("Enter the element - 2 of the Linked List: ");
    scanf("%d", &n2);
    printf("Enter the element - 3 of the Linked List: ");
    scanf("%d", &n3);
    printf("Enter the element - 4 of the Linked List: ");
    scanf("%d", &n4);
    
    

    head->data = n1;
    head->next = second;

    second->data = n2;
    second->next = third;

    third->data = n3;
    third->next = fourth;

    fourth->data = n4;
    fourth->next = NULL;  

    printf("\n");
    LinkedListTraversal(head);
    printf("\n\n");

    return 0;
}