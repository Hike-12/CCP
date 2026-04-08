#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, e;
    cout << "Enter number of vertices and edges: ";
    cin >> v >> e;

    vector<vector<int>> adj(v);

    cout << "Enter undirected edges (u v):\n";
    for (int i = 0; i < e; i++) {
        int u, w;
        cin >> u >> w;
        adj[u].push_back(w);
        adj[w].push_back(u);
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    vector<int> dist(v, -1);
    queue<int> q;

    dist[src] = 0;
    q.push(src);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int nei : adj[node]) {
            if (dist[nei] == -1) {
                dist[nei] = dist[node] + 1;
                q.push(nei);
            }
        }
    }

    cout << "Shortest distance from source " << src << ":\n";
    for (int i = 0; i < v; i++) {
        cout << "To " << i << " -> " << dist[i] << "\n";
    }

    return 0;
}
