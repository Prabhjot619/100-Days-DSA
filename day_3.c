/*Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.

Input:
- First line: integer n (array size)
- Second line: n space-separated integers
- Third line: integer k (key to search)

Output:
- Line 1: "Found at index i" OR "Not Found"
Line 2: "Comparisons = c"

Example:
Input:
5
10 20 30 40 50
30

Output:
Found at index 2
Comparisons = 3

Explanation: Compared with 10, 20, 30 (found at index 2 with 3 comparisons)*/

#include <stdio.h>
#include <stdlib.h>



int main(){
int n;
int index=-1;
int tarnm;
int comp=0;

printf("Enter size of array:");
scanf("%d",&n);


int *arr;
arr=(int*)malloc(n*sizeof(int));

for(int i=0;i<n;i++){
    printf("Enter %d element of array:",i);
    scanf("%d",&arr[i]);
}
printf("Enter target number:");
scanf("%d",&tarnm);

for(int i=0;i<n;i++){

     comp++;
    if(arr[i]==tarnm){
        index=i;
        break;
    }

}

if(index != -1){
    printf("Number found at index: %d\n",index);
}
else{
    printf("Not found in array \n");
}
printf("Number of comparisons: %d\n",comp);

free(arr);

    return 0;
}