#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Depth-First Search (DFS) Recursive
void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited);
        }
    }
}

// Breadth-First Search (BFS) using Queue
void bfs(int start, vector<vector<int>>& graph, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    // Define the number of nodes
    int n = 6;

    // Graph adjacency list representation
    vector<vector<int>> graph(n);

    // Predefined set of edges
    vector<pair<int, int>> edges = {
        {0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 4}, {3, 5}, {4, 5}
    };

    // Populate the adjacency list
    for (auto edge : edges) {
        int u = edge.first, v = edge.second;
        graph[u].push_back(v);
        graph[v].push_back(u); // Uncomment this for an undirected graph
    }

    // Perform BFS and DFS starting from node 0
    vector<bool> visited(n, false);

    cout << "BFS Traversal: ";
    bfs(0, graph, visited);
    cout << endl;

    // Reset visited array for DFS
    fill(visited.begin(), visited.end(), false);
    cout << "DFS Traversal: ";
    dfs(0, graph, visited);
    cout << endl;

    return 0;
}