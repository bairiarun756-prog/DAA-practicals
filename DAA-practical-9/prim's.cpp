
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> cost(n, vector<int>(n));

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
            if (i != j && cost[i][j] == 0)
                cost[i][j] = INT_MAX;
        }
    }

    vector<bool> visited(n, false);
    visited[0] = true;

    int edges = 0, totalCost = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    while (edges < n - 1) {
        int minCost = INT_MAX;
        int u = -1, v = -1;

        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < minCost) {
                        minCost = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (v == -1) {
            cout << "Graph is disconnected.\n";
            return 0;
        }

        cout << u << " - " << v
             << " : " << minCost << endl;

        visited[v] = true;
        totalCost += minCost;
        edges++;
    }

    cout << "Total Minimum Cost = " << totalCost << endl;

    return 0;
}
