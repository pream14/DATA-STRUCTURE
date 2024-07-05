#include<stdio.h>
#include<stdlib.h>
#define n 5
char queue[n];
int f=-1;
int r=-1;
void enque(int a){
    if((f==0&&r==n-1)||(r==f-1)){
        printf("queue is full\n");
        return;
    }
    else if(f==-1&&r==-1){
        f=r=0;
        queue[r]=a;
    }
    else if(r==n-1&&f!=0){
        r=0;
        queue[r]=a;
    }
    else{
        r++;
        queue[r]=a;
    }

}
int deque(){
    if(f==-1){
        printf("queue is empty");
        return -1;
    }
    int a=queue[f];
    if(f==r){
        f=r=-1;
    }
    else if(f==n-1){
        f=0;
    }
    else{
        f++;
    }
    return a;


}
int main(){
    enque('a');
    enque('b');
    enque('c');
   
    printf("%c\n",deque());
    enque('d');
    printf("%c\n",deque());
    printf("%c\n",deque());
    enque('e');
    printf("%c\n",deque());
    printf("%c\n",deque());
    printf("%c\n",deque());
    printf("f=%d,r= %d",f,r);
 }

#include <stdio.h>
#include <stdlib.h>
#define n 100

char queue[n];
int f = -1;
int r = -1;

void enque(char a) {
    if ((f == 0 && r == n - 1) || (r == f - 1)) {
        printf("Queue is full\n");
        return;
    } else if (f == -1 && r == -1) {
        f = r = 0;
        queue[r] = a;
    } else if (r == n - 1 && f != 0) {
        r = 0;
        queue[r] = a;
    } else {
        r++;
        queue[r] = a;
    }
}

char deque() {
    if (f == -1) {
        printf("Queue is empty\n");
        return '\0';
    }
    char a = queue[f];
    if (f == r) {
        f = r = -1;
    } else if (f == n - 1) {
        f = 0;
    } else {
        f++;
    }
    return a;
}

int main() {
    int choice;
    char element;

    while (1) {
        printf("\n1-Enqueue\n2-Dequeue\n3-Exit\nEnter your choice: ");
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
                printf("Exiting program\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }

        printf("Queue: ");
        for (int i=f;i!=-1&&i!=r;i =(i + 1)%n) {
            printf("%c ", queue[i]);
        }
        if (f != -1)
            printf("%c ", queue[r]);

        printf("\n");
    }

    return 0;
}
