/*Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4
2
1 5 6
3
7

Explanation:
Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.*/
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
struct node* insertLevelOrder(int arr[], struct node* root, int i, int n){
    if(i<n){
        struct node* temp = newNode(arr[i]);
        root = temp;
        root->left = insertLevelOrder(arr, root->left, 2*i + 1, n);
        root->right = insertLevelOrder(arr, root->right, 2*i + 2, n);
    }
    return root;
}
void verticalOrder(struct node* root, int hd, int min_hd, int max_hd, int* arr[], int* count[]){
    if(root==NULL) return;
    if(hd<min_hd) *min_hd=hd;
    if(hd>max_hd) *max_hd=hd;
    arr[hd+1000][(*count)[hd+1000]++]=root->data;
    verticalOrder(root->left, hd-1, min_hd, max_hd, arr, count);
    verticalOrder(root->right, hd+1, min_hd, max_hd, arr, count);
}
int main(){
    int n;
    printf("Enter the number of nodes: ");
    if(scanf("%d",&n)!=1 || n<=0){
        printf("0\n");
        return 0;
    }
    int arr[n];
    printf("Enter the level-order traversal (-1 for NULL): ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    struct node* root = insertLevelOrder(arr, root, 0, n);
    int* vertical_arr[2001];
    int count[2001]={0};
    for(int i=0;i<2001;i++){
        vertical_arr[i]=(int*)malloc(n*sizeof(int));
    }
    int min_hd=0, max_hd=0;
    verticalOrder(root, 0, &min_hd, &max_hd, vertical_arr, count);
    for(int i=min_hd+1000; i<=max_hd+1000; i++){
        for(int j=0; j<count[i]; j++){
            printf("%d ", vertical_arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
