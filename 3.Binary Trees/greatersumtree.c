#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int data;
    struct Node* lc;
    struct Node* rc;
};

void modifyTree(struct Node *root, int *sum) {
    if (root == NULL) return;
    modifyTree(root->rc, sum);
    *sum = *sum + root->data;
    root->data = *sum - root->data;
    modifyTree(root->lc, sum);
}

struct Node* getnode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->lc = newNode->rc = NULL;
    return newNode;
}

void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->lc);
    printf("%d ", root->data);
    inorder(root->rc);
}

void insert(struct Node** root, int data) {
    if (*root == NULL) {
        *root = getnode(data);
    } else if (data <= (*root)->data) {
        insert(&(*root)->lc, data);
    } else {
        insert(&(*root)->rc, data);
    }
}

int main() {
    struct Node* root = NULL;
    FILE* f;
    int b, data, k, i = 0;
    printf("Enter the no of nodes:");
    scanf("%d", &b);

    int* a = (int*)malloc(b * sizeof(int));

    f = fopen("shuffled_numbers.txt", "r");

    for (int i = 0; i < b; i++) {
        fscanf(f, "%d ", &a[i]);
        insert(&root, a[i]);
    }

    printf("\nInorder traversal before conversion:\n");
    // inorder(root);

    printf("\nConverting to Greater Sum Tree...\n");
    clock_t start = clock();
    int sum = 0;
    modifyTree(root, &sum);
    clock_t end = clock();
    double execution_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Execution time: %f seconds\n", execution_time);

    // Save input size and execution time to a CSV file (Append mode)
    FILE* outputFile = fopen("gretsum.csv", "a");
    fprintf(outputFile, "%d,%f\n", b, execution_time);
    fclose(outputFile);

    // printf("\nInorder traversal after conversion:\n");
    // inorder(root);

    return 0;
}
