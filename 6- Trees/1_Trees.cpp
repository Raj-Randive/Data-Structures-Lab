/*

--> Binary Trees (Stack Data Structure is used.)
    1. Preorder --> Rlr
    2. Inorder --> lRr
    3. Postorder --> lrR

*/

#include<iostream>
using namespace std;

int s, top, x, i;
int *stackarr = new int[s];

void push(){
    if(top >= (s-1)){
        cout << "\n\t Stack Overflow" << endl;
    }
    else{
        cout << "  Enter the value to be pushed: ";
        cin >> x;
        top++;
        stackarr[top] = x;
    }
}

void pop(){
    if(top<=-1){
        cout << "\n\t Stack Underflow";
    }
    else{
        cout << "\n\t The popped element is: " << stackarr[top] << endl;
        top--;
    }
}

void display()
{
    if(top>=0){
        cout<<"\n";
        cout << "\n\n The elements in Stack are : \n";
        for(i = top; i >= 0; i--){
            cout << stackarr[i] << endl;
        }
        cout << "\n Press Next Choice\n";
    }
    else{
        cout << "\n The Stack is empty";
    }
}


int main()
{
    int choice;
    top = -1;
    cout << "\n> Enter the size of Stack: ";
    cin >> s;
    cout << "\nSTACK OPERATIONS USING ARRAY";
    cout << "\n--------------------------------";
    cout << "\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EXIT\n";

    do
    {
        cout << "\n> Enter the Choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                cout << "\n\n  EXIT POINT ";
                break;
            }
            default:
            {
                cout << "\n\t Please Enter a Valid Choice(1/2/3/4)";
            }
                
        }
    }
    while(choice!=4);
    

    return 0;
}