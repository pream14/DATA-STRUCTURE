// #include <stdio.h>
// #include <stdlib.h>

// #define n 100

// int data[n];
// int priorities[n];
// int size = 0;

// void enqueue(int value, int priority) {
//     if (size >= n) {
//         printf("Priority Queue is full. Cannot enqueue.\n");
//         return;
//     }

//     int i = size - 1;
//     while (i >= 0 && priority < priorities[i]) {  // Reverse the comparison order
//         data[i + 1] = data[i];
//         priorities[i + 1] = priorities[i];
//         i--;
//     }

//     data[i + 1] = value;
//     priorities[i + 1] = priority;
//     size++;
// }

// int dequeue() {
//     if (size == 0) {
//         printf("Priority Queue is empty. Cannot dequeue.\n");
//         return -1;
//     }

//     int value = data[0];
//     int priority = priorities[0];

//     for (int i = 1; i < size; i++) {
//         data[i - 1] = data[i];
//         priorities[i - 1] = priorities[i];
//     }

//     size--;

//     printf("Dequeued: Value = %d, Priority = %d\n", value, priority);

//     return value;
// }

// int main() {
//     enqueue(5, 2);
//     enqueue(10, 1);
//     enqueue(20, 3);

//     while (size > 0) {
//         dequeue();
//     }

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// struct node
// {
//     int info, priority;
//     struct node *next;
// };

// struct node *start = NULL;

// void insert(int x, int n)
// {
//     struct node *p, *prev;
//     struct node *newnode;

//     newnode = (struct node *)malloc(sizeof(struct node));
//     prev = (struct node *)malloc(sizeof(struct node));

//     newnode->info = x;
//     newnode->priority = n;
//     newnode->next = NULL;

//     if (start == NULL)
//         start = newnode;
//     else if (newnode->priority > start->priority)
//     {
        

//         prev = start;
//         p = start;

//         while (p != NULL && p->priority <= newnode->priority)
//         {
//             prev = p;
//             p = p->next;
//         }

//         newnode->next = p;
//         prev->next = newnode;
//      }
//     else
//     {
//         newnode->next = start;
//         start = newnode;
//     }
// }

// void delete()
// {
//     struct node *p;

//     if (start == NULL)
//         printf("Queue is Empty\n");
//     else
//     {
//         p = start;
//         start = start->next;
//         printf("The deleted node is %d\n", p->info);
//         free(p);
//     }
// }

// void display()
// {
//     struct node *p;

//     if (start == NULL)
//         printf("Queue is Empty\n");
//     else
//     {
//         p = start;
//         printf("The elements in the queue are\n");
//         printf("PRIORITY INFO\n");
//         while (p != NULL)
//         {
//             printf("%d %d\n", p->priority, p->info);
//             p = p->next;
//         }
//     }
// }

// int main()
// {
//     int x, choice, n;

//     // Directly execute operations without user input
//     x = 10;
//     n = 2;
//     insert(x, n);

//     delete();

//     x = 20;
//     n = 1;
//     insert(x, n);

//     display();

//     printf("Thank you\n");
//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>

#define a 100

struct node
{
    int info, priority;
};

struct node Queue[a];
int size = 0;

void insert(int x, int n)
{
    if (size>=a)
    {
        printf("Queue is full. Cannot insert.\n");
        return;
    }
    int i=size - 1;
    while (i >= 0 && n <Queue[i].priority)
    {
        Queue[i + 1]=Queue[i];
        i--;
    }
    Queue[i + 1].info = x;
    Queue[i + 1].priority = n;
    size++;
}

void delete()
{
    if (size == 0)
    {
        printf("Queue is empty. Cannot delete.\n");
        return;
    }
    int value = Queue[0].info;
    for (int i = 1; i < size; i++)
    {
        Queue[i - 1]=Queue[i];
    }
    size--;
    printf("The deleted node is %d\n", value);
}

void display()
{
    if (size == 0)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("The elements in the queue are\n");
        printf("PRIORITY INFO\n");
        for (int i = 0; i < size; i++)
        {
            printf("%d %d\n", Queue[i].priority, Queue[i].info);
        }
    }
}

int main()
{
    int x, n;
    x = 10;
    n = 2;
    insert(x, n);
    delete();
    x = 20;
    n = 1;
    insert(x, n);
    display();
    printf("Thank you\n");
    return 0;
}
