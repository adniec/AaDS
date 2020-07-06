#pragma once
#include <iostream>
#include "../List/list.hpp"
#include "../Stack/Stack.hpp"
using namespace std;

#define V 7
#define MAXIMUM 2147483647
bool visited[V] = {};
stack visit;

int matrix[V][V] = {
    {0,0,0,0,1,1,0},
    {0,0,1,1,1,1,0},
    {0,1,0,1,0,1,1},
    {0,1,1,0,1,0,1},
    {1,1,0,1,0,1,0},
    {1,1,1,0,1,0,0},
    {0,0,1,1,0,0,0},
};

int weighted[V][V] = {
    {0,9,2,0,0,9,0},
    {0,0,0,9,0,0,0},
    {0,5,0,9,3,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,2,4},
    {0,0,0,0,0,0,1},
    {0,0,0,2,0,0,0},
};

node** getAdjLists(){
    node** graph = new node*[V];
    for(int i=0; i<V; i++)
        graph[i] = nullptr;

    for(int i=0; i<V; i++)
        for(int j=0; j<V; j++)
            if(matrix[i][j])
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
