#include <stdio.h>

int main() {
    int n, pos, x;
    int i;

    scanf("%d", &n);

    int arr[n + 1];   

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &pos);

    scanf("%d", &x);

    for (i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = x;

    for (i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
