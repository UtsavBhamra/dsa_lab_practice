#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char data;
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

void push(struct stack* st,char data1){
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
    char ele = st->top->data;
    st->top = st->top->next;
    free(temp);
    return ele;
}

char peek(struct stack* st){
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
        printf("%c ",temp->data);
        temp = temp->next;
    }
}

int priority(char op){
    switch(op){
        case '^':
            return 2;
        case '/':
            return 1;
        case '*':
            return 1;
        case '+':
            return 0;
        case '-':
            return 0;
        default:
            return -1;
    }
}

char* in_to_post(char* str){
    int n = strlen(str);
    char postfix[100];
    int ptr=0;
    struct stack* st = malloc(sizeof(struct stack));
    st->top = NULL;
    st->size=0;
    
    for(int i=0;i<n;i++){
        if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')){
            postfix[ptr]=str[i];
            ptr++;
        }
        else if(str[i]=='('){
            push(st,str[i]);
        }
        else if(str[i]==')'){
            while(peek(st)!='('){
                char ele = pop(st);
                postfix[ptr] = ele;
                ptr++;
            }
            pop(st);
        }
        else if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/' || str[i]=='^'){
            while(!is_empty(st) && priority(str[i])<=priority(peek(st))){
                char op = pop(st);
                postfix[ptr] = op;
                ptr++;
            }
            push(st,str[i]);
        }
    }
    
    while(!is_empty(st)){
            char op = pop(st);
            postfix[ptr] =op;
            ptr++;
    }
    postfix[ptr]='\n';
    printf("%s",postfix);
    return postfix;
}


int main(){
    char infix[11];
    printf("enter str: ");
    scanf("%s",infix);
    in_to_post(infix);
    return 0;
}