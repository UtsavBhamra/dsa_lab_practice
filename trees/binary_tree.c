#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* insert_node(struct node* prev,int data1,int side){
    if(side==0){
        struct node* temp = malloc(sizeof(struct node));
        temp->data = data1;
        prev->left = temp;
        return temp;
    }
    else if(side==1){
        struct node* temp = malloc(sizeof(struct node));
        temp->data = data1;
        prev->right = temp;
        return temp;
    }
}

void preorder(struct node* root){
    if(root==NULL){
        return;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

void inorder(struct node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}


int main(){
    struct node* root = malloc(sizeof(struct node));
    root->data = 1;
    struct node* node1 = insert_node(root,2,0);
    struct node* node2 = insert_node(root,3,1);
    struct node* node3 = insert_node(node1,4,0);
    
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    inorder(root);
    return 0;
}