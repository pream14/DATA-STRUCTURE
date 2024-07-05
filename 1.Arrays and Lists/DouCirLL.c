#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next,*prev;
};
struct node* getnode(int data) {
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = data;
    p->next = NULL;
    p->prev=NULL;
    return p;
}
void insertafter(struct node **head, int a, int x) {
    struct node *current = *head;
    struct node *newnode = getnode(x);

    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

      do {
        if(current->data == a) {
            newnode->next = current->next;
            newnode->prev = current;
            current->next = newnode;
        
        if (newnode->next != NULL) {
            newnode->next->prev = newnode; // Check if newnode->next is not NULL
        }
    }
    current = current->next;
    }while(current!=(*head));

    printf("%d not found in the list\n", a);
}

void insertloop(struct node **head){
    struct node *current=*head;
    while(current->next!=NULL){
        current=current->next;
    }
    (*head)->prev=current;
    current->next=*head;
}
void insertend(struct node **head,int data){
    struct node *newnode=getnode(data);
    if(*head==NULL){
        newnode->prev=NULL;
        *head=newnode;
    }
    else{
        struct node *current=*head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next=newnode;
        newnode->prev=current;

    }
}
int main(){
    struct node *head=NULL;
    int n,data,a,x;
    printf("enter the number of elements:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter the %d element:",i+1);
        scanf("%d",&data);
        insertend(&head,data);
    }
    insertloop(&head);
    struct node* current=head;
    do{
        printf("%d->",current->prev);
        printf("%d->",current->data);
        printf("%d\n",current->next);
        
        current=current->next;
    }while(current!=head);
    printf("enter where you want to insert:");
    scanf("%d",&a);
    printf("enter the element you want to insert:");
    scanf("%d",&x);
    insertafter(&head,a,x);
    struct node* current1=head;
    do{
        printf("%d->",current1->prev);
        printf("%d->",current1->data);
        printf("%d\n",current1->next);
        
        current1=current1->next;
    }while(current1!=head);
    
     current = head;
    do {
        struct node* temp = current;
        current = current->next;
        free(temp);
    }while(current!=head);

    return 0;
}