#include "Graph.h";
#include <iostream>
#include <queue>
#include <list>
#include <vector>
using namespace std;

Graph::Graph(int numVertices)
{
    this->numVertices = numVertices;
    adjList = new list<pair<int, int>>[numVertices];
}

Graph::~Graph()
{
    delete[] adjList;
}

Graph::Graph()
{
    numVertices = 0;
    adjList = nullptr;
}

void Graph::addEdge(int SourceVertex, int DestinationVertex, int weight)
{
    adjList[SourceVertex].push_back({DestinationVertex, weight});
    adjList[DestinationVertex].push_back({SourceVertex, weight});
}

void Graph::addVertex(int vertex, int weight)
{
    adjList[vertex].push_back({ vertex, weight });
    if (vertex > numVertices)
    {
        numVertices = vertex;
    }
}

void Graph::removeVertex(int vertex)
{
    adjList[vertex].clear(); // remove all edges from the vertex
    for (int i = 0; i < numVertices; i++)
    {
        list<pair<int, int>>::iterator it;
        for (it = adjList[i].begin(); it != adjList[i].end(); ++it)
        {
            if ((*it).first == vertex)
            {
                adjList[i].erase(it);
                break;
            }
        }
    }
}

void Graph::dijkstra(int sourceVertex)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(numVertices, 0);
    pq.push(make_pair(0, sourceVertex));
    dist[sourceVertex] = 0;

    while (!pq.empty())
    {
        int adjacentVertex = pq.top().second;
        pq.pop();
        list<pair<int, int>>::iterator it;
        for (it = adjList[adjacentVertex].begin(); it != adjList[adjacentVertex].end(); ++it)
        {
            int vertex = (*it).first;
            int weight = (*it).second;
            if (dist[vertex] > dist[adjacentVertex] + weight)
            {
                dist[vertex] = dist[adjacentVertex] + weight;
                pq.push(make_pair(dist[vertex], vertex));
            }
        }
    }
    cout << "The distances from the source vertex to all other vertices are: " << endl;
    for (int i = 0; i < numVertices; i++)
    {
        cout << "Vertex " << i << " : " << dist[i] << endl;
    }
}
void Graph::removeEdge (int sourceVertex, int destinationVertex)
{
	list<pair<int, int>>::iterator it;
	for (it = adjList[sourceVertex].begin(); it != adjList[sourceVertex].end(); ++it)
	{
		if ((*it).first == destinationVertex)
		{
			adjList[sourceVertex].erase(it);
			break;
		}
	}
	for (it = adjList[destinationVertex].begin(); it != adjList[destinationVertex].end(); ++it)
	{
		if ((*it).first == sourceVertex)
		{
			adjList[destinationVertex].erase(it);
			break;
		}
	}
}
bool Graph::adjacent (int vertex, int destinationVertex)
{
	list<pair<int, int>>::iterator it;
	for (it = adjList[vertex].begin(); it != adjList[vertex].end(); ++it)
	{
		if ((*it).first == destinationVertex)
		{
			return true;
		}
	}
	return false;
}

void Graph::calculatePaths(int sourceVertex)
{
    dijkstra(sourceVertex);
}