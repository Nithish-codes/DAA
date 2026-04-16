#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1, n2;
    int *L, *R;

    n1 = m - l + 1;
    n2 = r - m;

    L = (int *)malloc(n1 * sizeof(int));
    R = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int arr[], int l, int r)
{
    int m;

    if (l < r)
    {
        m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void copyArray(int src[], int dest[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        dest[i] = src[i];
}

void printArray(int arr[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int main()
{
    clock_t start, end;
    double time_taken;

    int original[] = {12, 11, 13, 5, 6, 7};
    int arr[6];
    int n = 6;
    int i;

    printf("Given array:\n");
    printArray(original, n);

    start = clock();

    for (i = 0; i < 10000; i++)
    {
        copyArray(original, arr, n);
        mergeSort(arr, 0, n - 1);
    }

    end = clock();

    printf("\n\nSorted array:\n");
    printArray(arr, n);

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\n\nTime taken: %lf seconds\n", time_taken);

    return 0;
}