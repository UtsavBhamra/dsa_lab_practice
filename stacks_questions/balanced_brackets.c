#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

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

char pop(struct stack* st){
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
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

int balanced_brackets(char* str) {
    struct stack* st = malloc(sizeof(struct stack));
    int n = strlen(str);
    
    for (int i = 0; i < n; i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            push(st, str[i]);
        } else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (is_empty(st)) {
                return 0; // Unmatched closing bracket
            }
            char top = pop(st);
            // Check for matching brackets
            if ((str[i] == ')' && top != '(') ||
                (str[i] == '}' && top != '{') ||
                (str[i] == ']' && top != '[')) {
                return 0; // Mismatched brackets
            }
        }
    }

    // Check if stack is empty at the end
    return is_empty(st); // Return 1 if balanced, 0 otherwise
}


int main(){
    char str[100];
    scanf("%s",str);
    printf("%d",balanced_brackets(str));
    return 0;
}