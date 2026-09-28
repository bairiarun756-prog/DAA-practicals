#include <iostream>
#include <vector>
using namespace std;

void DFS(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;

    cout << node << " ";

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor, graph, visited);
        }
    }
}

int main() {
    int vertices = 5;

    vector<vector<int>> graph(vertices);

    // Add edges
    graph[0].push_back(1);
    graph[0].push_back(2);

    graph[1].push_back(0);
    graph[1].push_back(3);
    graph[1].push_back(4);

    graph[2].push_back(0);
    graph[3].push_back(1);
    graph[4].push_back(1);

    vector<bool> visited(vertices, false);

    cout << "DFS Traversal: ";
    DFS(0, graph, visited);

    return 0;
}