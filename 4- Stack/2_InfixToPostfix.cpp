#include <iostream>
#include <string> 
using namespace std;

struct stack {
    int top;
    int size;
    char *arr;
};

struct stack *createStack(int cap) {
    struct stack *stk = (struct stack*)malloc(sizeof(struct stack));
    stk->top = -1;
    stk->size = cap;
    stk->arr = (char *)malloc(cap * sizeof(char));
    return stk;
}

void push(struct stack **stak, char item) {
    struct stack *ptr = *stak;
    if (ptr->top == (ptr->size - 1)) {
        cout << "Overflow";
        return;
    }
    else {
        ptr->arr[(ptr->top) + 1] = item;
        ptr->top++;
    }
}

void pop(struct stack **stak) {
    struct stack *ptr = *stak;
    if (ptr->top == -1) {
        cout << "Underflow";
        return;
    }
    else {
        (ptr->top)--;
        //return (stk_ref->top--); //Only delete dont return
        return;
    }
}

int prec(char c) {
    if (c == '^') {
        return 4; 
    }
    else if (c == '/' || c == '*') {
        return 3;
    }
    else if (c == '+' || c == '-') {
        return 2;
    }
    else {
        return 1;
    }
}

void infixToPostfix(string s) {
    struct stack *stak = createStack(s.length());
    string result;
    
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
 
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            result += c;
        }
 
        else if (c == '(') {
            push(&stak, '(');
        }
        
        else if (c == ')') {
            while ( stak->arr[stak->top] != '('  ) {
                result += stak->arr[stak->top];
                pop(&stak);
            }
            pop(&stak);
        }
 
        else {
            while ( !(stak->top == (stak->size - 1)) && prec(s[i]) <= prec(stak->arr[stak->top])) {
                result += stak->arr[stak->top];
                pop(&stak);
            }
            push(&stak, c);
        }
    }
 
    while ( !(stak->top == -1)) {
        result += stak->arr[stak->top];
        pop(&stak);
    }
    cout << result << endl;
}
 
 int main()
{
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(exp);
    return 0;
}
    