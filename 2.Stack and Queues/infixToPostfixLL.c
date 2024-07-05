#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define n 100

struct node{
    char data;
    struct node* next;
};

struct node *top=NULL;

char infix[n],postfix[n];

void print(){
    printf("postfix:");
    printf("%s\n",postfix);
}

void push(int a){
   struct node *newnode=(struct node*)malloc(sizeof(struct node));
   newnode->data=a;
   newnode->next=top;
   top=newnode;
}

char pop(){
     if (top == NULL) {
        printf("underflow");
        return '\0';
    }
    char a = top->data;
    struct node* temp = top;
    top = top->next;
    free(temp);
    return a;  
}

int empty(){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int precedence(char c){
    if(c=='^') return 3;
    else if(c=='*'||c=='/') return 2;
    else if(c=='+'||c=='-') return 1;
    else return 0;
}

void topostfix(){
    int j=0;
    for(int i=0;i<strlen(infix);i++){
        char symbol=infix[i],next;
        switch (symbol){
            case '(':
                push(symbol);
                break;
            
            case ')':
                while((next=pop())!='('){
                    postfix[j++]=next;
                }
                
                break;
            
            case '+':
            case '*':
            case '-':
            case '/':
            case '^':
                while(!empty() && precedence(top->data)>=precedence(symbol)){
                    postfix[j++]=pop();
                }
                push(symbol);
                break;
            default:
                postfix[j++]=symbol;

        }
       
    }
    while(!empty()){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
}

int posteval(){
    struct node *optop=NULL;
    for(int i=0;i<strlen(postfix);i++){
        char current=postfix[i];
        if(postfix[i]>='0' && postfix[i]<='9'){
            struct node *newnode=(struct node*)malloc(sizeof(struct node));
            newnode->data=current-'0';
            newnode->next=optop;
            optop=newnode;
        }
        else{
            int a=optop->data;
            int b=optop->next->data;
            switch (current)
            {
            case '+':
                a=b+a;
                break;
            case '-':
                a=b-a;
                break;
            case '*':
               a=b*a;
                break;
            case '/':
                a=b/a;
                break;
            case '^':
                a=(int)pow(b,a);
                break;
            default:
                break;
            }
            struct node *newnode=(struct node*)malloc(sizeof(struct node));
            newnode->data=a;
            newnode->next=optop;
            optop=newnode;

        }
        
    }
    return optop->data;
}

int main(){
    printf("enter the infix:");
    gets(infix);
    topostfix();
    print();
    int result=posteval();
    printf("answer:%d",result);
}
