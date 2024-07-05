#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node* getnode(int data) {
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = data;
    p->next = NULL;
    return p;
}
void insertbeg(struct node **head,int data){
    struct node *newnode=getnode(data);
    newnode->next=*head;
    *head=newnode;
}
int main(){
    struct node *head=NULL;
    int n,data;
    printf("enter the number of element:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter the %d element:",i+1);
        scanf("%d",&data);
        insertbeg(&head,data);
    }
    struct node* current=head;
    while(current!=NULL){
        printf("%d->",current->data);
        current=current->next;
    }
    printf("NULL");

}