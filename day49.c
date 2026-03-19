/*Problem: BST Insert

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications*/
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node*left;
    struct node*right;
};
struct node* newNode(int data){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
struct node* insert(struct node* root,int data){
    if(root==NULL) return newNode(data);
    if(data<root->data) root->left=insert(root->left,data);
    else if(data>root->data) root->right=insert(root->right,data);
    return root;
}
void inorder(struct node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
int main(){
    int n;
    printf("Enter the number of nodes: ");
    if(scanf("%d",&n)!=1 || n<=0){
        printf("0\n");
        return 0;
    }
    struct node* root=NULL;
    for(int i=0;i<n;i++){
        int data;
        printf("Enter node value: ");
        scanf("%d",&data);
        root=insert(root,data);
    }
    printf("Inorder traversal of BST: ");
    inorder(root);
    printf("\n");
    return 0;
}
