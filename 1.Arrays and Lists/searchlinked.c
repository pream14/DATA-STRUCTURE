#include<stdio.h>
#include<stdlib.h>
int search(struct node *head,int tar);
struct node *getnode(int data);
struct node{
    int data;
    struct node *next;
};

int main(){
    struct node *head=NULL;
    struct node *p1,*p2;
    int p3;
    p1=getnode(3);
    p2=getnode(9);
    head=p1;
    p1->next=p2;
    p3=search(head,9);
    printf("address %d",p3);

}
struct node* getnode(int data){
   struct node* p=(struct node*)malloc(sizeof(struct node));
   p->data=data;
   p->next=NULL;
   return p;
}
int search(struct node *head,int tar){
    int index=0;
    if(head==NULL){
        printf("head is NULL");
    }
    struct node *current=head;
    while(current!=NULL){
        if(current->data==tar){
            return index;
        }
        current=current->next;
        index++;
    }
   
}