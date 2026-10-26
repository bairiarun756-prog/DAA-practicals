
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int parent[100], rnk[100];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int x, int y) {
    int a = find(x);
    int b = find(y);

    if (a == b)
        return;

    if (rnk[a] < rnk[b])
        parent[a] = b;
    else if (rnk[a] > rnk[b])
        parent[b] = a;
    else {
        parent[b] = a;
        rnk[a]++;
    }
}

int main() {
    int V, E;
    cout << "Enter vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++)
        cin >> edges[i].u >> edges[i].v
            >> edges[i].weight;

    sort(edges.begin(), edges.end(), compare);

    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rnk[i] = 0;
    }

    int totalWeight = 0, count = 0;

    cout << "Edges in Minimum Spanning Tree:\n";

    for (Edge e : edges) {
        if (find(e.u) != find(e.v)) {
            cout << e.u << " - " << e.v
                 << " : " << e.weight << "\n";

            unite(e.u, e.v);
            totalWeight += e.weight;
            count++;

            if (count == V - 1)
                break;
        }
    }

    if (count != V - 1)
        cout << "Graph is disconnected; MST does not exist.\n";
    else
        cout << "Total MST weight: " << totalWeight << "\n";

    return 0;
}

