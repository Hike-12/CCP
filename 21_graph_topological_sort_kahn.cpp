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
    vector<int> indegree(v, 0);

    cout << "Enter directed edges (u v):\n";
    for (int i = 0; i < e; i++) {
        int u, w;
        cin >> u >> w;
        adj[u].push_back(w);
        indegree[w]++;
    }

    queue<int> q;
    for (int i = 0; i < v; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    vector<int> topo;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (int nei : adj[node]) {
            indegree[nei]--;
            if (indegree[nei] == 0) q.push(nei);
        }
    }

    if ((int)topo.size() != v) {
        cout << "Graph has a cycle. Topological sort not possible.\n";
    } else {
        cout << "Topological Order: ";
        for (int i = 0; i < v; i++) {
            cout << topo[i] << (i + 1 < v ? " " : "\n");
        }
    }

    return 0;
}
