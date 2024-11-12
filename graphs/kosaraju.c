//not working fully

#include<stdio.h>
#include<stdlib.h>
#define MAX 30

int adj[MAX][MAX];

struct node {
    int data;
    struct node* next;
};

struct stack{
    struct node* top;
};

int isempty(struct stack* st){
    if(st->top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack* st,int data1){
    struct node* temp = malloc(sizeof(struct node));
    temp->data=data1;
    temp->next = NULL;
    if(isempty(st)){
        st->top=temp;
    }
    else{
        temp->next = st->top;
        st->top = temp;
    }
}

void pop(struct stack* st){
    if(isempty(st)){
        printf("stack underflow");
    }
    else{
        struct node* temp = st->top;
        st->top = st->top->next;
        free(temp);
    }
}

int peek(struct stack* st){
    if(isempty(st)){
        printf("stack underflow");
        return -1;     
    }
    else{
        return st->top->data;
    }
}

void initialize(){
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            adj[i][j]=0;
        }
    }
}

void reverseGraph(){
    for(int i=0;i<MAX;i++){
        for(int j=0;j<i;j++){
            printf("%d %d\n",i,j);
            if(i==0 && j==1){
            printf("debug1- %d\n",adj[i][j]);
            }
            if(adj[i][j]==1){
                printf("debug- %d %d\n",i,j);
                adj[i][j]=0;
                adj[j][i]=1;
            };
        }
    }
}

void insertEdge(int n1,int n2){
    adj[n1][n2]=1;
    // adj[n2][n1]=1;
}

void dfs(int start,int* visited, struct stack* st){
    visited[start]=1;
    printf("%d  ",start);
    
    for(int i=0;i<MAX;i++){
        if(adj[start][i]==1 && visited[i]!=1){
            dfs(i,visited,st);
        }
    }
    
    push(st,start);
}

void kosaraju(struct stack* st,int* visited){
    while(isempty(st)!=1){
        int ele = peek(st);
        pop(st);
        printf("ele = %d\n",ele);
        struct stack* st2 = malloc(sizeof(struct stack));
        if(visited[ele]!=1){
            printf("unvisited ele %d\n",ele);
            dfs(ele,visited,st2);
        }
        printf("\n-------------------------------------\n");
    }
}

int main(){
    initialize();
    int visited[5]={0};
    //insertEdge will insert bidirectional edges
    insertEdge(0,1);
    insertEdge(0,2);
    insertEdge(1,3);
    insertEdge(2,4);
    struct stack* st = malloc(sizeof(struct stack));
    dfs(0,visited,st);
    
    reverseGraph();
    printf("\nrev matrix\n");
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            printf(" %d ",adj[i][j]);
        }
        printf("\n");
    }
    int v2[5]={0};
    kosaraju(st,v2);
    return 0;
}