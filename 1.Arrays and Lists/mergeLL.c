#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* getnode(int data) {
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = data;
    p->next = NULL;
    return p;
}

void insertend(struct node **head, int data) {
    struct node *newnode = getnode(data);
    if (*head == NULL) {
        *head = newnode;
    } else {
        struct node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newnode;
    }
}

void mergeSorted(struct node **head1, struct node **head2, struct node **result) {
    struct node *current1 = *head1;
    struct node *current2 = *head2;
    
    while (current1 != NULL && current2 != NULL) {
        if (current1->data <= current2->data) {
            insertend(result, current1->data);
            current1 = current1->next;
        } else {
            insertend(result, current2->data);
            current2 = current2->next;
        }
    }
    
    while (current1 != NULL) {
        insertend(result, current1->data);
        current1 = current1->next;
    }
    
    while (current2 != NULL) {
        insertend(result, current2->data);
        current2 = current2->next;
    }
}

int main() {
    struct node *head = NULL;
    struct node *head1 = NULL;
    struct node *mergedList = NULL;
    
    int n, data, n1, data1;
    
    printf("Enter the number of elements in the 1st list: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("Enter the %d element: ", i + 1);
        scanf("%d", &data);
        insertend(&head, data);
    }
    
    printf("Enter the number of elements in the 2nd list: ");
    scanf("%d", &n1);
    
    for (int i = 0; i < n1; i++) {
        printf("Enter the %d element: ", i + 1);
        scanf("%d", &data1);
        insertend(&head1, data1);
    }
    
   
    mergeSorted(&head, &head1, &mergedList);
    
    struct node *current = mergedList;
    printf("Merged List: ");
    
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    
    printf("NULL\n");
    
   
    current = mergedList;
    while (current != NULL) {
        struct node* temp = current;
        current = current->next;
        free(temp);
    }
    
    return 0;
}
