#include <iostream>
#include <vector>
using namespace std;

bool firstInComponent = true;

void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    if (!firstInComponent) cout << " ";
    cout << u;
    firstInComponent = false;

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, adj, visited);
        }
    }
}

int connectedComponentsDFS(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    int count = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            count++;
            cout << "Component " << count << ": ";
            firstInComponent = true;
            dfs(i, adj, visited);
            cout << "\n";
        }
    }

    return count;
}

int main() {
    int V = 7;
    vector<vector<int>> adj(V);

    auto addEdge = [&](int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    };

    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(3, 4);
    addEdge(5, 6);

    int total = connectedComponentsDFS(V, adj);
    cout << "Total connected components: " << total << "\n";

    return 0;
}
