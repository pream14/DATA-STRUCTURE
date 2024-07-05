#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void insertAtFront(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    if (front == NULL) {
        front = rear = newNode;
    } else {
        newNode->next = front;
        front = newNode;
    }
}

void insertAtRear(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void display() {
    struct Node* current = front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void getFront() {
    if (front == NULL) {
        printf("empty\n");
    } else {
        printf("%d\n", front->data);
    }
}

void deleteAtFront() {
    if (front == NULL) {
        printf("empty\n");
    } else {
        struct Node* temp = front;
        front = front->next;
        free(temp);
    }
}

void deleteAtRear() {
    if (rear == NULL) {
        printf("empty\n");
    } else {
        struct Node* current = front;
        while (current->next != rear) {
            current = current->next;
        }
        struct Node* temp = rear;
        rear = current;
        rear->next = NULL;
        free(temp);
    }
}

int main() {
    insertAtFront(1);
    insertAtFront(2);
    insertAtFront(3);
    insertAtRear(4);
    insertAtRear(5);
    deleteAtFront();
    deleteAtRear();
    display();

    return 0;
}
