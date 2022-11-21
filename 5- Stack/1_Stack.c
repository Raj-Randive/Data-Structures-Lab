#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

struct stack *createStack(int cap) {
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    s->top = -1;
    s->size = cap;
    s->arr = (int *)malloc(cap * sizeof(int));
    return s;
}

int isEmpty(struct stack * ptr){
    if(ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct stack * ptr){
    if( ptr->top == ptr->size - 1 ){
        return 1;
    }
    else{
        return 0;
    }
}

int peek(struct stack* sp, int i){
    int arrayInd = sp->top -i + 1;
    if(arrayInd < 0){
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else{
        return sp->arr[arrayInd];
    }
}

void push(struct stack * ptr, int value){
    if(isFull(ptr)){
        printf("Stack overflow! Cannot push %d to the stack.", value);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

int pop(struct stack * ptr){
    if(isEmpty(ptr)){
        printf("Stack underflow!");
        return -1;
    }
    else{
        int value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

void printStack(struct stack * sPointer){
    for (int i = sPointer->top; i >=0; i--)
    {
        printf("%d \n", sPointer->arr[i]);
    } 
}

int main(){

    int temp;
    struct stack * s1 = createStack(5);

    push(s1, 37);
    push(s1, 87);
    push(s1, 44);
    push(s1, 21);
    push(s1, 90);
    // push(s1, 22);

    temp = pop(s1);

    printStack(s1);

    printf("\n\n%d " ,peek(s1, 2));

    return 0;
}