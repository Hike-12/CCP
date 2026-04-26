### Problem: Find Connected Components in an Undirected Graph using DFS

Use recursive DFS and a visited array. Traverse vertices from 0 to V-1. For each unvisited vertex, start DFS, print that component in one line, and increment the component count.

Function signatures:

```cpp
void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited);
int connectedComponentsDFS(int V, vector<vector<int>>& adj);
```

Graph in main:

- V = 7
- Edges: 0-1, 1-2, 3-4, 5-6

Expected output:

```text
Component 1: 0 1 2
Component 2: 3 4
Component 3: 5 6
Total connected components: 3
```

Complexity:

- Time: O(V + E)
- Space: O(V)
