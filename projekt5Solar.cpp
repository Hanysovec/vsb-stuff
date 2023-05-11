#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <cmath>
#include "Graph.h"
#include <chrono>

using namespace std;


int main() {

    string file_name = "Graf1.txt";
    // Read graph from file
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    cout << "Loading file " << file_name << "..." << endl;
    ifstream file(file_name);
    int u, v, max_vertex = -1;
    while (file >> u >> v) {
        max_vertex = max(max_vertex, max(u, v));
    }
    Graph G(max_vertex + 1);
    file.clear();
    file.seekg(0);
    while (file >> u >> v) {
        G.add_edge(u, v);
    }
    file.close();
    chrono::steady_clock::time_point end = chrono::steady_clock::now();


    cout << "Time to load file: " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << " milliseconds." << endl;
    int size = G.numberOfVertex();
    //Get largest component and its size
    begin = chrono::steady_clock::now();
    cout << "Finding largest component..." << endl;
    int sizeComponent = G.largest_component();
    end = chrono::steady_clock::now();
    cout << "Time to find largest component: " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << " milliseconds." << endl;


    // Compute global clustering coefficient
    cout << "Calculating clustering coefficient..." << endl;
    begin = chrono::steady_clock::now();
    double C = G.clustering_coefficient();
    end = chrono::steady_clock::now();
    cout << "Time to calculate: " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << " milliseconds." << endl;
    cout << "-------------------------------------" << endl;
    cout << "Number of vertices in graph: " << size << endl;
    cout << "Number of vertices in component: " << sizeComponent << endl;
    cout << "Global clustering coefficient: " << C << endl; 

    return 0;
}
