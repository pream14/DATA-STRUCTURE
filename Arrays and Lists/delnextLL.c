#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node * getnode(int data);
void delAfter(struct node *head, int x);

int main() {
    struct node *head = NULL;
    struct node *p1, *p2, *p3, *p4;

    p1 = getnode(1);
    p2 = getnode(2);
    p3 = getnode(3);
    p4 = getnode(4);
    head = p1;
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;

    delAfter(head, 1);

    struct node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");

    return 0;
}

struct node* getnode(int data) {
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = data;
    p->next = NULL;
    return p;
}

void delAfter(struct node *head, int x) {
    struct node *current = head;

    while (current != NULL && current->data != x) {
        current = current->next;
    }

    if (current == NULL || current->next == NULL) {
        printf("Node with value %d not found or no node after it.\n", x);
        return;
    }

    struct node *temp = current->next;
    current->next = temp->next;
    free(temp);
}
