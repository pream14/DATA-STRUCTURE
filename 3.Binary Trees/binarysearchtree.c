#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void inorder(int *arr,int i)
{
    if((arr[2*i+1])!=0)
          inorder(arr,2*i+1);
    printf("%d  ",arr[i]);
    if((arr[2*i+2])!=0)
          inorder(arr,2*i+2);

}

int search(int *a,int data){
    int i=0;
    while(a[i]!=data&&a[i]!=0){
        if(a[i]<data)
        i=2*i+2;
        else
        i=2*i+1;
    }
    if(a[i]==data)
    return i;
    else{
        printf("element not found");
    return -1;}
}

void insert(int *a,int data,int i){
    if(a[i]==0){
        a[i]=data;
    }
    else if(a[i]<data){
        
        insert(a,data,2*i+2);
    }
    else{
        insert(a,data,2*i+1);
    }
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    int *a = (int *)calloc(pow(2, n+1) - 1, sizeof(int));
    
    
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        int j = 0;
        insert(a,data,0);
        // while (a[j] != 0) {
        //     if (data < a[j]) {
        //         j = 2 * j + 1;
        //     } else {
        //         j = 2 * j + 2;
        //     }
        // }
        
        // a[j] = data;
    }
    inorder(a, 0);
    printf("\n");
    int x;
    printf("search element:");
    scanf("%d",&x);
    int f=search(a,x);
    printf("search:%d\n",f);
    a[f]=-1;//for no child
    
    // inorder(a,0);
 
    return 0;
}

