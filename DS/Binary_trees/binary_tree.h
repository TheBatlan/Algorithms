#include <iostream>
using namespace std;

/* Node for storing data of binary tree */

class Node {
public:
	Node* lchild;
	int data;
	Node* rchild;
};

/* Linear queue */

class Queue {
private:
	int size, front, rear;
	Node** Q;

public:
	Queue() {
		this -> size = 100;
		this -> front = this -> rear = -1;
		this -> Q = new Node*[this -> size];
	}

	bool isEmpty();
	void enqueue(Node* addr);
	Node* dequeue();
};

bool Queue::isEmpty() {
	return (this -> front == this -> rear);
}

void Queue::enqueue(Node* addr) {
	if (this -> rear == this -> size - 1) 
		cout << "Queue is full\n";
	else {
		this -> rear++;
		this -> Q[this -> rear] = addr;
	}
}

Node* Queue::dequeue() {
	Node* x = NULL;
	if (this -> front == this -> rear) 
		cout << "Queue is empty\n";
	else {
		x = this -> Q[this -> front + 1];
		this -> front++;
	}
	return x;
}

/* Tree */

class Tree {
private:
	Node* root;

public:
	Tree() {
		root = nullptr;
	}

	void create() {
		Node *p, *t;
		Queue q;

		int x;
		cout << "Enter the root value: ";
		cin >> x;

		if (x != -1) {
			root = new Node;
			root -> data = x;
			root -> lchild = root -> rchild = nullptr;
		}

		q.enqueue(root);

		while (!q.isEmpty()) {
			// getting the last parent address
			p = q.dequeue();

			// left child
			cout << "Enter the left child of " << p -> data << " : ";
			cin >> x;

			if (x != -1) {
				t = new Node;
				t -> data = x;
				t -> lchild = t -> rchild = nullptr;
				p -> lchild = t;
				q.enqueue(t);
			}

			// right child
			cout << "Enter the right child of " << p -> data << " : ";
			cin >> x;

			if (x != -1) {
				t = new Node;
				t -> data = x;
				t -> lchild = t -> rchild = nullptr;
				p -> rchild = t;
				q.enqueue(t);
			}
		}
	}

	void preorder() {
		cout << "Preorder traversal : ";
		preorder(root);
		cout << "\n";
	}

	void preorder(Node* p) {
		if (p) {
			cout << p -> data << " ";
			preorder(p -> lchild);
			preorder(p -> rchild);
		}
	} 

	void inorder() {
		cout << "Inorder traversal : ";
		inorder(root);
		cout << "\n";
	}

	void inorder(Node* p) {
		if (p) {
			inorder(p -> lchild);
			cout << p -> data << " ";
			inorder(p -> rchild);
		}
	} 

	void postorder() {
		cout << "Postorder traversal : ";
		postorder(root);
		cout << "\n";
	}

	void postorder(Node* p) {
		if (p) {
			postorder(p -> lchild);
			postorder(p -> rchild);
			cout << p -> data << " ";
		}
	} 

	void levelorder() {
		cout << "Level-order traversal : ";
		levelorder(root);
		cout << "\n";
	}

	void levelorder(Node* p) {
		Queue q;
		q.enqueue(p);
		cout << p -> data << " ";
		while (!q.isEmpty()) {
			p = q.dequeue();
			if (p -> lchild) {
				cout << p -> lchild -> data << " ";
				q.enqueue(p -> lchild);
			}
			if (p -> rchild) {
				cout << p -> rchild -> data << " ";
				q.enqueue(p -> rchild);
			}
		}	
	}

	int height() {
		return height(root) - 1;
	}

	int height(Node* p) {
		int x = 0, y = 0;
		if (p == nullptr) 
			return 0;
		x = height(p -> lchild);
		y = height(p -> rchild);

		if (x > y) return x + 1;
		else return y + 1;
	}
};
