#include "Graph.h"
Graph::Graph(int v) : V(v), matrix(v) {}


void Graph::add_edge(int u, int v) {
    matrix[u].push_back(v);
    matrix[v].push_back(u);
}

int Graph::largest_component() {
    if (!sorted) {
        sort_matrix();
    }
    vector<bool> visited(V, false);
    int max_size = 0;
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            vector<int> curr_component;
            int size = bfs(i, visited, curr_component);
            if (size > max_size) {
                max_size = size;
                component = curr_component;
            }
        }
    }
    return max_size;
}

void Graph::sort_matrix() {
    for (int i = 0; i < V; i++) {
        sort(matrix[i].begin(), matrix[i].end());
    }
    sorted = true;
}

int Graph::bfs(int src, vector<bool>& visited, vector<int>& component) {
    int size = 0;
    queue<int> q;
    q.push(src);
    visited[src] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        size++;
        component.push_back(u);
        for (int v : matrix[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    return size;
}

long Graph::numberOfVertex() {
    long count = 0;
    for (int i = 0; i < V; i++)
    {
        if (!(matrix[i].empty()))
        {
            count++;
        }
    }
    return count;
}

double Graph::clustering_coefficient() {
    long long triplets = 0;
    long long triangles = 0;
    if (component.empty()) {
        largest_component();
    }

    for (int u : component) {
        vector<int> neighbors = matrix[u];
        long long degree = neighbors.size();
        if (degree < 2) continue;
        for (int i = 0; i < degree - 1; i++) {
            for (int j = i + 1; j < degree; j++) {
                int v = neighbors[i];
                int w = neighbors[j];
                if (binary_search(matrix[v].begin(), matrix[v].end(), w)) {
                    triangles++;
                }
            }
        }
        triplets += degree * (degree - 1) / 2;
    }
    double c = 0.0;
    if (triplets > 0) {
        c = (double)(triangles) / (double)(triplets);
    }
    return c;
}
