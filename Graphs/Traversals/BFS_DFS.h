#include <bits/stdc++.h>
using namespace std;

/* Queue for BFS */
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

class Traversals {
private:
    int V, src;
    int** graph;

public:
    Traversals(int V, int src) {
        this -> V = V;
        this -> src = src;
        this -> graph = new int*[this -> V + 1];
        cout << "Enter the adjacency matrix data: (" << this -> V + 1 << "x" << this -> V + 1 << "):\n";
        cout << "***Enter 0, if there is no edge***\n";
        for (int i = 0; i <= this -> V; i++) {
            this -> graph[i] = new int[this -> V + 1];
            for (int j = 0; j <= this -> V; j++) {
                cin >> this -> graph[i][j];
            }
        }
    }

    /* BFS */
    void BFS() {
        Queue q(this -> V);
        int u;
        bool visited[this -> V + 1];
        for (int i = 0; i <= this -> V; i++) 
            visited[i] = false;

        cout << "BFS Traversal:\t";
        cout << this -> src << " ";
        visited[this -> src] = true;
        q.enqueue(this -> src);

        while (!q.isEmpty()) {
            u = q.dequeue();

            for (int v = 1; v <= this -> V; v++) {
                if (this -> graph[u][v] && visited[v] == false) {
                    q.enqueue(v);
                    visited[v] = true;
                    cout << v << " ";
                }
            }
        }
        cout << "\n";
    }

    /* DFS */
    void DFS() {
        cout << "DFS Traversal:\t";
        DFS(this -> src);
        cout << "\n";
    }
    void DFS(int src) {
        // static array size can be checked accrdingly
        static int visited[50] = {0};
        int v;
        if (visited[src] == 0) {
            cout << src << " ";
            visited[src] = 1;
            for (v = 1; v <= this -> V; v++) {
                if (this -> graph[src][v] && visited[v] == 0) {
                    DFS(v);
                }
            }
        }
    }
};

