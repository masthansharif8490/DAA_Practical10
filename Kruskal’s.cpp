
#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int parent[100];

int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void unite(int u, int v) {
    parent[find(u)] = find(v);
}

int main() {
    int n, e;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;

    Edge edges[100];

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < e; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    sort(edges, edges + e, compare);

    for (int i = 0; i < n; i++)
        parent[i] = i;

    int totalCost = 0, count = 0;

    cout << "Edges in Minimum Spanning Tree:\n";

    for (int i = 0; i < e && count < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        if (find(u) != find(v)) {
            cout << u << " - " << v
                 << " : " << edges[i].weight << endl;

            unite(u, v);
            totalCost += edges[i].weight;
            count++;
        }
    }

    if (count != n - 1) {
        cout << "Graph is disconnected!\n";
    } else {
        cout << "Total cost of MST = " << totalCost << endl;
    }

    return 0;
}
