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

void depthFirstSearch(int graph[V][V], int vertex){
    visited[vertex] = true;
    for(int i=0; i<V; i++)
        if(graph[vertex][i] && !visited[i])
            depthFirstSearch(graph, i);
    visit.push(vertex);
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

int components(int graph[V][V]){
    for(int i=0; i<V; i++) visited[i] = false;
    int counter = 0;
    for(int i=0; i<V; i++){
        if(!visited[i]){
            depthFirstSearch(graph, i);
            counter++;
        }
    }
    return counter;
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

bool detectedCycle(int graph[V][V], int vertex, int parent){
    visited[vertex] = true;

    for(int i=0; i<V; i++){
        if(graph[vertex][i])
            if(visited[i]){
                if(i != parent)
                    return true;
            }else
                if(detectedCycle(graph, i, vertex))
                    return true;
    } 
    return false; 
}

bool hasUndirectedCycle(int graph[V][V]){
    for(int i=0; i<V; i++) visited[i] = false;
    for(int i=0; i<V; i++)
        if(!visited[i])
            if(detectedCycle(graph, i, -1))
                return true;
    return false;
}

bool hasEulerianCycle(int graph[V][V]){
    if(components(graph) != 1) return false;

    int incomming[V] = {};
    int outcomming[V] = {};

    for(int i=0; i<V; i++){
        int sum = 0;
        for(int j=0; j<V; j++){
            if(graph[i][j]){
                incomming[j]++;
                sum++;
            }
        }
        outcomming[i] = sum;
    }
    for(int i=0; i<V; i++)
        if(incomming[i] != outcomming[i]) return false;
    return true;
}

void topologicalSort(int graph[V][V]){
    for(int i=0; i<V; i++) visited[i] = false;
    while(!visit.isEmpty()) visit.pop();

    for(int i=0; i<V; i++)
        if(!visited[i])
            depthFirstSearch(graph, i);

    while(!visit.isEmpty()) cout << visit.pop() << " ";
}
