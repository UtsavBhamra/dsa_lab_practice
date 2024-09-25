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

void push(struct queue* q,int data1){
    struct node* temp = malloc(sizeof(struct node));
    temp->data = data1;
    temp->next=NULL;
    if(is_empty(q)){
        q->front = temp;
        q->rear = temp;
    }
    else{
        q->front->next = temp;
        q->front= q->front->next;
    }
}

int pop(struct queue* q){
    if(is_empty(q)){
        printf("stack underflow");
        return -1;
    }
    struct node* temp = q->rear;
    while(temp->next!=q->front){
        temp = temp->next;
    }
    struct node* temp_node = temp->next;
    int ele = temp_node->data;
    q->front = temp;
    free(temp_node);
    return ele;
}

void display(struct queue* q){
    struct node* temp  = q->rear;
    while(temp!=q->front){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("%d ",temp->data);
}

int main(){
    struct queue* q = malloc(sizeof(struct queue));
    q->front=NULL;
    q->rear=NULL;
    q->size=0;
    push(q,1);
    push(q,2);
    push(q,3);
    pop(q);
    push(q,6);
    display(q);
    return 0;
}