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
    struct node* current=head;
    while(current!=NULL){
        printf("%d->",current->data);
        current=current->next;
    }
    printf("NULL");
     current = head;
    while (current != NULL) {
        struct node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}