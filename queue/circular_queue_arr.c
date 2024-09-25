#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10

struct queue{
    int arr[MAX_SIZE];
    int front;
    int rear;
};

int is_empty(struct queue* q){
    if(q->front==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int is_full(struct queue* q){
    return (q->rear+1)%MAX_SIZE==q->front;
}

void enqueue(struct queue* q,int data){
    if(is_full(q)){
        printf("q overflow");
    }
    if(is_empty(q)){
        q->front++;
    }
    q->rear = (q->rear+1)%MAX_SIZE;
    q->arr[q->rear]=data;
}

int dequeue(struct queue* q){
    if(is_empty(q)){
        printf("underflow");
        return -1;
    }
    int ele = q->arr[q->front];
    if(q->front==q->rear){
        q->front=-1;
        q->rear=-1;
    }
    else{
        q->front = (q->front+1)%MAX_SIZE;
    }
    return ele;
}

void display(struct queue* q){
    if(is_empty(q)){
        printf("empty q");
    }
    int i=q->front;
    while(i!=q->rear){
        printf("%d ",q->arr[i]);
        i = (i+1)%MAX_SIZE;
    }
    printf("%d",q->rear);
}

int main(){
    
    return 0;
}