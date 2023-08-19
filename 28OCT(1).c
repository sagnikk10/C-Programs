#include <stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;
node *new(int data){
    node *newnode=(node *)malloc(sizeof(node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

node *insert(node *root,int x){
    if(root==NULL){
        root=new(x);
    }
    else if(x<root->data){
        root->left=insert(root->left,x);
        
    }
    else 
    root->right=insert(root->right,x);
    return root;
}

int FindMin(node *root){
    if(root==NULL)
    return -1;
    else if(root->right==NULL)
    return root->data;
    return FindMin(root->right);
}


node *delete(node *root,int data){
    if(root==NULL)
    return root;
    else if(data<root->data){
        root->left=delete(root->left,data);
    }
    else if(data>root->data){
        root->right=delete(root->right,data);
    }
    else{
        if(root->left==NULL && root->right==NULL)
        {
            node *temp=root;
            root=NULL;
             free(temp);
            return root;
        }
        else if(root->left==NULL)
        {
            node *temp=root;
            root=root->right;
            free(temp);
            return root;
        }
        else if(root->right==NULL)
        {
            node *temp=root;
            root=root->left;
            free(temp);
            return root;
        }
        else
        {
            node *temp;
            temp->data=FindMin(root->right);
            root->data=temp->data;
            root->right=delete(root->right,temp->data);
        }
        return root;
    }
}
void print(node *root){
    if(root==NULL)
    {	
    return;
}
	print(root->left);
    printf("%d  ",root->data);
    print(root->right);
    }
    
int main() {
	struct node* root=NULL;

   root=insert(root,51);
    root=insert(root,12);

    root=insert(root,3);
    root=insert(root,4);
    
 print(root);
 
    return 0;
}
