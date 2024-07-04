#include <stdio.h>
#include <stdlib.h>
#include<time.h>

struct Node {
    int data;
    struct Node* lc;
    struct Node* rc;
};

struct node {
    int a;
    struct node* next;
    struct node* prev;
};

struct Node* getnode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->lc = newNode->rc = NULL;
    return newNode;
}


void insertend(struct node** head, int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->a = data;
    newnode->next = NULL;
    newnode->prev = NULL;

    if (*head == NULL) {
        *head = newnode;
    } else {
        struct node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newnode;
        newnode->prev = current;
    }
}

void doubly(struct Node* root, struct node** head) {
    if (root == NULL) return;
    doubly(root->lc, head);
    insertend(head, root->data);
    doubly(root->rc, head);
}

void printList(struct node* head) {
     struct node* current1=head;
    while(current1!=NULL){
        printf("%p->",current1->prev);
        printf("\"%d\"->",current1->a);
        printf("%p\n",current1->next);
        
        current1=current1->next;
    }
    printf("NULL");
}

void inorder(struct Node *root) {
    if (root == NULL) return;
    inorder(root->lc);
    printf("%d ", root->data);
    inorder(root->rc);
}


void insert(struct Node **root, int data) {
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
    struct node* head = NULL;
    FILE *f;
    int b, data, k, i = 0;
      printf("enter the no of nodes:");
     scanf("%d", &b);

    int *a = (int *)malloc(b * sizeof(int));

    f = fopen("shuffled_numbers.txt", "r");

    for (int i = 0; i < b; i++) {
        fscanf(f, "%d ", &a[i]);
        insert(&root,a[i]);
    }
    // inorder(root);
    printf("\nDoubly linked list from the binary tree:\n");
     clock_t start=clock();
    doubly(root, &head);
    clock_t end= clock();
    double execution_time = (double)(end - start) / CLOCKS_PER_SEC;
     printf("execution time:%f seconds",execution_time);
    // printList(head);

    return 0;
}



// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// struct Node {
//     int data;
//     struct Node* lc;
//     struct Node* rc;
// };

// struct node {
//     int a;
//     struct node* next;
//     struct node* prev;
// };

// struct Node* getnode(int data) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->lc = newNode->rc = NULL;
//     return newNode;
// }

// void insertend(struct node** head, int data) {
//     struct node* newnode = (struct node*)malloc(sizeof(struct node));
//     newnode->a = data;
//     newnode->next = NULL;
//     newnode->prev = NULL;

//     if (*head == NULL) {
//         *head = newnode;
//     } else {
//         struct node* current = *head;
//         while (current->next != NULL) {
//             current = current->next;
//         }
//         current->next = newnode;
//         newnode->prev = current;
//     }
// }

// void doubly(struct Node* root, struct node** head) {
//     if (root == NULL) return;
//     doubly(root->lc, head);
//     insertend(head, root->data);
//     doubly(root->rc, head);
// }

// void printList(struct node* head) {
//     struct node* current1 = head;
//     while (current1 != NULL) {
//         printf("%p->", current1->prev);
//         printf("\"%d\"->", current1->a);
//         printf("%p\n", current1->next);

//         current1 = current1->next;
//     }
//     printf("NULL");
// }

// void inorder(struct Node* root) {
//     if (root == NULL) return;
//     inorder(root->lc);
//     printf("%d ", root->data);
//     inorder(root->rc);
// }

// void insert(struct Node** root, int data) {
//     if (*root == NULL) {
//         *root = getnode(data);
//     } else if (data <= (*root)->data) {
//         insert(&(*root)->lc, data);
//     } else {
//         insert(&(*root)->rc, data);
//     }
// }

// int main() {
//     struct Node* root = NULL;
//     struct node* head = NULL;
//     FILE* f;
//     int b, data, k, i = 0;
//     printf("Enter the no of nodes:");
//     scanf("%d", &b);

//     int* a = (int*)malloc(b * sizeof(int));

//     f = fopen("shuffled_numbers.txt", "r");

//     for (int i = 0; i < b; i++) {
//         fscanf(f, "%d ", &a[i]);
//         insert(&root, a[i]);
//     }

//     printf("\nDoubly linked list from the binary tree:\n");
//     clock_t start = clock();
//     doubly(root, &head);
//     clock_t end = clock();
//     double execution_time = (double)(end - start) / CLOCKS_PER_SEC;
//     printf("Execution time: %f seconds\n", execution_time);

//     // Save input size and execution time to a CSV file (Append mode)
//     FILE* outputFile = fopen("BtToDl.csv", "a");
//     fprintf(outputFile, "%d,%f\n", b, execution_time);
//     fclose(outputFile);

//     // printList(head);

//     return 0;
// }
