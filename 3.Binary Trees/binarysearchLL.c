#include<stdlib.h>
#include<stdio.h>

struct node{
    int data;
    struct node *lc,*rc;
}*root;

void inorder(struct node* root) {
    if (root == NULL) return;
    inorder(root->lc);
    printf("%d ", root->data);
    inorder(root->rc);
}

struct node* getnode(int data){
    struct node *p=(struct node*)malloc(sizeof(struct node));
    p->data=data;
    p->lc=NULL;
    p->rc=NULL;
    return p;
}

void search(int b,struct node* root,int data,struct node* parent){
     if(root==NULL){
        printf("not found");
        return;
    }
    if(root->data==data){
        if(parent!=NULL){
            printf("parent of %d is %d\n",data,parent->data);
            if(b==1)
                printf("%d is the right child of %d\n",data,parent->data);
            else
                printf("%d is the left child of %d\n",data,parent->data);
        }
        else{
            printf("%d is the root node\n",data);
        }
    }
    else if(root->data<data)
        search(1,root->rc,data,root);
    else {
        search(0,root->lc,data,root);
    }
}



void del(struct node **root,int data){
    if(*root==NULL){
        printf("not found\n");
        return;
    }
    else if((*root)->data<data){
        del(&(*root)->rc,data);
    }
    else if((*root)->data>data){
        del(&(*root)->lc,data);
    }
    else{
        if((*root)->rc==NULL){
            *root=(*root)->lc;
        }else if((*root)->lc==NULL){
            *root=(*root)->rc;
        }
        else{
            // struct node *c=(*root)->lc;//inorder Predecessor
            // while(c->rc!=NULL){
            //     c=c->rc;
            // }
            // (*root)->data=c->data;
            // del(&(*root)->lc,c->data);
            struct node* c=(*root)->rc;//inorder  in-order successor 
            while(c->lc!=NULL){
                c=c->lc;
            }
            (*root)->data=c->data;
            del(&(*root)->rc,c->data);
        }
    }


}

void insert(int data,struct node **root){
    struct node *newnode=getnode(data);
    struct node *parent=NULL;
    int side;
    if(*root==NULL){
        *root=newnode;
    }
    else{
        struct node *current=*root;
        while (current!=NULL) {
            parent=current;
            if(current->data<data){
                side=0;
                current=current->rc;
            }
            else{
                side=1;
                current=current->lc;
            }
        }
        if(side==0){
            parent->rc=newnode;
        }
        else{
            parent->lc=newnode;
        }
        
    }

    }
int main(){
    int a,data,b;
    printf("enter the no of nodes:");
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        printf("enter the data:");
        scanf("%d",&data);
        insert(data,&root);
    }
    inorder(root);
    printf("\nenter the search node:\n");
    scanf("%d",&b);
    search(5,root,b,NULL);
    int c;
    printf("enter the element to del:");
    scanf("%d",&c);
    del(&root,c);
    inorder(root);

}




// #include <stdio.h>
// #include <stdlib.h>

// struct node {
//     int data;
//     struct node *left;
//     struct node *right;
// };

// struct node *createNode(int data) {
//     struct node *newNode =(struct node*)malloc(sizeof(struct node));
//     newNode->data = data;
//     newNode->left = NULL;
//     newNode->right = NULL;
//     return newNode;
// }

// struct node *insert(struct node *root, int data) {
//     if (root == NULL) {
//         root = createNode(data);
//     } else if (data <= root->data) {
//         root->left = insert(root->left, data);
//     } else {
//         root->right = insert(root->right, data);
//     }
//     return root;
// }

// // void deletenode(struct node *root, int data) {
// //     if (root == NULL) {
// //         printf("Not found\n");
// //     } else if (data < root->data) {
// //         deletenode(root->left, data);
// //     } else if (data > root->data) {
// //         deletenode(root->right, data);
// //     } else {
// //         if (root->left == NULL && root->right == NULL) {
// //             free(root);
// //             root = NULL;
// //         } else if (root->left == NULL) {
// //             struct node *temp = root;
// //             root = root->right;
// //             free(temp);
// //         } else if (root->right == NULL) {
// //             struct node *temp = root;
// //             root = root->left;
// //             free(temp);
// //         } else {
// //             struct node *temp = root->right;
// //             while (temp->left != NULL) {
// //                 temp = temp->left;
// //             }
// //             root->data = temp->data;
// //             deletenode(root->right, temp->data);
// //         }
// //     }
// // }

// void inorder(struct node *root) {
//     if (root != NULL) {
//         inorder(root->left);
//         printf("%d ", root->data);
//         inorder(root->right);
//     }
// }

// void preorder(struct node *root) {
//     if (root != NULL) {
//         printf("%d ", root->data);
//         preorder(root->left);
//         preorder(root->right);
//     }
// }

// // void search(struct node *root, int data) {
// //     if (root == NULL) {
// //         printf("Not found\n");
// //     } else if (root->data == data) {
// //         printf("Found\n");
// //     } else if (data <= root->data) {
// //         search(root->left, data);
// //     } else {
// //         search(root->right, data);
// //     }
// // }

// // a search function that return the node and its parent and also postion of the node

// struct node *search(struct node *root, int data, struct node **parent, int *position) {
//     if (root == NULL) {
//         return NULL;
//     } else if (root->data == data) {
//         return root;
//     } else if (data <= root->data) {
//         *parent = root;
//         *position = 0;
//         return search(root->left, data, parent, position);
//     } else {
//         *parent = root;
//         *position = 1;
//         return search(root->right, data, parent, position);
//     }
// }

// void printtree(struct node *root) {
//     if (root != NULL) {
//         printf("%d ", root->data);
//         printtree(root->left);
//         printtree(root->right);
//     }
// }

// int main() {
//     struct node *root = NULL;
//     int choice, data;
//     while (1) {
//         printf("1. Insert\n");
//         printf("2. Search\n");
//         printf("3. Inorder Traversal\n");
//         printf("4. Preorder Traversal\n");
//        //printf("4. Delete\n");
//         printf("5. Print tree\n");
//         printf("6. Exit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);
//         switch (choice) {
//             case 1:
//                 printf("Enter the value to be inserted: ");
//                 scanf("%d", &data);
//                 root = insert(root, data);
//                 break;
//             case 2:
//                 printf("Enter the value to be searched: ");
//                 scanf("%d", &data);
//                 struct node *parent = NULL;
//                 int position;
//                 struct node *temp = search(root, data, &parent, &position);
//                 if (temp == NULL) {
//                     printf("Not found\n");
//                 } else {
//                     printf("Found\n");
//                     printf("Parent: %d\n", parent->data);
//                     printf("Position: %d\n", position);
//                 }
//                 break;
//             case 3:
//                 inorder(root);
//                 printf("\n");
//                 break;
//             case 4:
//                 preorder(root);
//                 printf("\n");
//                 break;
//             // case 4:
//             //     printf("Enter the value to be deleted: ");
//             //     scanf("%d", &data);
//             //     deletenode(root, data);
//             //     break;
//             case 5:
//                 printtree(root);
//                 printf("\n");
//                 break;
//             case 6:
//                 exit(0);
//             default:
//                 printf("Invalid choice\n"); 
//                 break;
//         }
//     }
//     return 0;
// }