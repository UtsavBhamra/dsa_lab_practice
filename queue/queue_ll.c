#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct queue {
    int size;
    struct node* front;
    struct node* rear;
};

int is_empty(struct queue* q){
    if(q->front==NULL && q->rear==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(struct queue* q,int data1){
    struct node* temp_node = malloc(sizeof(struct node));
    temp_node->data = data1;
    temp_node->next = NULL;
    if(is_empty(q)){
        q->front = temp_node;
        q->rear = temp_node;
    }
    else{
        q->rear->next = temp_node;
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
    struct node* temp_node = q->front;
    q->front = q->front->next;
    free(temp_node);
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

void display(struct queue* q){
    if(q->size==0){
        printf("empty queue");
    }
    else{
        struct node* temp = q->front;
        printf("%d ",temp->data);
        while(temp!=q->rear){
            temp=temp->next;
            printf("%d ",temp->data);
        }
    }
}

int main(){
    struct queue* q = malloc(sizeof(struct queue));
    q->front=NULL;
    q->rear=NULL;
    q->size=0;
    enqueue(q,10);
    enqueue(q,20);
    enqueue(q,30);
    enqueue(q,40);
    dequeue(q);
    display(q);
    return 0;
}