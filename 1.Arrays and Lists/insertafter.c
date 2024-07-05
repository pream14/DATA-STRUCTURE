#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    
};

struct node *getnode(int data){
    struct node *p=(struct node *)malloc(sizeof(struct node));
    p->data=data;
    p->next=NULL;
    return p;
}
void insertafter(struct node **head,int a,int x){
    struct node *current=*head;
    struct node *newnode=getnode(x);
    
    if(*head==NULL){
        printf("node is empty");
        return;
    }
   
    
        while(current!=NULL){
           if (current->data == a) {
            newnode->next = current->next;
            current->next = newnode;
            return;
            }

            current=current->next;

        }
         printf("%d not found in the list\n", a);
    }

void insertend(struct node **head,int data){
    struct node* newnode=getnode(data);
    if(*head==NULL){
        *head=newnode;
        return;
    }
    else{
        struct node *current=*head;
        while(current->next!=NULL){
            current=current->next;
        }
        current->next=newnode;
    }
    
}
int main(){
    struct node *head=NULL;
    int n,data,a,x;
    printf("enter the number of element:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter the %d element:",i+1);
        scanf("%d",&data);
        insertend(&head,data);
    }
        struct node *current=head;
        while(current!=NULL){
            printf("%d->",current->data);
            current=current->next;
        }
        printf("NULL\n");
        printf("enter the element where you want to insert :");
        scanf("%d",&a);
        printf("enter the number you want to insert:");
        scanf("%d",&x);
        insertafter(&head,a,x);
        struct node *current1=head;
        while(current1!=NULL){
            printf("%d->",current1->data);
            current1=current1->next;
        }

    
}