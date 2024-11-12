#include<stdio.h>
#include<stdlib.h>
#define MAX 20

int adj[MAX][MAX];

void initialize(){
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            adj[i][j]=0;
        }
    }
}

void dfs(int start,int* visited){
    printf("%d  ",start);
    visited[start]=1;
    
    for(int i=0;i<MAX;i++){
        if(adj[start][i]==1 && visited[i]!=1){
            dfs(i,visited);
        }
    }
}

int main(){
    initialize();
    int visited[5]={0,0,0,0,0};
    int size=5;
    adj[0][1]=1;
    adj[0][2]=1;
    adj[1][0]=1;
    adj[1][3]=1;
    adj[2][0]=1;
    adj[4][2]=1;
    adj[3][1]=1;
    adj[2][4]=1;
    
    dfs(0,visited);
    return 0;
}