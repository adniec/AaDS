#pragma once
#include "../List/list.hpp"
#include "../Queue/queue.hpp"

int* breadthFirstSearch(node* graph[V], int source){
    int* parents = new int[V];
    for(int i=0; i<V; i++) parents[i] = -1;
    parents[source] = source;
    queue q;
    q.put(source);

    while(!q.isEmpty()){
        int actual = q.get();
        node* neighbour = graph[actual];

        while(neighbour){
            int value = neighbour->value;
            if(parents[value] < 0){
                parents[value] = actual;
                q.put(value);
            }
            neighbour = neighbour->next;
        }
    }
    return parents;
}

void depthFirstSearch(node* graph[V], int vertex){
    visited[vertex] = true;
    node* neighbour = graph[vertex];

    while(neighbour){
        int value = neighbour->value;
        if(!visited[value]){
            depthFirstSearch(graph, value);
        }
        neighbour = neighbour->next;
    }
}

int degree(node* graph[V]){
    int degree = 0;
    for(int i=0; i<V; i++){
        int neightbours = length(graph[i]);
        if(neightbours > degree) degree = neightbours;
    }
    return degree;
}
