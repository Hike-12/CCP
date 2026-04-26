// Check if Graph is Bipartite Using BFS (2-coloring)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(int V, vector<vector<int>>& adj) {
    vector<int> color(V, -1);

    for (int src = 0; src < V; src++) {
        if (color[src] != -1) continue;
        queue<int> q;
        q.push(src);
        color[src] = 0;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                } else if (color[v] == color[u]) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    // Even cycle (bipartite)
    int V = 4;
    vector<vector<int>> adj(V);
    adj[0].push_back(1); adj[1].push_back(0);
    adj[1].push_back(2); adj[2].push_back(1);
    adj[2].push_back(3); adj[3].push_back(2);
    adj[3].push_back(0); adj[0].push_back(3);
    cout << "Even cycle (0-1-2-3-0): " << (isBipartite(V, adj) ? "Bipartite" : "Not Bipartite") << "\n";

    // Odd cycle (not bipartite)
    V = 3;
    adj.assign(V, {});
    adj[0].push_back(1); adj[1].push_back(0);
    adj[1].push_back(2); adj[2].push_back(1);
    adj[2].push_back(0); adj[0].push_back(2);
    cout << "Odd cycle  (0-1-2-0): " << (isBipartite(V, adj) ? "Bipartite" : "Not Bipartite") << "\n";
}
