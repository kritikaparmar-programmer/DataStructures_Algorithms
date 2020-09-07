// Stack implementation using array.

#include <iostream>

using namespace std;

#define MAX 1000

class Stack{
    int top;

public:
    int a[MAX];
    Stack (){
    top = -1;
    }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
    void display();
    };

bool Stack :: push(int x){
    if(top >= MAX-1){
        cout<<"Stack Overflow\n";
        return false;
    }
    else{
        top += 1;
        a[top] = x;
        cout<<x<<" "<<"is pushed into Stack\n";
        return true;

    }
}
int Stack :: pop(){
    if (top < 0){
        cout<<"Stack is Empty\n";
        return 0;
    }
    else{
        int x;
        x = a[top];
        top -= 1;
        return x;
    }
}

int Stack::peek(){
    if (top < 0){
        cout<<"Stack is Empty\n";
        return 0;
    }
    else{
        int x;
        x = a[top];
        return x;
    }
}

bool Stack::isEmpty(){
    return (top<0);
}

void Stack::display(){
    if (isEmpty()){
        cout<<"Stack is Empty\n";
        return ;
    }
    cout<<"Stack element: \n";
    for(int i=top; i>=0; i--){
        cout<<a[i]<<"\n";
    }
}

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    cout << s.pop() << " Popped from stack\n";
    s.push(40);
    s.push(60);
    s.display();
    return 0;
}
