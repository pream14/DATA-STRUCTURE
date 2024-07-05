#include<time.h>
#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node *lc, *rc;
};

void inorder(struct node *root) {
    if (root == NULL) return;
    inorder(root->lc);
    printf("%d ", root->data);
    inorder(root->rc);
}

void kth(struct node *root, int *arr, int *i) {
    if (root == NULL) return;
    else {
        kth(root->lc, arr, i);
        arr[(*i)++] = root->data;
        kth(root->rc, arr, i);
    }
}

struct node *getnode(int data) {
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = data;
    p->lc = NULL;
    p->rc = NULL;
    return p;
}

void insert(struct node **root, int data) {
    if (*root == NULL) {
        *root = getnode(data);
    } else if (data <= (*root)->data) {
        insert(&(*root)->lc, data);
    } else {
        insert(&(*root)->rc, data);
    }
}

int main() {
    FILE *f;
    int b, data, k, i = 0;
      printf("enter the no of nodes:");
     scanf("%d", &b);
    struct node *root = NULL; // Use local variable instead of global

    int *a = (int *)malloc(b * sizeof(int));

    f = fopen("shuffled_numbers.txt", "r");

    for (int i = 0; i < b; i++) {
        fscanf(f, "%d ", &a[i]);
        insert(&root,a[i]);
    }
    

    printf("\nenter the Kth value for the smallest element:");
    scanf("%d", &k);

    int *arr = (int *)malloc(b * sizeof(int));
     clock_t start=clock();
    kth(root, arr, &i);

    if (k <= b) {
        printf("\nThe %dth smallest element is: %d\n", k, arr[k - 1]);
    } else {
        printf("\nThere are less than %d elements in the tree.\n", k);
    }
    clock_t end= clock();
    double execution_time = (double)(end - start) / CLOCKS_PER_SEC;
     printf("execution time:%f seconds",execution_time);
    // Free the allocated memory for the array
    free(arr);

    return 0;
}


// #include <time.h>
// #include <stdlib.h>
// #include <stdio.h>

// struct node {
//     int data;
//     struct node *lc, *rc;
// };

// void inorder(struct node *root) {
//     if (root == NULL) return;
//     inorder(root->lc);
//     printf("%d ", root->data);
//     inorder(root->rc);
// }

// void kth(struct node *root, int *arr, int *i) {
//     if (root == NULL) return;
//     else {
//         kth(root->lc, arr, i);
//         arr[(*i)++] = root->data;
//         kth(root->rc, arr, i);
//     }
// }

// struct node *getnode(int data) {
//     struct node *p = (struct node *)malloc(sizeof(struct node));
//     p->data = data;
//     p->lc = NULL;
//     p->rc = NULL;
//     return p;
// }

// void insert(struct node **root, int data) {
//     if (*root == NULL) {
//         *root = getnode(data);
//     } else if (data <= (*root)->data) {
//         insert(&(*root)->lc, data);
//     } else {
//         insert(&(*root)->rc, data);
//     }
// }

// int main() {
//     FILE *f;
//     int b, data, k, i = 0;
//     printf("Enter the no of nodes:");
//     scanf("%d", &b);
//     struct node *root = NULL; // Use local variable instead of global

//     int *a = (int *)malloc(b * sizeof(int));

//     f = fopen("shuffled_numbers.txt", "r");

//     for (int i = 0; i < b; i++) {
//         fscanf(f, "%d ", &a[i]);
//         insert(&root, a[i]);
//     }

//     printf("\nEnter the Kth value for the smallest element:");
//     scanf("%d", &k);

//     int *arr = (int *)malloc(b * sizeof(int));
//     clock_t start = clock();
//     kth(root, arr, &i);
//     clock_t end = clock();
//     double execution_time = (double)(end - start) / CLOCKS_PER_SEC;

//     // Print the result
//     if (k <= b) {
//         printf("\nThe %dth smallest element is: %d\n", k, arr[k - 1]);
//     } else {
//         printf("\nThere are less than %d elements in the tree.\n", k);
//     }

//     // Save input size and execution time to a CSV file
//     FILE *outputFile = fopen("time_complexity_data.csv", "a");
//     // fprintf(outputFile, "Input Size,Execution Time\n");
//     fprintf(outputFile, "%d,%f\n", b, execution_time);
//     fclose(outputFile);

//     // Free the allocated memory for arrays
//     free(arr);
//     free(a);

//     return 0;
// }










// #include <time.h>
// #include <stdlib.h>
// #include <stdio.h>

// struct node {
//     int data;
//     struct node *lc, *rc;
// };

// void inorder(struct node *root) {
//     if (root == NULL) return;
//     inorder(root->lc);
//     // printf("%d ", root->data);
//     inorder(root->rc);
// }

// void kth(struct node *root, int *arr, int *i) {
//     if (root == NULL) return;
//     else {
//         kth(root->lc, arr, i);
//         arr[(*i)++] = root->data;
//         kth(root->rc, arr, i);
//     }
// }

// struct node *getnode(int data) {
//     struct node *p = (struct node *)malloc(sizeof(struct node));
//     p->data = data;
//     p->lc = NULL;
//     p->rc = NULL;
//     return p;
// }

// void insert(struct node **root, int data) {
//     if (*root == NULL) {
//         *root = getnode(data);
//     } else if (data <= (*root)->data) {
//         insert(&(*root)->lc, data);
//     } else {
//         insert(&(*root)->rc, data);
//     }
// }

// int main() {
//     FILE *f;
//     int b, data, k, i = 0;

//     // Loop through different input sizes
//     for (int size = 100; size <= 1000; size += 100) {
//         struct node *root = NULL;

//         int *a = (int *)malloc(size * sizeof(int));

//         f = fopen("shuffled_numbers.txt", "r");

//         for (int i = 0; i < size; i++) {
//             fscanf(f, "%d ", &a[i]);
//             insert(&root, a[i]);
//         }

//         int *arr = (int *)malloc(size * sizeof(int));
//         clock_t start = clock();
//         kth(root, arr, &i);
//         clock_t end = clock();

//         double execution_time = (double)(end - start) / CLOCKS_PER_SEC;
//         printf("Input Size: %d, Execution Time: %f seconds\n", size, execution_time);

//         // Free the allocated memory for arrays
//         free(a);
//         free(arr);
//     }

//     return 0;
// }
