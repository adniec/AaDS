#pragma once

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
