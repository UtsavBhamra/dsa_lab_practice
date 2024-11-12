#include<stdio.h>
#include<stdlib.h>

#define MAX 5  // set MAX to 5 for simplicity in testing

int adj[MAX][MAX];

struct node {
    int data;
    struct node* next;
};

struct stack {
    struct node* top;
};

// Initialize the stack with NULL top
struct stack* createStack() {
    struct stack* st = malloc(sizeof(struct stack));
    st->top = NULL;
    return st;
}

int isempty(struct stack* st) {
    return st->top == NULL;
}

void push(struct stack* st, int data1) {
    struct node* temp = malloc(sizeof(struct node));
    temp->data = data1;
    temp->next = st->top;
    st->top = temp;
}

void pop(struct stack* st) {
    if (isempty(st)) {
        printf("stack underflow\n");
    } else {
        struct node* temp = st->top;
        st->top = st->top->next;
        free(temp);
    }
}

int peek(struct stack* st) {
    if (isempty(st)) {
        printf("stack underflow\n");
        return -1;     
    } else {
        return st->top->data;
    }
}

void initialize() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            adj[i][j] = 0;
        }
    }
}

void reverseGraph() {
    for (int i = 0; i < MAX; i++) {
        for (int j = i + 1; j < MAX; j++) {
            // Swap edges to reverse the graph
            int temp = adj[i][j];
            adj[i][j] = adj[j][i];
            adj[j][i] = temp;
        }
    }
}

void insertEdge(int n1, int n2) {
    adj[n1][n2] = 1;
}

void dfs(int start, int* visited, struct stack* st) {
    visited[start] = 1;
    
    for (int i = 0; i < MAX; i++) {
        if (adj[start][i] == 1 && !visited[i]) {
            dfs(i, visited, st);
        }
    }
    
    push(st, start);
}

void dfsPrint(int start, int* visited) {
    visited[start] = 1;
    printf("%d  ", start);

    for (int i = 0; i < MAX; i++) {
        if (adj[start][i] == 1 && !visited[i]) {
            dfsPrint(i, visited);
        }
    }
}

void kosaraju(struct stack* st) {
    int visited[MAX] = {0};

    // Reverse the graph
    reverseGraph();

    // Process all vertices in order defined by the stack
    while (!isempty(st)) {
        int ele = peek(st);
        pop(st);

        // Print all reachable nodes from ele
        if (!visited[ele]) {
            printf("Component: ");
            dfsPrint(ele, visited);
            printf("\n-------------------------------------\n");
        }
    }
}

int main() {
    initialize();
    
    // Insert edges for the graph
    insertEdge(0, 1);
    insertEdge(1, 2);
    insertEdge(2, 0);
    insertEdge(1, 3);
    insertEdge(3, 4);

    // Initialize the stack and visited array
    struct stack* st = createStack();
    int visited[MAX] = {0};

    // Perform DFS and push finishing times onto the stack
    for (int i = 0; i < MAX; i++) {
        if (!visited[i]) {
            dfs(i, visited, st);
        }
    }

    // Run Kosaraju’s algorithm to find and print components
    kosaraju(st);

    // Free the stack
    free(st);

    return 0;
}
