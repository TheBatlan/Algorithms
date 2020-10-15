#include <bits/stdc++.h>
using namespace std;

void getAdjanceyMatrix(int** costs, int V) {
    cout << "***Enter 0 if there is no edge***\n";
    cout << "Enter the Adjacency Matrix data (" << V + 1 << "x" << V + 1 << "): \n";
    for (int i = 0; i <= V; i++) {
        costs[i] = new int[V + 1];
        for (int j = 0; j <= V; j++) {
            cin >> costs[i][j];
            if (costs[i][j] == 0) costs[i][j] = INT32_MAX;
        }
    }
}

void primsMCST(int** costs, int V) {

    // near array
    int near[V + 1];
    // edges array
    int edges[2][V - 1];

    int i, j, k, min = INT32_MAX, u, v;

    // intializing near
    for (i = 0; i <= V; i++) near[i] = INT32_MAX;

    // finding the minimum cost
    for (i = 1; i <= V; i++) {
        for (j = i; j <= V; j++) {
            if (costs[i][j] < min) {
                min = costs[i][j];
                u = i;
                v = j;
            }
        }
    }

    // update near and edges
    edges[0][0] = u;
    edges[1][0] = v;
    near[u] = near[v] = 0;

    for (j = 1; j <= V; j++) {
        if (near[j] != 0) {
            if (costs[j][u] < costs[j][v]) 
                near[j] = u;
            else
                near[j] = v;
        }
    }

    // further procedure
    for (i = 1; i <= V - 2; i++) {
        min = INT32_MAX;
        // finding the minimum and connected edge
        for (j = 1; j <= V; j++) {
            if (near[j] != 0 && costs[j][near[j]] < min) {
                min = costs[j][near[j]];
                k = j;
            }
        }

        // update near and edges
        edges[0][i] = k;
        edges[1][i] = near[k];
        near[k] = 0;

        for (j = 1; j <= V; j++) {
            if (near[j] != 0 && costs[j][k] < costs[j][near[j]]) {
                near[j] = k;
            }
        }
    }

    // Print the minimum cost edges
    cout << "The Minimum cost edges for Minimum Cost Spanning Tree: \n";
    for (int i = 0; i <= V - 2; i++) {
        cout << edges[0][i] << " --- " << edges[1][i] << "\n";
    }
}

int main() {

    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    int** costs;
    costs = new int*[V + 1];

    // get input data
    getAdjanceyMatrix(costs, V);

    // performing Prims
    primsMCST(costs, V);

    return 0;
}
