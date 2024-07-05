#include <stdio.h>
#define n 5 

int deque[n];
int f = -1, r = -1;

void insertAtFront(int x)
{
    if ((f == 0 && r == n - 1) || (f == r + 1))
    {
        // To check if the queue is full
        printf("queue is full\n");
    }
    else if (f == -1 && r == -1)
    {
        // Queue is empty
        f = r = 0;
        deque[f] = x;
    }
    else if (f == 0)
    {
        // Queue at least has one element
        f = n - 1;
        deque[f] = x;
    }
    else
    {
        // Front is at the last position
        f--;
        deque[f] = x;
    }
}

void insertAtRear(int x) 
{
    if ((f == 0 && r == n - 1) || (f == r + 1))
    {
        // To check if the queue is full
        printf("queue is full\n");
    }
    else if (f == -1 && r == -1)
    {
        // Queue is empty
        f = r = 0;
        deque[r] = x;
    }
    else if (r == n - 1)
    {
        r = 0;
        deque[r] = x;
    }
    else
    {
        r++;
        deque[r] = x;
    }
}

void display()
{
    int i = f;
    while (i != r)
    {
        // To print until the rear is encountered
        printf("%d ", deque[i]);
        i = (i + 1)%n;
    }
    printf("%d ", deque[r]);
}

void getFront()
{
    if (f == -1 && r == -1)
    {
        printf("empty\n");
    }
    printf("%d\n", deque[f]);
}

void deleteAtFront() 
{
    if (f == -1 && r == -1)
    {
        printf("empty\n");
    }
    else if (f == r)
    {
        f = r = -1;
    }
    else if (f == n - 1)
    {
        printf("%d\n", deque[f]);
        f = 0;
    }
    else
    {
        printf("%d\n", deque[f]);
        f++;
    }
}

void deleteAtRear() 
{
    if (f == -1 && r == -1)
    {
        printf("empty\n");
    }
    else if (f == r)
    {
        f = r = -1;
    }
    else if (r == 0)
    {
        printf("%d\n", deque[r]);
        r = n - 1;
    }
    else
    {
        printf("%d\n", deque[r]);
        r--;
    }
}

int main()
{
    insertAtFront(1);
    insertAtFront(2);
    insertAtFront(3);
    insertAtRear(4);
    insertAtRear(5);
    deleteAtFront();
    deleteAtRear();
    display(); 

}
