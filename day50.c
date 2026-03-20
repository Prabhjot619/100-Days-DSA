/*Problem: BST Search

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
int search(struct node* root,int key){
    if(root==NULL) return 0;
    if(root->data==key) return 1;
    if(key<root->data) return search(root->left,key);
    else return search(root->right,key);
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
    int key;
    printf("Enter value to search: ");
    scanf("%d",&key);
    if(search(root,key)) printf("Found\n");
    else printf("Not Found\n");
    return 0;
}
