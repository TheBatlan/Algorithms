#include <bits/stdc++.h>
using namespace std;

class Queue {
private:
	// attributes of the queue
	int size, front, rear;
	// pointer for the array
	int* Q;

public:
	// constructing the queue
	Queue(int size) {
		this -> size = size + 1;
		this -> front = this -> rear = 0;
		Q = new int[this -> size];
	}
	// destructing the queue
	~Queue() {
		delete [] Q;
	}

	// operations on queue
	bool isEmpty() {
		return (this -> front == this -> rear);
	}

	bool isFull() {
		return ((this -> rear + 1) % this -> size) == this -> front;
	}

	void enqueue(int data) {
		if (isFull()) 
			cout << "Cannot perform enqueue\n";
		else {
			this -> rear = (this -> rear + 1) % this -> size;
			this -> Q[this -> rear] = data;
		}
	}

	int dequeue() {
		int x = -1;
		if (!isEmpty()) {
			this -> front = (this -> front + 1) % this -> size;
			x = this -> Q[this -> front];
		}
		return x;
	}

	int front_el() {
		int x = -1;
		if (!isEmpty()) {
			x = (this -> rear) % this -> size;
		}
		return x;
	}

	int rear_el() {
		int x = -1;
		if (!isEmpty()) {
			x = (this -> front + 1) % this -> size;
		}
		return x;
	}

	// displaying the queue
	void display_queue() {
		if (isEmpty()) 
			cout << "No elements to display\n";
		else {
			cout << "The Queue elements : ";
			int i = (this -> front + 1) % this -> size;
			while (i != (this -> rear + 1) % this -> size) {
				cout << this -> Q[i] << " ";
				i = (i + 1) % this -> size;
			} 
			cout << "\n";
		}
	}
};

int main() {

	// deploying the queue
	Queue q(5);

	// performing the operations on queue

	// enqueue
	q.enqueue(5);
	q.enqueue(4);
	q.enqueue(3);
	q.enqueue(2);
	q.enqueue(1);

	// display
	q.display_queue();

	// dequeue
	q.dequeue();
	q.dequeue();

	// display
	q.display_queue();

	// front and rear element
	cout << "First : " << q.front_el() << " \nRear : " << q.rear_el() << "\n";

	return 0;
}
