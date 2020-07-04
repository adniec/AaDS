#pragma once
#include <iostream>
#include "graph.hpp"
#include "adjMatrix.hpp"
using namespace std;

int* dijkstra(int graph[V][V], int source){
    int cost[V];
    int* parents = new int[V];
    bool found[V];
    for(int i=0; i<V; i++){
        cost[i] = MAXIMUM;
        found[i] = false;
		parents[i] = -1;
    }
    cost[source] = 0;
	parents[source] = source;

    for(int _=0; _<V-1; _++){
        int smallest = MAXIMUM;
        int u;

        for(int i=0; i<V; i++)
            if(!found[i] && cost[i] < smallest){
                smallest = cost[i];
                u = i;
            }
        found[u] = true;

        for(int i=0; i<V; i++)
            if(!found[i] && graph[u][i] && cost[u] != MAXIMUM){
                int value = cost[u] + graph[u][i];
                if(cost[i] > value){
					cost[i] = value;
					parents[i] = u;
				}
            }
    }
    cout << "Minimal costs from " << source << " are: ";
    for(int i=0; i<V; i++) cout << cost[i] << " ";
	cout << endl;
	return parents;
}

int* prim(int graph[V][V]){
    int* parents = new int[V];
    int values[V];
    bool found[V];
    
    for(int i=0; i<V; i++){
        values[i] = MAXIMUM;
        found[i] = false;
    }
    values[0] = 0;
    parents[0] = -1;
    
    for(int _=0; _<V-1; _++){
        int min = MAXIMUM;
        int u;

        for (int i=0; i<V; i++)
            if(found[i] == false && values[i] < min){
                min = values[i];
                u = i;
            }
        found[u] = true;

        for(int i=0; i<V; i++){
            int value = graph[u][i];
            if(!found[i] && value && value < values[i]){
                parents[i] = u;
                values[i] = value;
            }
        }
    }
    return parents;
}

int fordFulkerson(int graph[V][V], int source, int destination){
    int tmpGraph[V][V];
    for(int i=0; i<V; i++)
        for(int j=0; j<V; j++)
            tmpGraph[i][j] = graph[i][j];

    int* parents = breadthFirstSearch(tmpGraph, source);
    int capacity = 0;

    while(parents[destination]!=-1){
        int path = MAXIMUM;
        for(int i=destination; i!=source; i=parents[i])
            path = min(path, tmpGraph[parents[i]][i]);

        for(int i=destination; i!=source; i=parents[i]){
            tmpGraph[parents[i]][i] -= path;
            tmpGraph[i][parents[i]] += path;
        }
        capacity += path;
        delete parents;
        parents = breadthFirstSearch(tmpGraph, source);
    }
    return capacity;
}

void travelWhenDescending(int graph[V][V], int source, int last_weight){
	visited[source] = true;
	for(int i=0; i<V; i++){
		int weight = graph[source][i];
		if(weight){
			if(last_weight > weight){
				travelWhenDescending(graph, i, weight);
			}
		}
	}
}
