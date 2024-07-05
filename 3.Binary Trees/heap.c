#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void percolateup(int *arr, int i) {
    while (i > 0 && arr[i / 2] > arr[i]) {
        swap(&arr[i / 2], &arr[i]);
        i = i / 2;
    }
}

int percolatedown(int *arr, int *a, int i) {
    if (*a == 0) {
        printf("Heap is empty\n");
        return -1;
    }

    int b = arr[0];
    if (*a == 1) {
        *a = 0;
    } else {
        arr[0] = arr[*a - 1];
        *a = *a - 1;
    }

    while (1) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int f = i;

        if (l < *a && arr[l] < arr[f]) {
            f = l;
        }

        if (r < *a && arr[r] < arr[f]) {
            f = r;
        }

        if (f != i) {
            swap(&arr[i], &arr[f]);
            i = f;
        } else {
            break;
        }
    }

    return b;
}

void insert(int *arr, int *size, int value) {
    arr[*size] = value;
    percolateup(arr, *size);
    (*size)++;
}

int extractMin(int *arr, int *size) {
    return percolatedown(arr, size, 0);
}

void heapSort(int *arr, int size) {
    // Build max heap
    for (int i = size / 2 - 1; i >= 0; i--) {
        percolatedown(arr, &size, i);
    }

    // Extract elements from the heap in decreasing order
    for (int i = size - 1; i > 0; i--) {
        // Swap the root (max element) with the last element
        swap(&arr[0], &arr[i]);
        
        // Reduce the heap size and percolate down to maintain the heap property
        percolatedown(arr, &size, 0);
    }
}

int main() {
    int a, d, arr[100], size = 0;
    printf("Enter the number of nodes: ");
    scanf("%d", &a);

    for (int i = 0; i < a; i++) {
        printf("Enter the %d element: ", i + 1);
        scanf("%d", &d);
        insert(arr, &size, d);
    }

    printf("Priority Queue:\n");
    for (int i = 0; i < size; i++) {
        printf("%d\n", arr[i]);
    }

    int extractedMin = extractMin(arr, &size);

    printf("After extracting min:\n");
    for (int i = 0; i < size; i++) {
        printf("%d\n", arr[i]);
    }

    if (extractedMin != -1) {
        printf("Extracted min value: %d\n", extractedMin);
    } else {
        printf("Heap is empty\n");
    }

    // Call heapSort function to sort the array
    heapSort(arr, size);

    printf("After heap sort (ascending order):\n");
    for (int i = 0; i < size; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}
