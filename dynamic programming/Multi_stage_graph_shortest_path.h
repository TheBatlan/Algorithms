#include <bits/stdc++.h>
using namespace std;

class MultiStageGraph {
private:
    int V, stages;
    int *cost, *d, *path;
    int** graph;
public:
    MultiStageGraph(int V, int stages) {
        this -> V = V;
        this -> stages = stages;

        // getting the matrix input
        this -> graph = new int*[this -> V + 1];
        cout << "***Enter 0 if there is no edge***\n";
        cout << "Enter the Adjacency Matrix data (" << this -> V + 1 << "x" << this -> V + 1 << "): \n";
        for (int i = 0; i <= this -> V; i++) {
            this -> graph[i] = new int[this -> V + 1];
            for (int j = 0; j <= this -> V; j++) {
                cin >> this -> graph[i][j];
            }
        }

        // arrays for data
        this -> cost = new int[V + 1];
        this -> d = new int[V + 1];
        this -> path = new int[stages + 1];

        // initial modifications
        int i, j, min;
        this -> cost[this -> V] = 0;
        this -> d[this -> V] = V;

        // running the dynamic programming
        for (i = this -> V - 1; i >= 1; i--) {
            min = INT32_MAX;
            for (j = i + 1; j <= this -> V; j++) {
                // getting the minimum cost
                if ((this -> graph[i][j] != 0) && (this -> graph[i][j] + this -> cost[j]) < min) {
                    min = this -> graph[i][j] + this -> cost[j];
                    this -> d[i] = j;
                }
            }
            // assigning the minimum cost
            this -> cost[i] = min;
        }

        // assigning the path
        this -> path[1] = 1;
        this -> path[this -> stages] = V;
        for (i = 2; i < this -> stages; i++) {
            this -> path[i] = this -> d[this -> path[i - 1]];
        }
    }

    // printing the path
    void shortest_path() {
        cout << "The Shortest Path is : ";
        for (int i = 1; i <= this -> stages; i++) {
            cout << this -> path[i] << " ";
        }
        cout << "\n";
    }

    ~MultiStageGraph() {
        delete [] cost;
        delete [] path;
        delete [] d;

        for (int i = 0; i <= this -> V; i++) {
            delete [] graph[i];
        }
        delete [] graph;
    }
};
