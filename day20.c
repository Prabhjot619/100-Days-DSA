/*Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.

Input:
- First line: integer n
- Second line: n integers

Output:
- Print the count of subarrays having sum zero

Example:
Input:
6
1 -1 2 -2 3 -3

Output:
6

Explanation: A subarray is a continuous part of the array. For the input array 1 -1 2 -2 3 -3, the following subarrays have sum zero: [1, -1], [2, -2], [3, -3], [1, -1, 2, -2], [2, -2, 3, -3], and [1, -1, 2, -2, 3, -3]. Since there are 6 such subarrays, the output is 6.*/
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    long long arg1 = *(const long long*)a;
    long long arg2 = *(const long long*)b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int main() {
    int n;
    printf("Enter size of array:");
    scanf("%d", &n);

    long long *prefix_sums = (long long*)malloc((n + 1) * sizeof(long long));
    prefix_sums[0] = 0;

    long long current_sum = 0;
    for (int i = 1; i <= n; i++) {
        int val;
        printf("Enter the %d element of array:",i);
        scanf("%d", &val);
        current_sum += val;
        prefix_sums[i] = current_sum;
    }

    qsort(prefix_sums, n + 1, sizeof(long long), compare);

    long long total_count = 0;
    long long frequency = 1;

    for (int i = 1; i <= n; i++) {
        if (prefix_sums[i] == prefix_sums[i - 1]) {
            frequency++;
        } else {
            total_count += (frequency * (frequency - 1)) / 2;
            frequency = 1;
        }
    }
    total_count += (frequency * (frequency - 1)) / 2;

    printf("%lld\n", total_count);
    free(prefix_sums);
    return 0;
}
