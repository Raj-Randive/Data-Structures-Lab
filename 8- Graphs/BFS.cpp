#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>
 
struct Queue {
    int front,rear,cap;
    int* arr;
};

int isEmpty(struct Queue *q){
    if (q->front == -1)
    {
        return 1;
    }
    return 0;   
}

int isFull(struct Queue *q){
    if ((q->front == 0 && q->rear == (q->cap -1) ) || (q->rear == q->front-1))
    {
        return 1;
    }
    return 0;   
}

struct Queue* createQueue(int cap) {
    struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    queue->cap = cap;
    queue->arr = (int *)malloc(sizeof(int)*cap);
    return queue;
}

void enQueue(struct Queue* q, int item) {
    if ((q->front == 0 && q->rear == (q->cap -1) ) || (q->rear == q->front-1)) {
        cout << "\nQueue Full: Overflow" << endl;
    }
    else if (q->rear == q->cap - 1) {
        q->rear = 0;
        q->arr[q->rear] = item;
    }
    else if (q->rear == -1) {
        q->rear = 0;
        q->front = 0;
        q->arr[q->rear] = item;
    }
    else {
        q->rear += 1;
        q->arr[q->rear] = item;
    }
}

int deQueue(struct Queue* q) {
    int item;
    if (q->front == -1) {
        cout << "\nQueue Empty: Underflow" << endl;
        return 0;
    }
    else if (q->front == q->rear) {
        item = q->arr[q->front];
        q->front = -1;
        q->rear = -1;
    }
    else if (q->front == q->cap - 1) {
        item = q->arr[q->front];
        q->front = 0;
    }
    else {
        item = q->arr[q->front];
        q->front += 1;
    }
    return item;
}
 
int main(){
    struct Queue* q = createQueue(5);
    // *****************************************************

    int node;

    int i = 5;

    int visited[7] = {0,0,0,0,0,0,0};
    int a [7][7] = {
        {0,0,1,1,0,0,0},
        {0,0,1,0,0,1,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,0,0,0},
        {0,0,1,0,0,0,1},
        {0,1,0,0,0,0,0}, 
        {0,0,0,0,1,0,0} 
    };
    printf("%d ", i);
    
    visited[i] = 1;

    enQueue(q, i);

    while (!isEmpty(q))
    {
        int node = deQueue(q);
        for (int j = 0; j < 7; j++)
        {
            if(a[node][j] == 1 && visited[j] == 0){
                printf("%d ", j);
                visited[j] = 1;
                enQueue(q, j);
            }
        }
    }
    return 0;
}