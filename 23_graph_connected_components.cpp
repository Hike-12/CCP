#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, const vector<vector<int>>& adj, vector<int>& vis, vector<int>& component) {
    vis[node] = 1;
    component.push_back(node);

    for (int nei : adj[node]) {
        if (!vis[nei]) dfs(nei, adj, vis, component);
    }
}

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

    vector<int> vis(v, 0);
    vector<vector<int>> components;

    for (int i = 0; i < v; i++) {
        if (!vis[i]) {
            vector<int> comp;
            dfs(i, adj, vis, comp);
            components.push_back(comp);
        }
    }

    cout << "Number of connected components: " << components.size() << "\n";
    for (int i = 0; i < (int)components.size(); i++) {
        cout << "Component " << i + 1 << ": ";
        for (int j = 0; j < (int)components[i].size(); j++) {
            cout << components[i][j] << (j + 1 < (int)components[i].size() ? " " : "\n");
        }
    }

    return 0;
}
