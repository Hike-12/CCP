// Topological Sort Using BFS (Kahn's Algorithm)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> topoSort(int V, const vector<vector<int>>& adj) {
    vector<int> indegree(V, 0);
    for (int u = 0; u < V; u++)
        for (int v : adj[u]) indegree[v]++;

    queue<int> q;
    for (int i = 0; i < V; i++)
        if (indegree[i] == 0) q.push(i);

    vector<int> order;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v : adj[u])
            if (--indegree[v] == 0) q.push(v);
    }
    return order; // size < V means cycle exists
}

int main() {
    // Graph: 5->2, 5->0, 4->0, 4->1, 2->3, 3->1
    int V = 6;
    vector<vector<int>> adj(V);
    adj[5].push_back(2); adj[5].push_back(0);
    adj[4].push_back(0); adj[4].push_back(1);
    adj[2].push_back(3); adj[3].push_back(1);

    auto order = topoSort(V, adj);
    cout << "Topological Order: ";
    for (int x : order) cout << x << " ";
    cout << "\n";

    // DAG with clear ordering
    V = 4;
    adj.assign(V, {});
    adj[0].push_back(1); adj[0].push_back(2);
    adj[1].push_back(3); adj[2].push_back(3);
    order = topoSort(V, adj);
    cout << "Topological Order: ";
    for (int x : order) cout << x << " ";
    cout << "\n";
}
