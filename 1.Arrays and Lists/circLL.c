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
void insertafter(struct node **head,int a,int x){
    struct node *current=*head;
    struct node *newnode=getnode(x);
    
    if(*head==NULL){
        printf("node is empty");
        return;
    }
   
    
       do{
           if (current->data == a) {
            newnode->next = current->next;
            current->next = newnode;
            return;
            }
             current=current->next;
            } while(current!=(*head));

           

        
         printf("%d not found in the list\n", a);
    }


void insertend(struct node **head,int data){
    struct node *newnode=getnode(data);
     struct node *current=*head;
    if(*head==NULL){
        *head=newnode;

    }
   
    else{
        
        while (current->next != NULL) {
            current = current->next;
        }
        current->next=newnode;
    }
    
   
}
void insertcirc(struct node **head){
    struct node* current1=*head;
    while(current1->next!=NULL){
        
        current1=current1->next;
    }
    current1->next=*head;
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
    insertcirc(&head);
  
    
    struct node* current=head;
    do{
        
        printf("%d->",current->data);
        printf("%d\n",current->next);
        current=current->next;
    }while(current!=head);
     printf("enter the element where you want to insert :");
        scanf("%d",&a);
        printf("enter the number you want to insert:");
        scanf("%d",&x);
        insertafter(&head,a,x);
        // insertcirc(&head);

     struct node* current2=head;
    do{
        
        printf("%d->",current2->data);
        printf("%d\n",current2->next);
        current2=current2->next;
    }while(current2!=head);
    
   
     current = head;
     do{
         struct node* temp = current;
        
        current=current->next;
        free(temp);
    }while(current!=head);
    

    return 0;
}