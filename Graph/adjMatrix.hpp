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

int degree(int graph[V][V]){
    int degree = 0;
    for(int i=0; i<V; i++){
        int neightbours = 0;
        for(int j=0; j<V; j++) if(graph[i][j]) neightbours++;
        if(neightbours > degree) degree = neightbours;
    }
    return degree;
}

bool isDirected(int graph[V][V]){
    int occurrences[V];
    for(int i=0; i<V; i++) occurrences[i] = 0;

    for(int i=0; i<V; i++)
        for(int j=0; j<V; j++)
            if(graph[i][j]){
                occurrences[i]++;
                occurrences[j]++;
            }

    for(int i=0; i<V; i++)
        if(occurrences[i] % 2 != 0) return true;
    return false;
}
