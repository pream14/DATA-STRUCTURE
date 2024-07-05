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
void insertend(struct node **head,int data){
    struct node *newnode=getnode(data);
    if(*head==NULL){
        *head=newnode;

    }
    else{
        struct node *current=*head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next=newnode;

    }
}
void print(struct node **head){
        struct node* current=*head;
    while(current!=NULL){
        printf("%d->",current->data);
        current=current->next;
    }
    printf("NULL\n");
}
void evenodd(struct node **head){
    if((*head)==NULL){
        printf("the node is empty");
    }
    if((*head)->next==NULL){
        printf("node has only one element");
    }

    struct node *current=*head;
    struct node *even=NULL;
    struct node *odd=NULL;
    
    while(current!=NULL){
        if(current->data%2==0){
            insertend(&even,current->data);
        }
        else{
            insertend(&odd,current->data);
        }
        current=current->next;
    }
     struct node *current1=even;
        while (current1->next != NULL) {
            current1 = current1->next;
        }
        current1->next=odd;
        printf("output:\n");
        print(&even);
    

    }


 




int main(){
    struct node *head=NULL;
    int n,data;
    printf("enter the numer of elements:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter the %d element:",i+1);
        scanf("%d",&data);
        insertend(&head,data);
    }
    print(&head);
    evenodd(&head);
     struct node *current = head;
    while (current != NULL) {
        struct node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}