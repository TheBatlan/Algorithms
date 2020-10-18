#include <bits/stdc++.h>
using namespace std;

class Stack {
private:
    int top, size;
    int* S;
public:
    Stack(int size) {
        this -> size = size;
        this -> top = -1;
        this -> S = new int[this -> size];
    }

    ~Stack() {
        delete [] S;
    }

    bool isEmpty();
    bool isFull();
    void push(int data);
    int pop();
    int stackTop();
    int peek(int pos);
    void display();
};

bool Stack::isEmpty() {
    return this -> top == -1;
}

bool Stack::isFull() {
    return this -> top == this -> size - 1;
}

void Stack::push(int data) {
    if (!isFull()) {
        this -> top++;
        this -> S[this -> top] = data;
    }
}

int Stack::pop() {
    int x = -1;
    if (!isEmpty()) {
        x = this -> S[this -> top--];
    }
    return x;
}

int Stack::stackTop() {
    int x = -1;
    if (!isEmpty()) {
        x = this -> S[this -> top];
    }
    return x;
}

int Stack::peek(int pos) {
    int x = -1;
    if (!(this -> top - pos + 1 < 0 || pos == 0)) {
        x = this -> S[this -> top - pos + 1];
    }
    return x;
}

void Stack::display() {
    if(!isEmpty()) {
        for (int i = this -> top; i >= 0; i--) {
            cout << this -> S[i] << " ";
        } 
        cout << "\n";
    }
}
