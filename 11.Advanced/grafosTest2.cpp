// C++ Program to Implement a Graph Using Adjacency List
#include <iostream>
#include <list>
#include <map>
using namespace std;

class Graph {
    map<int, list<int> >
        adjList; // Adjacency list to store the graph

public:
    // Function to add an edge between vertices u and v of
    // the graph
    void add_edge(int u, int v)
    {
        // Add edge from u to v
        adjList[u].push_back(v);
        // Add edge from v to u because the graph is
        // undirected
        adjList[v].push_back(u);
    }

    // Function to print the adjacency list representation
    // of the graph
    void print()
    {
        cout << "Adjacency list for the Graph: " << endl;
        // Iterate over each vertex
        for (auto i : adjList) {
            // Print the vertex
            cout << i.first << " -> ";
            // Iterate over the connected vertices
            for (auto j : i.second) {
                // Print the connected vertex
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    // Create a graph object
    Graph g;

    // Add edges to create the graph
    g.add_edge(1, 0);
    g.add_edge(2, 0);
    g.add_edge(1, 2);

    // Print the adjacency list representation of the graph
    g.print();
    return 0;
}