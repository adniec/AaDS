#pragma once
#include "../Queue/queue.hpp"

int* breadthFirstSearch(int graph[V][V], int source){
    int* parents = new int[V];
    for(int i=0; i<V; i++) parents[i] = -1;
    parents[source] = source;
    queue q;
    q.put(source);
    while(!q.isEmpty()){
        int u = q.get();
        for(int i=0; i<V; i++){
            if(graph[u][i] && parents[i] < 0){
                parents[i] = u;
                q.put(i);
            }
        }
    }
    return parents;
}

void depthFirstSearch(int graph[V][V], int source){
    visited[source] = true;
    for(int i=0; i<V; i++)
        if(graph[source][i] && !visited[i])
            depthFirstSearch(graph, i);
}
