#include <bits/stdc++.h>
using namespace std;

class APSP {
private:
    int** graph;
    int V;
    int I = INT32_MAX;

public:
    APSP(int V) {
        this -> V = V;
        this -> graph = new int*[this -> V + 1];

        // getting the data
        cout << "***Enter 0 if there is no direct edge***\n";
        cout << "Enter the data for Adjacency Matrix: (" << this -> V + 1 << "x" << this -> V + 1 << "):\n";
        for (int i = 0; i <= this -> V; i++) {
            this -> graph[i] = new int[this -> V + 1];
            for (int j = 0; j <= this -> V; j++) {
                cin >> this -> graph[i][j];
                // if 0, then no direct edge, only I
                if (this -> graph[i][j] == 0) this -> graph[i][j] = this -> I;
                // no self loops
                if (i == j) this -> graph[i][j] = 0;
            }
        }

        // finding the shortest path
        int i, j, k;
        // for kth vertex
        for (k = 1; k <= this -> V; k++) {

            // modifying the entire matrix once
            for (i = 1; i <= this -> V; i++) {
                for (j = 1; j <= this -> V; j++) {
                    // self loop portion and the current vertex portion has to be neglected
                    if (i == j || i == k || j == k) 
                        continue;
                    else {
                        if ((this -> graph[i][k] != this -> I && this -> graph[k][j] != this -> I) && (this -> graph[i][k] + this -> graph[k][j]) < this -> graph[i][j]) {
                            this -> graph[i][j] = this -> graph[i][k] + this -> graph[k][j];
                        }
                    }
                }
            }

        }
    }

    void shortest_path() {
        cout << "The Shortest Path for the given graph:\n";
        for (int i = 1; i <= this -> V; i++) {
            for (int j = 1; j <= this -> V; j++) {
                cout << this -> graph[i][j] << " ";
            }
            cout << "\n";
        }
    }

    ~APSP() {
        for (int i = 0; i <= this -> V; i++) {
            delete [] this -> graph[i];
        }
        delete [] this -> graph;
    }
};
