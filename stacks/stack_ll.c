#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int data;
    struct node* next;
};

struct stack{
    int size;
    struct node* top;
};

int is_empty(struct stack* st){
    if(st->top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack* st,int data1){
    struct node* temp_node = malloc(sizeof(struct node));
    temp_node->data = data1;
    temp_node->next = st->top;
    st->top = temp_node;
}

int pop(struct stack* st){
    if(is_empty(st)){
        printf("empty stack");
        return -1;
    }
    struct node* temp = st->top;
    int ele = st->top->data;
    st->top = st->top->next;
    free(temp);
    return ele;
}

int peek(struct stack* st){
    if(is_empty(st)){
        printf("empty stack");
        return -1;
    }
    return st->top->data;
}



void display(struct stack* st){
    if(is_empty(st)){
        printf("empty stack");
    }
    struct node* temp = st->top;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

int main(){
    
    return 0;
}