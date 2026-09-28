#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(int start, vector<vector<int>>& graph, int vertices) {
    vector<bool> visited(vertices, false);

    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
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

    cout << "BFS Traversal: ";
    BFS(0, graph, vertices);

    return 0;
}