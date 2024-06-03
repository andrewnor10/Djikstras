#ifndef Graph_H
#define Graph_H

#include <vector>

class Node {
public:
    int value;
    int weight;
    Node(int v, int w) : value(v), weight(w) {}
};

class Graph // Dijkstra's Algorithm
{
public:
    Graph(int numVertices);
    ~Graph();
    void addEdge(int sourceVertex, int destinationVertex, int weight);
    void dijkstra(int sourceVertex);
    void printSolution(std::vector<int>& distances, int numVertices);
    int minDistance(const std::vector<int>& distances, const std::vector<bool>& shortestPathTreeSet, int numVertices);

private:
    int numVertices;
    std::vector<std::vector<Node>> graph;
};

#endif // Graph_H
