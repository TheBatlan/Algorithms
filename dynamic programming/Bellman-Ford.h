#include <bits/stdc++.h>
using namespace std;

class BellmanFord {
private:
    int **cost;
    int V, src, I;
    int* dist;

public:
    BellmanFord(int V, int src) {
        this -> V = V;
        this -> src = src;
        this -> I = INT32_MAX;
        this -> dist = new int[this -> V + 1];
        this -> cost = new int*[this -> V + 1];

        cout << "***Enter 0, if there is no edge***\n";
        cout << "Enter the data matrix (" << this -> V + 1 << "x" << this -> V + 1 << "): \n";
        for (int i = 0; i <= this -> V; i++) {
            this -> cost[i] = new int[this -> V + 1];
            for (int j = 0; j <= this -> V; j++) {
                cin >> this -> cost[i][j];
            }
        }

        int i, j, k;
        for (i = 1; i <= this -> V; i++) 
            this -> dist[i] = this -> I;
        // src element is at distance 0
        this -> dist[this -> src] = 0;

        // relaxing all the edges for |V| - 1 times
        for (k = 1; k < this -> V; k++) {

            // running through the entire adjacency matrix once
            for (i = 1; i <= this -> V; i++) {
                for (j = 1; j <= this -> V; j++) {
                    if (this -> cost[i][j] != 0) {
                        // performing relaxation on a pair of vertices
                        if (this -> dist[i] + this -> cost[i][j] < this -> dist[j]) {
                            this -> dist[j] = this -> dist[i] + this -> cost[i][j];
                        }
                    }
                }
            }

        }
    }    

    void shortest_distance() {
        cout << "The shortest distance is :\n";
        cout << "Vertex\tDistance\n";
        for (int i = 1; i <= this -> V; i++) {
            cout << i << "\t\t" << this -> dist[i] << "\n";
        }
        cout << "\n";
    }
};
