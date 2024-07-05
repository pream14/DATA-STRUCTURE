#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node *lc, *rc;
};

void inorder(struct node *root) {
    if (root == NULL) return;
    inorder(root->lc);
    printf("%d ", root->data);
    inorder(root->rc);
}

int lc(struct node* root, int p, int q,int *a,int *b,int i,int j){
     if(root==NULL||root->data==p||root->data==q)return root->data;
    a[i++]=lc(root->lc,p,q,a,b,i,j);
    b[j++]=lc(root->rc,p,q,a,b,i,j);
    int k,f=0;
    for(k=0;k<i||k<j;k++){
        if(a[k]!=b[k]){
            f=1;
            return a[k-1];
        }
        else{
            continue;
        }    
    }
    if(f==0){
        return -1;
    }
}

struct node *getnode(int data) {
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = data;
    p->lc = NULL;
    p->rc = NULL;
    return p;
}

void insert(struct node **root, int data) {
    if (*root == NULL) {
        *root = getnode(data);
    } else if (data <= (*root)->data) {
        insert(&(*root)->lc, data);
    } else {
        insert(&(*root)->rc, data);
    }
}

int main() {
    int a, data,c,d,i=0,j=0;
    struct node *root = NULL;
    printf("enter the no of nodes:");
    scanf("%d", &a);
    for (int i = 0; i < a; i++) {
        printf("enter the data:");
        scanf("%d", &data);
        insert(&root, data);
    }
    inorder(root);
    printf("\nenter the 1st node value for LCA:");
    scanf("%d",&c);
    
    printf("\nenter the 2nd node value for LCA:");
    scanf("%d", &d);
    int *arr = (int *)malloc(a * sizeof(int));
    int *arr1 = (int *)malloc(a * sizeof(int));
    int l=lc(root,c,d,arr,arr1,0,0);
    printf("\n");
   if(l!=-1)
    printf("the lowest common ancestor:%d",l);

}

