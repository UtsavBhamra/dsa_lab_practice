#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

#define V 9

int minDistance(int* dist, int* stpset){
    int min = 10000;
    int min_index;
    
    for(int v=0;v<V;v++){
        if(stpset[v]==0 && dist[v]<=min){
            min = dist[v];
            min_index = v;
        }
    }
    
    return min_index;
}

void printSolution(int dist[]) {
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

int dijkstra(int graph[V][V], int src){
    int dist[V];
    int stpset[V];
    
    for(int i=0;i<V;i++){
        dist[i]=10000;
        stpset[i]=0;
    }
    
    dist[src]=0;
    
    for(int i=0;i<V;i++){
        int u = minDistance(dist,stpset);
        
        stpset[u] = 1;
        
        for(int v=0;v<V;v++){
            if(stpset[v]!=1 && graph[u][v] && dist[u]!=10000 && dist[u]+graph[u][v]<dist[v]){
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    
    printSolution(dist);
}


int main(){
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };

    dijkstra(graph, 0);

    return 0;
}