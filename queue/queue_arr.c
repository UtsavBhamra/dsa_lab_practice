#include<stdio.h>
#include<stdlib.h>
#define SIZE 20

struct queue {
    int arr[SIZE];
    int front;
    int rear;
    int size;
};

int is_empty(struct queue* q){
    if(q->front==q->rear){
        return 1;
    }
    else{
        return 0;
    }
}

int is_full(struct queue* q){
    if(q->rear==SIZE-1){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(struct queue* q,int ele){
    if(is_full(q)){
        printf("q is full");
    }
    q->rear++;
    q->arr[q->rear]=ele;
    q->size++;
}

int dequeue(struct queue* q){
    if(is_empty(q)){
        printf("q is empty");
    }
    q->front++;
    int ele = q->arr[q->front];
    q->arr[q->front]=0;
    return ele;
    q->size--;
}

int peek(struct queue* q){
    if(is_empty(q)){
        printf("q is empty");
        return -1;
    }
    return q->arr[q->front+1];
}

void display(struct queue* q){
    for(int i=q->front+1;i<=q->rear;i++){
        printf("%d ",q->arr[i]);
    }
}

int main(){
    struct queue* q = malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    q->size=0;
    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);
    enqueue(q,60);
    dequeue(q);
    display(q);
    return 0;
}