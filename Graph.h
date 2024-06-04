#ifndef Graph_H
#define Graph_H

#include <vector>
#include <list>
#include <iostream>
#include <queue>



class Edge {
public:
    int sourceVertex;
	int destinationVertex;
	int weight;
  
	Edge(int d, int w) : destinationVertex(d), weight(w) {}

};

class Vertex {
public:
    int value;
    int weight;
    Vertex(int v, int w) : value(v), weight(w) {}

    std::vector<Edge> edges;
};

class Graph // Dijkstra's Algorithm
{
public:
    Graph(int numVertices);
    Graph();
    ~Graph();
    void addEdge(int sourceVertex, int destinationVertex, int weight);
    void addVertex(int value, int weight);
    void removeEdge(int sourceVertex, int destinationVertex);
    void removeVertex(int value);
    void dijkstra(int sourceVertex);
    bool adjacent(int sourceVertex, int destinationVertex);
    void calculatePaths(int sourceVertex);


private:
    int numVertices;
    std::vector<int> distances;
    std::list<std::pair<int,int>>* adjList;
    std::vector<std::vector<Vertex>> graph;
};

#endif // Graph_H
