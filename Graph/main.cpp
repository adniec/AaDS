#include <iostream>
#include "graph.hpp"
#include "weighted.hpp"
#include "adjLists.hpp"
// #include "adjMatrix.hpp"
using namespace std;

int main(){
    node** graph = getAdjLists();
    // int (*graph)[V] = matrix;

    cout << "Undirected Eulerian Graph:\n";
    depthFirstSearch(graph, 0);
    cout << "\nDepth-first search visited vertices: ";
    for(int i=0; i<V; i++) cout << visited[i] << " ";

    int* parents = breadthFirstSearch(graph, 0);
    cout << "\nBreadth-first search found parents: ";
    for(int i=0; i<V; i++) cout << parents[i] << " ";
    cout << endl;
    shortestPath(parents, 0, 6);

    cout << "\nIs graph directed? " << isDirected(graph);
    cout << "\nHas graph cycle? " << hasUndirectedCycle(graph);
    cout << "\nHas graph Eulerian cycle? " << hasEulerianCycle(graph);
    cout << "\nGraph components: " << components(graph);
    cout << "\nGraph degree: " << degree(graph);

    cout << "\n\n\nDirected Acyclic Graph With Weights:\n";
    cout << "\nTopological order of vertices: ";
    topologicalSort(weighted);
    cout << endl;

    shortestPath(dijkstra(weighted, 0), 0, 6);

    int* parent = prim(weighted);
    cout << "Minimum spanning tree: ";
    for(int i=0; i<V; i++) cout << parent[i] << " ";

    int start = 0;
    int end = 6;
    cout << "\nMaximum flow from " << start << " to " << end << " is: " << fordFulkerson(weighted, start, end);

    start = 2;
    for(int i=0; i<V; i++) visited[i] = false;
    travelWhenDescending(weighted, start, MAXIMUM);
    cout << "\nCan travel between descending edges. From " << start << " reachable are: ";
    for(int i=0; i<V; i++) cout << visited[i] << " ";

    return 0;
}
