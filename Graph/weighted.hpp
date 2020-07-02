#pragma once
#include <iostream>
#include "graph.hpp"
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
