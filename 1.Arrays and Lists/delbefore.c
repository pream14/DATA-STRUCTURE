#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* getnode(int data);
void delBefore(struct node **head, int x);

int main() {
    int n=5;
    struct node *head = NULL;
    struct node *p1, *p2, *p3;
    // for(int i=0;i<=n;i++){
    //     struct node* current =getnode(i);
    //     head->next=current;
    //     head=current;

    // }
    p1 = getnode(1);
    p2 = getnode(4);
    p3=getnode(5);
    head = p1;
    p1->next = p2;
    p2->next=p3;


    
    delBefore(&head,1);
    struct node *current = head;
    while (current!=  NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");

    return 0;
}

struct node *getnode(int data){
    struct node *p=(struct node *)malloc(sizeof(struct node));
    p->data=data;
    p->next=NULL;
    return p;
}

// void del(struct node **head, int delno) {
//     struct node *current = *head;
//     struct node *prev = NULL;

//     if (*head == NULL) {
//         printf("List is empty\n");
//         return;
//     }

    
//     if (current != NULL && current->data == delno) {
//         *head = current->next;
//         free(current);
//         return;
//     }

    
//     while (current != NULL && current->data != delno) {
//         prev = current;
//         current = current->next;
//     }

    
//     if (current == NULL) {
//         printf("Node with data %d not found\n", delno);
//         return;
//     }

    
//     prev->next = current->next;

   
//     free(current);
// }

void delBefore(struct node **head, int x) {
    struct node *current = *head;
    struct node *prev = NULL;

    if (*head == NULL || (*head)->next == NULL) {
        printf("List is empty or has only one node. Cannot delete before.\n");
        return;
    }

    // Traverse the list to find the node with value x
    while (current->next != NULL && current->next->data != x) {
        prev = current;
        current = current->next;
    }

    // Check if the node with value x was found
    if (current->next == NULL) {
        printf("Node with value %d not found.\n", x);
        return;
    }

    // Check if the node with value x is the first node in the list
    if (prev == NULL) {
        struct node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    // Delete the node before the one with value x
    struct node *temp = prev->next;
    prev->next = current->next;
    free(temp);
}
