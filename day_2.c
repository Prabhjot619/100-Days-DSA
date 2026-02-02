#include <stdio.h>
#include <stdlib.h>

int main(){

int n=5;
int *arr;
arr=(int*)malloc(n*sizeof(int));
int pos;


for(int i=0;i<n;i++){
printf("Enter %d element of array:",i);
    scanf("%d",&arr[i]);
}
printf("Array:");
for(int i=0;i<n;i++){
    printf("%d\t",arr[i]);
}

printf("Enter position to delete:");
scanf("%d",&pos);

if(pos<0 || pos>n){
    printf("INVALID POSITION!!");

}
else{
    for(int i=pos;i<n-1;i++){
        arr[i]=arr[i+1];
    }

n--;

printf("Array after deletion:");
for(int i=0;i<n;i++){
    printf("%d\t",arr[i]);
}
printf("\n");

}

free(arr);
    return 0;
}