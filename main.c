#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main() {
    int N;
    scanf("%d", &N);

    int *arr = malloc(N * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Falha na alocação de memória\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    quickSortIterative(arr, 0, N - 1);

    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
}
