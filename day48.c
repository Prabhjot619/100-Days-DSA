/*Problem: Count Leaf Nodes

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
    if(data==-1) return NULL;
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
int countLeafNodes(struct node* root){
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL) return 1;
    return countLeafNodes(root->left)+countLeafNodes(root->right);
}
int main(){
    int n;
    printf("Enter the number of nodes: ");
    if(scanf("%d",&n)!=1 || n<=0){
        printf("0\n");
        return 0;
    }
    int* arr=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        printf("Enter node value (or -1 for NULL): ");
        scanf("%d",&arr[i]);
    }
    struct node* root=newNode(arr[0]);
    struct node** queue=(struct node**)malloc(n*sizeof(struct node*));
    int head=0,tail=0;
    queue[tail++]=root;
    int i=1;
    while(i<n && head<tail){
        struct node* curr=queue[head++];
        if(curr!=NULL){
            curr->left=newNode(arr[i++]);
            queue[tail++]=curr->left;
            if(i<n){
                curr->right=newNode(arr[i++]);
                queue[tail++]=curr->right;
            }
        }
    }
    printf("Number of leaf nodes: %d\n",countLeafNodes(root));
    free(arr);

    return 0;
}
