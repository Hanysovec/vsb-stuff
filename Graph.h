#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <cmath>

using namespace std;
/**
* Implementation of a way to store graph and calculate the Global clustering coefficient of the largest component
*/
class Graph
{
private:
    int V; /// largest vertex in graph
    vector<vector<int>> matrix; ///< Graph stored in memory
    vector<int> component; ///< largest component stored in memory
    bool sorted = false; ///< if the matrix is sorted
public:
    /**
    * Inicialize the matrix
    * @param V Number of vertices
    */
    Graph(int v);

    /**
    * Add edge to the matrix with specified vertex
    * @param u First vertex
    * @param v Second vertex
    */
    void add_edge(int u, int v);

    /**
    * Algorithm to find the largest component, returns the number of vertices.
    */
    int largest_component();

    /**
    * Used to sort the matrix from 0 to number of vertices
    */
    void sort_matrix();

    /**
    * Returns the number of Vertices.
    */
    long numberOfVertex();

    /**
    * Breadth-first search to find a components number of vertices.
    * @param src Vertex ID
    * @param visited bool vector
    * @param component current component
    */
    int bfs(int src, vector<bool>& visited, vector<int>& component);

    /**
    * Function to calculate the global clustering coefficient and returns it.
    */
    double clustering_coefficient();
};

