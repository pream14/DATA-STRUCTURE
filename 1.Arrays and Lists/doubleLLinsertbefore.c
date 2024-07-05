#include<stdio.h>
#include<stdlib.h>
struct node *getnode(int data);
void insertbefore(struct node **head,int tar,int new);
void printList(struct node* head);
struct node{
    int data;
    struct node *next,*previous;
};
int main(){
    struct node *head=NULL;
    struct node *p1,*p2,*p3;
    p1=getnode(5);
    p2=getnode(10);
    p3=getnode(4);
    head=p1;
    p1->next=p2;
    p2->previous=p1;
    p2->next=p3;
    p3->previous=p2;
    
    insertbefore(&head,6,30);
    printList(head);


}
struct node *getnode(int data){
    struct node *p=(struct node *)malloc(sizeof(struct node));
    p->data=data;
    p->next=NULL;
    return p;
}
void insertbefore(struct node **head,int tar,int new){
    struct node *newnode=getnode(new);

    if((*head)==NULL){
        *head=newnode;
    }
    if((*head)->data==tar){
        newnode->next=*head;
        *head=newnode;

    }
    struct node *current=*head;
    while(current->next!=NULL){
        if(current->next->data==tar){
            newnode->next=current->next;
            current->next=newnode;
            return;
        }   
        current=current->next;

     }
     current->next=newnode;
} 
void printList(struct node* head){
    struct node *current = head;
    while (current != NULL) {
        printf("%d-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}