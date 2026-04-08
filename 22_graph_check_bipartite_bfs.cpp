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

    vector<int> color(v, -1);
    bool isBipartite = true;

    for (int start = 0; start < v && isBipartite; start++) {
        if (color[start] != -1) continue;

        queue<int> q;
        q.push(start);
        color[start] = 0;

        while (!q.empty() && isBipartite) {
            int node = q.front();
            q.pop();

            for (int nei : adj[node]) {
                if (color[nei] == -1) {
                    color[nei] = 1 - color[node];
                    q.push(nei);
                } else if (color[nei] == color[node]) {
                    isBipartite = false;
                    break;
                }
            }
        }
    }

    cout << (isBipartite ? "Graph is Bipartite\n" : "Graph is Not Bipartite\n");

    return 0;
}
