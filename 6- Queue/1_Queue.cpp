#include <iostream>
using namespace std;

struct Queue {
    int front,rear,cap;
    int* arr;
};

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

void displayQueue(struct Queue* q) {
    int i;
    if (q->front == -1) {
        cout << "\nQueue Empty: Underflow\n" << endl;
    }
    else if (q->front <= q->rear) {
        for (i=q->front; i<=q->rear; i++) {
            cout << q->arr[i] << " ";    
        }
    }
    else {
        for (i=q->front; i<q->cap; i++) {
            cout << q->arr[i] << " ";    
        }
        for (i=0; i<=q->rear; i++) {
            cout << q->arr[i] << " ";
        }
    }
}

int main() {
    struct Queue* q = createQueue(5);

    enQueue(q, 52);
    enQueue(q, 64);
    enQueue(q, 71);
    enQueue(q, 83);
    enQueue(q, 90);
    enQueue(q, 53); // Queue overflow condition

    deQueue(q);
    deQueue(q);
    deQueue(q);

    displayQueue(q);

    return 0;
}