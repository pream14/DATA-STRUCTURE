#include <stdio.h>
#include <stdlib.h>

struct node {
    int data, exp;
    struct node *next;
};

struct node *getnode(int data, int exp) {
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = data;
    p->exp = exp;
    p->next = NULL;
    return p;
}

void insert(struct node **head, int data, int exp) {
    struct node *current = *head;
    struct node *newnode = getnode(data, exp);

    if (*head == NULL) {
        *head = newnode;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newnode;
    }
}

struct node *add(struct node *head1, struct node *head2) {
    struct node *current1 = head1;
    struct node *current2 = head2;
    struct node *result = NULL;
    struct node *currentResult = NULL;

    while (current1 != NULL && current2 != NULL) {
        if (current1->exp == current2->exp) {
            int sum = current1->data + current2->data;
            insert(&result, sum, current1->exp);
            current1 = current1->next;
            current2 = current2->next;
        } else if (current1->exp > current2->exp) {
            insert(&result, current1->data, current1->exp);
            current1 = current1->next;
        } else {
            insert(&result, current2->data, current2->exp);
            current2 = current2->next;
        }
    }

    // Copy any remaining terms from both input polynomials
    while (current1 != NULL) {
        insert(&result, current1->data, current1->exp);
        current1 = current1->next;
    }

    while (current2 != NULL) {
        insert(&result, current2->data, current2->exp);
        current2 = current2->next;
    }

    return result;
}

void print(struct node *head) {
    struct node *current = head;
    if (current == NULL) {
        printf("0\n");
        return;
    }

    while (current != NULL) {
        printf("(%dx^%d)", current->data, current->exp);
        current = current->next;
        if (current != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    struct node *head1 = NULL;
    struct node *head2 = NULL;

    int n1, n2, a, x;
    
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n1);

    for (int i = 0; i < n1; i++) {
        printf("Enter the coefficient for term %d: ", i + 1);
        scanf("%d", &a);
        printf("Enter the exponent for term %d: ", i + 1);
        scanf("%d", &x);
        insert(&head1, a, x);
    }

    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n2);

    for (int i = 0; i < n2; i++) {
        printf("Enter the coefficient for term %d: ", i + 1);
        scanf("%d", &a);
        printf("Enter the exponent for term %d: ", i + 1);
        scanf("%d", &x);
        insert(&head2, a, x);
    }

    printf("First Polynomial: ");
    print(head1);

    printf("Second Polynomial: ");
    print(head2);

    struct node *sum = add(head1, head2);
    printf("Sum of Polynomials: ");
    print(sum);

    return 0;
}
