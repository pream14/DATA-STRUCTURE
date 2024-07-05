#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enque(char a) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = a;
    newNode->next = NULL;

    if (rear == NULL) {
        front=rear=newNode;
    } else {
        rear->next = newNode;
        rear=newNode;
    }
}

char deque() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return '\0';
    }

    char data=front->data;
    struct Node* temp=front;

    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
    return data;
}

int main() {
    int choice;
    char element;

    while (1) {
        printf("\n1 - Enqueue\n2 - Dequeue\n3 - Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf(" %c", &element);
                enque(element);
                break;
            case 2:
                printf("Dequeued element: %c\n", deque());
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }

        printf("Queue: ");
        struct Node* current = front;
        while (current != NULL) {
            printf("%c ", current->data);
            current = current->next;
        }
        printf("\n");
    }

    return 0;
}
