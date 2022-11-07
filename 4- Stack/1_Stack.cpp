#include <iostream>
using namespace std;

struct stack {
    int top;
    int size;
    int *arr;
};

struct stack *createStack(int cap) {
    struct stack *stk = (struct stack*)malloc(sizeof(struct stack));
    stk->top = -1;
    stk->size = cap;
    stk->arr = (int *)malloc(cap * sizeof(int));
    return stk;
}

void push(struct stack **stak, int item) {
    struct stack *ptr = *stak;
    if (ptr->top == (ptr->size - 1)) {
        cout << "Stack Overflow" << endl;
        return;
    }
    else {
        ptr->arr[(ptr->top) + 1] = item;
        ptr->top++;
    }
}

int pop(struct stack **stak) {
    struct stack *ptr = *stak;
    if (ptr->top == -1) {
        cout << "Underflow " << endl;
        return -1;
    }
    else {
        return (ptr->top--);
    }
}

int main() {
    int temp;
    struct stack *s = createStack(5);
    push(&s, 92);
    push(&s, 66);
    push(&s, 81);
    push(&s, 12);
    push(&s, 45);
    push(&s, 67);
    // temp = pop(&s);

    for (int i = s->top; i >=0; i--)
    {
        cout << s->arr[i] << endl;
    }
    
    return 0;
}