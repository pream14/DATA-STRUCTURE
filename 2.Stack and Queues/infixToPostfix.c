#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define n 100
int opstack[n];
int optop=-1;

char stack[n];
int top=-1;

char infix[n],postfix[n];

void print(){
    printf("postfix:");
    printf("%s\n",postfix);
}

void push(char a){
    if(top==n-1){
        printf("overflow");
    }
    else{
        top++;
        stack[top]=a;
    }
}

char pop(){
    char a;
    if(top==-1){
        printf("underflow");
    }
    else{
        a=stack[top];
        top--;
        return a;
    }
}

int empty(){
    if(top==-1){
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
                while(!empty() && precedence(stack[top])>=precedence(symbol)){
                    postfix[j++]=pop();
                }
                push(symbol);
                break;
            default:
                postfix[j++]=symbol;
                break;

        }
       
    }
    while(!empty()){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
}

int posteval(){
   
    for(int i=0;i<strlen(postfix);i++){
        int current=postfix[i];
        if(postfix[i]>='0' && postfix[i]<='9'){
            opstack[++optop]=postfix[i]-'0';
        }
        else{
            int a=opstack[optop--];
            int b=opstack[optop--];
            switch (current)
            {
            case '+':
                opstack[++optop]=b+a;
                break;
            case '-':
                opstack[++optop]=b-a;
                break;
            case '*':
                opstack[++optop]=b*a;
                break;
            case '/':
                opstack[++optop]=b/a;
                break;
            case '^':
                opstack[++optop]=pow(b,a);
                break;
            default:
                break;
            }

        }
        
    }
    return opstack[optop];
}

int main(){
    printf("enter the infix:");
    gets(infix);
    topostfix();
    print();
    int result=posteval();
    printf("answer:%d",result);
}
