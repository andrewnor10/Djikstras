#ifndef Graph_H
#define Graph_H

#include <vector>

class Vertex {
public:
    int value;
    int weight;
    Vertex(int v, int w) : value(v), weight(w) {}
};
class Edge {
    Vertex v1;
    Vertex v2;
    Edge(Vertex v1, Vertex v2) : v1(v1), v2(v2) {};

};

class Graph // Dijkstra's Algorithm
{
public:
    Graph(int numVertices);
    ~Graph();
    void addEdge(int sourceVertex, int destinationVertex, int weight);
    void dijkstra(int sourceVertex);
    void printSolution(std::vector<int>& distances, int numVertices);
    bool adjacent(sourceVertex, destinationVertex);
    int minDistance(const std::vector<int>& distances, const std::vector<bool>& shortestPathTreeSet, int numVertices);

private:
    int numVertices;
    std::vector<std::vector<Vertex>> graph;
};

#endif // Graph_H
