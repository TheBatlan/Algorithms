#include <bits/stdc++.h>
using namespace std;

// global variables for vertices and src
int V, src;

// get data
void getAdjacencyMatrix(int** cost) {
    cout << "Enter the data matrix (" << V << "x" << V << ": \n";
    for (int i = 0; i < V; i++) {
    	cost[i] = new int[V];
        for (int j = 0; j < V; j++) {
            cin >> cost[i][j];
        }
    }
}

int minDistance(int* dist, const bool* includes) {
    int minIndex, min = INT_MAX;
    for (int i = 0; i < V; i++) {
        if (!includes[i] && dist[i] <= min) {
            minIndex = i;
            min = dist[i];
        }
    }
    return minIndex;
}

void printResult(int* dist) {
    cout << "The minimum distance from each of the vertices are: \n";
    for (int i = 0; i < V; i++) {
        cout << i << " -> " << dist[i] << "\n";
    }
}

void dijikstras(int** cost, int src) {
    // array for distances
    int dist[V];
    // array for includes
    bool includes[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT32_MAX;
        includes[i] = false;
    }

    // source is at distance 0
    dist[src] = 0;

    for (int i = 0; i < V - 1; i++) {
        // get the minimum distant and connected vertex
        int u = minDistance(dist, includes);
        includes[u] = true;

        // relaxation of vertices
        for (int v = 0; v < V; v++) {
            if (!includes[v] && cost[u][v] && dist[u] != INT32_MAX && dist[u] + cost[u][v] < dist[v]) {
                dist[v] = dist[u] + cost[u][v];
            }
        }
    }

    // minimum distance from each of the vertices
    printResult(dist);
}

int main() {

    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Select a vertex as the source (0 - " << V - 1 << "): ";
    cin >> src;

    int** cost = new int*[V];
    // getting input cost of edges
    getAdjacencyMatrix(cost);

    // performing dijikstra
    dijikstras(cost, src);

    return 0;
}
