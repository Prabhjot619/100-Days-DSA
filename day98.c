// Problem: Given intervals, merge all overlapping ones.

#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int start;
    int end;
} Interval;

int compare(const void *a, const void *b) {
    return ((Interval *)a)->start - ((Interval *)b)->start;
}

void mergeIntervals(Interval arr[], int n) {
    qsort(arr, n, sizeof(Interval), compare);

    Interval res[n];
    int j = 0;

    res[j] = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i].start <= res[j].end) {
            if (arr[i].end > res[j].end)
                res[j].end = arr[i].end;
        } else {
            j++;
            res[j] = arr[i];
        }
    }

    for (int i = 0; i <= j; i++) {
        printf("(%d, %d) ", res[i].start, res[i].end);
    }
}

int main() {
    Interval arr[] = {{1,3}, {2,6}, {8,10}, {15,18}};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeIntervals(arr, n);
    return 0;
}
