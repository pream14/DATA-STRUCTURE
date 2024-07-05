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

void modifyTree(struct node *root, int *sum) {
    if (root == NULL) return;

    // Traverse the right subtree first
    modifyTree(root->rc, sum);

    // Update the sum with the current node's value
    *sum = *sum + root->data;

    // Update the current node's value
    root->data = *sum - root->data;

    // Traverse the left subtree
    modifyTree(root->lc, sum);
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
    int a, data;
    struct node *root = NULL;

    printf("Enter the number of nodes: ");
    scanf("%d", &a);

    for (int i = 0; i < a; i++) {
        printf("Enter the data: ");
        scanf("%d", &data);
        insert(&root, data);
    }

    printf("Inorder Traversal of the Tree before modification:\n");
    inorder(root);
    printf("\n");

    int sum = 0;
    modifyTree(root, &sum);

    printf("Inorder Traversal of the Tree after modification:\n");
    inorder(root);
    printf("\n");

    return 0;
}
