#pragma once

void depthFirstSearch(int graph[V][V], int source){
    visited[source] = true;
    for(int i=0; i<V; i++)
        if(graph[source][i] && !visited[i])
            depthFirstSearch(graph, i);
}
