#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii; // (distance, node)

void dijkstra(int source, vector<vector<pii>>& graph, vector<int>& dist) {
    priority_queue<pii, vector<pii>, greater<pii>> pq; // Min-Heap
    dist[source] = 0;
    pq.push({ 0, source });

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue; // Ignore outdated distances

        for (auto edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({ dist[v], v });
            }
        }
    }
}

int main() {
    int V = 5; // Number of nodes
    vector<vector<pii>> graph(V); // Adjacency list: (neighbor, weight)

    // Adding edges (node1, node2, weight)
    graph[0].push_back({ 1, 10 });
    graph[0].push_back({ 2, 5 });
    graph[1].push_back({ 3, 1 });
    graph[1].push_back({ 4, 3 });
    graph[2].push_back({ 1, 2 });
    graph[2].push_back({ 3, 9 });
    graph[3].push_back({ 4, 2 });

    vector<int> dist(V, INT_MAX); // Distance array

    int source = 0;
    dijkstra(source, graph, dist);

    cout << "Shortest distances from node " << source << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "To node " << i << ": " << dist[i] << endl;
    }

    return 0;
}