#include<stdio.h>
#include<stdlib.h>

//For searching, just store the preorder in an array and check if the elemnt is there in the array
//write height and depth code

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* findMax(struct node* root){
    if(root==NULL){
        return root;
    }
    else if(root->right==NULL){
        return root;
    }
    else{
        return findMax(root->right);
    }
}

struct node* findMin(struct node* root){
    if(root==NULL){
        return root;
    }
    else if(root->left==NULL){
        return root;
    }
    else{
        return findMin(root->left);
    }
}

struct node* findNode(struct node* root,int key){
    struct node* temp = root;
    while(temp!=NULL){
        if(key == temp->data){
            return temp;
        }
        else if(key < temp->data){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    printf("Does Not exist");
    struct node* temp2 = malloc(sizeof(struct node));
    temp2->left = NULL;
    temp2->right =NULL;
    return temp2;
}

struct node* createNode(int data){
    struct node* temp  =malloc(sizeof(struct node));
    temp->data = data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

struct node* addNode(struct node* root,int data1){
    struct node* dummy = root;
    if(root==NULL){
        struct node* temp = createNode(data1);
        root = temp;
        return root;
    }
    if(data1 < root->data){
        root->left = addNode(root->left,data1);
    }
    else{
        root->right = addNode(root->right,data1);
    }
    return root;
}

struct node* deleteNode(struct node* root,int data1){
    if(root==NULL){
        printf("Node not found");
        return root;
    }
    else if(data1 < root->data){
        root->left = deleteNode(root->left,data1);
    }
    else if(data1 > root->data){
        root->right = deleteNode(root->right,data1);
    }
    else{
        if(root->left==NULL && root->right==NULL){
            free(root);
            root = NULL;
            return root;
        }
        else if(root->left==NULL){
            struct node* temp = root;
            root = root->right;
            free(temp);
            return root;
        }
        else if(root->right==NULL){
            struct node* temp = root->left;
            root = root->left;
            free(temp);
            return root;
        }
        else{
            struct node* temp = findMax(root->left);
            root->data = temp->data;
            root->left = deleteNode(root->left,temp->data);
        }
    }
    return root;
}

void preorder(struct node* root){
    if(root==NULL){
        return;
    }
    printf("%d",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d",root->data);
}

void inorder(struct node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);
}

int main(){
    int optNum,data,del,par,sel=1;
	struct node* root=NULL;
	do{
		printf("\n\n1.Print\n2.Add Node\n3.Delete\n");
		printf("Choose the option number: ");
		scanf("%d",&optNum);
		switch(optNum){
			case 1:
      sel = 1;
    	while(sel!=0)
    	{
    		printf("\n\n1.Preorder\n2.Inorder\n3.Postorder");
    		printf("\nChoose the option number: ");
    		scanf("%d",&sel);
        printf("\nThe tree is: ");
    		switch(sel)
        {
    			case 1:
          preorder(root);
    			break;

    			case 2:
    			inorder(root);
    			break;

    			case 3:
    			postorder(root);
    			break;
    		}
      }
			break;

			case 2:
      printf("\n\nEnter data: ");
      scanf("%d", &data);
      root = addNode(root, data);
			break;

			case 3:
			printf("\nEnter node to be deleted: ");
			scanf("%d",&data);
  		root = deleteNode(root, data);
			printf("\nNode deleted");
			break;

			case 4:
			break;

			default:
			printf("\nPlease sleect correct option");
			break;
		}
	} while(optNum != 4);
}