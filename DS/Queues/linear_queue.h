#include <bits/stdc++.h>
using namespace std;

class Queue {
private:
    int front, rear, size;
    int* Q;

public:
    Queue(int size) {
        this -> size = size;
        this -> front = this -> rear = -1;
        this -> Q = new int[this -> size];
    }

    ~Queue() {
        delete [] Q;
    }

    bool isEmpty();
    bool isFull();
    void enqueue(int data);
    int dequeue();
    void display_queue();
    int front_el();
    int rear_el();
};

bool Queue::isEmpty() {
    return (this -> front == this -> rear);
}

bool Queue::isFull() {
    return (this -> rear == this -> size - 1);
}

void Queue::enqueue(int data) {
    if (!isFull()) {
        this -> rear++;
        this -> Q[this -> rear] = data;
    }
}

int Queue::dequeue() {
    int x = -1;
    if (!isEmpty()) {
        this -> front++;
        x = this -> Q[this -> front];
    } 
    return x;
}

void Queue::display_queue() {
    if (isEmpty()) {
        cout << "The Queue is empty\n";
    } else {
        cout << "The Queue is : ";
        for (int i = this -> front + 1; i <= this -> rear; i++) {
            cout << this -> Q[i] << " ";
        }
        cout << "\n";
    }
}

int Queue::front_el() {
    int x = -1;
    if (!isEmpty()) {
        x = this -> Q[this -> front];
    }
    return x;
}

int Queue::rear_el() {
    int x = -1;
    if (!isEmpty()) {
        x = this -> Q[this -> rear];
    }
    return x; 
}
