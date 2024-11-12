#include<stdio.h>
#include<stdlib.h>

struct Edge {
    int src;
    int dest;
    int weight;
};

struct Graph {
    int V,E;
    struct Edge* edge;
};

struct Graph* createGraph(int V,int E){
    struct Graph* temp = malloc(sizeof(struct Graph));
    temp->V = V;
    temp->E = E;
    temp->edge = malloc(E*sizeof(struct Edge));
    return temp;
}
void printArr(int dist[], int n) {
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}


void bellFord(struct Graph* g, int src){
    int V = g->V;
    int E = g->E;
    int dist[V];
    
    for(int i=0;i<V;i++){
        dist[V]=10000;
    }
    dist[0]=0;
    
    for(int i=0;i<V-1;i++){
        for(int j=0;j<E;j++){
            int u = g->edge[j].src;
            int v = g->edge[j].dest;
            int w = g->edge[j].weight;
            if(dist[u]!=10000 && (dist[u]+w<dist[v])){
                dist[v] = dist[u]+w;
            }
        }
    }
    printArr(dist, V);
}



int main(){
    int V = 5; // Number of vertices in graph
    int E = 8; // Number of edges in graph
    struct Graph* graph = createGraph(V, E);

    // add edge 0-1 (or A-B in graph)
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = -1;

    // add edge 0-2 (or A-C in graph)
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 4;

    // add edge 1-2 (or B-C in graph)
    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 3;

    // add edge 1-3 (or B-D in graph)
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 2;

    // add edge 1-4 (or B-E in graph)
    graph->edge[4].src = 1;
    graph->edge[4].dest = 4;
    graph->edge[4].weight = 2;

    // add edge 3-2 (or D-C in graph)
    graph->edge[5].src = 3;
    graph->edge[5].dest = 2;
    graph->edge[5].weight = 5;

    // add edge 3-1 (or D-B in graph)
    graph->edge[6].src = 3;
    graph->edge[6].dest = 1;
    graph->edge[6].weight = 1;

    // add edge 4-3 (or E-D in graph)
    graph->edge[7].src = 4;
    graph->edge[7].dest = 3;
    graph->edge[7].weight = -3;

    bellFord(graph, 0);

    free(graph->edge);
    free(graph);

    return 0;
}