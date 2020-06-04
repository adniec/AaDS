#pragma once
#include <iostream>
#include "../List/list.hpp"
using namespace std;

const int V = 7;
const int MAXIMUM = 2147483647;
bool visited[V] = {};

int GRAPH[V][V] = {
    {0,0,0,0,1,1,0},
    {0,0,1,1,1,1,0},
    {0,1,0,1,0,1,1},
    {0,1,1,0,1,0,1},
    {1,1,0,1,0,1,0},
    {1,1,1,0,1,0,0},
    {0,0,1,1,0,0,0}
};

int WEIGHTED[V][V] = {
    {0,0,0,0,6,3,0},
    {0,0,4,1,1,2,0},
    {0,4,0,3,0,5,6},
    {0,1,3,0,9,0,1},
    {6,1,0,9,0,2,0},
    {3,2,5,0,2,0,0},
    {0,0,6,1,0,0,0}
};

node** getNeighbours(){
    node** graph = new node*[V];
    for(int i=0; i<V; i++) graph[i] = nullptr;
    for(int i=0; i<V; i++)
        for(int j=0; j<V; j++)
            if(GRAPH[i][j])
                pushBack(graph[i], j);
    return graph;
}

void shortestPath(int parents[], int source, int destination){
    node* values = new node{destination};

    cout << "Shortest path from " << source << " to " << destination << ": ";
    while(parents[source] != destination){
        if(parents[destination] < 0){
            cout << "does not exist." << endl;
            return;
        }
        pushFront(values, parents[destination]);
        destination = parents[destination];
    }
    print(values);
}
