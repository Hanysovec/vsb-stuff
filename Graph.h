#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <cmath>

using namespace std;

class Graph
{
private:
    int V; // number of vertices
    vector<vector<int>> matrix; // adjacency list to store the graph
    vector<int> component;
    bool sorted = false;
public:
    Graph(int v);

    // Add edge to the graph
    void add_edge(int u, int v);

    // Get largest component and its size
    int largest_component();

    void sort_matrix();

    long numberOfVertex();

    // Breadth-first search to get component size
    int bfs(int src, vector<bool>& visited, vector<int>& component);

    // Compute global clustering coefficient
    double clustering_coefficient();
};

