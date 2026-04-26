// Find Connected Components in Undirected Graph (BFS)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int connectedComponents(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    int count = 0;

    for (int src = 0; src < V; src++) {
        if (visited[src]) continue;
        count++;
        queue<int> q;
        q.push(src);
        visited[src] = true;
        cout << "Component " << count << ": ";
        while (!q.empty()) {
            int u = q.front(); q.pop();
            cout << u << " ";
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        cout << "\n";
    }
    return count;
}

int main() {
    // 7 nodes, 4 edges → 3 components
    int V = 7;
    vector<vector<int>> adj(V);
    auto addEdge = [&](int u, int v) {
        adj[u].push_back(v); adj[v].push_back(u);
    };
    addEdge(0, 1); addEdge(1, 2); addEdge(3, 4); addEdge(5, 6);

    int cnt = connectedComponents(V, adj);
    cout << "Total connected components: " << cnt << "\n";
}
