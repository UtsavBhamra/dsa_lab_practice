#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

struct lifo{
    int st_arr[MAX_SIZE];
    int top;
};

int isempty(struct lifo* st){
    if(st->top<0){
        return 1;
    }
    else{
        return 0;
    }
}

int isfull(struct lifo* st){
    if(st->top==MAX_SIZE){
        return 1;
    }
    else{
        return 0;
    }
}

void create(struct lifo* st){
    st->top = -1;
}

void push(struct lifo* st,int data1){
    if(isfull(st)==1){
        printf("stack overflow");
        return;
    }
    st->top++;
    st->st_arr[st->top] = data1;
}

int pop(struct lifo* st){
    if(isempty(st)==1){
        printf("stack underflow");
        return -2;
    }
    int ele = st->st_arr[st->top];
    st->top--;
    exit(-1);
}

int main(){
    struct lifo* st = malloc(sizeof(struct lifo));
    create(st);
    push(st,10);
    push(st,20);
    printf("%d ",st->st_arr[1]);
    return 0;
}