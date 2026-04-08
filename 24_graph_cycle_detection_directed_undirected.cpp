#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool hasCycleUndirectedBFS(int v, const vector<vector<int>>& adj) {
    vector<int> vis(v, 0);

    for (int start = 0; start < v; start++) {
        if (vis[start]) continue;

        queue<pair<int, int>> q;
        q.push({start, -1});
        vis[start] = 1;

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (int nei : adj[node]) {
                if (!vis[nei]) {
                    vis[nei] = 1;
                    q.push({nei, node});
                } else if (nei != parent) {
                    return true;
                }
            }
        }
    }

    return false;
}

bool hasCycleDirectedKahn(int v, const vector<vector<int>>& adj) {
    vector<int> indegree(v, 0);
    for (int i = 0; i < v; i++) {
        for (int nei : adj[i]) indegree[nei]++;
    }

    queue<int> q;
    for (int i = 0; i < v; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    int visitedCount = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        visitedCount++;

        for (int nei : adj[node]) {
            indegree[nei]--;
            if (indegree[nei] == 0) q.push(nei);
        }
    }

    return visitedCount != v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int v1, e1;
    cout << "Undirected graph - enter vertices and edges: ";
    cin >> v1 >> e1;

    vector<vector<int>> adjUnd(v1);
    cout << "Enter undirected edges (u v):\n";
    for (int i = 0; i < e1; i++) {
        int u, w;
        cin >> u >> w;
        adjUnd[u].push_back(w);
        adjUnd[w].push_back(u);
    }

    int v2, e2;
    cout << "Directed graph - enter vertices and edges: ";
    cin >> v2 >> e2;

    vector<vector<int>> adjDir(v2);
    cout << "Enter directed edges (u v):\n";
    for (int i = 0; i < e2; i++) {
        int u, w;
        cin >> u >> w;
        adjDir[u].push_back(w);
    }

    bool undirectedCycle = hasCycleUndirectedBFS(v1, adjUnd);
    bool directedCycle = hasCycleDirectedKahn(v2, adjDir);

    cout << (undirectedCycle ? "Undirected graph has a cycle\n" : "Undirected graph has no cycle\n");
    cout << (directedCycle ? "Directed graph has a cycle\n" : "Directed graph has no cycle\n");

    return 0;
}
