#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int adj[MAX][MAX];

void initialize(){
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            adj[i][j]=-1;
        }
    }
}

struct q_node{
    int data;
    struct q_node* next;
};

struct queue {
    int size;
    struct q_node* front;
    struct q_node* rear;
};

int is_empty(struct queue* q){
    return q->front==NULL;
}

void enqueue(struct queue* q,int data1){
    struct q_node* temp_q_node = malloc(sizeof(struct q_node));
    temp_q_node->data = data1;
    temp_q_node->next = NULL;
    if(is_empty(q)){
        q->front = temp_q_node;
        q->rear = temp_q_node;
    }
    else{
        q->rear->next = temp_q_node;
        q->rear = q->rear->next;
    }
    q->size++;
}

int dequeue(struct queue* q){
    if(is_empty(q)){
        printf("q is empty");
        return -1;
    }
    int ele = q->front->data;
    struct q_node* temp_q_node = q->front;
    q->front = q->front->next;
    free(temp_q_node);
    return ele;
}

int peek(struct queue* q){
    if(is_empty(q)){
        printf("q is empty");
        return -1;
    }
    else{
        return q->front->data;
    }
}


void bfs(int visited[], int size) {
    struct queue* q = malloc(sizeof(struct queue));
    printf("%d",is_empty(q));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;

    enqueue(q, 0);
    visited[0] = 1; // Mark starting node as visited

    while (!is_empty(q)) {
        int ele = dequeue(q);
        printf("%d ", ele);

        // Enqueue all adjacent, unvisited nodes
        int j = 0;
        while (adj[ele][j] != -1) {
            int adjacent_node = adj[ele][j];
            if (!visited[adjacent_node]) {
                enqueue(q, adjacent_node);
                visited[adjacent_node] = 1; // Mark as visited when enqueued
            }
            j++;
        }
    }
}

int main(){
    initialize();
    int visited[5]={0,0,0,0,0};
    int size=5;
    adj[0][0]=1;
    adj[0][1]=2;
    adj[1][0]=0;
    adj[1][1]=3;
    adj[2][0]=0;
    adj[2][1]=4;
    adj[3][0]=1;
    adj[4][0]=2;
    
    bfs(visited,size);
    
    return 0;
}