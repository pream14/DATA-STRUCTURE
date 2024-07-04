#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubble(int *a, int n) {
    for (int i = 0; i <n-1; i++) {
        int t=0;
        for (int j = 0; j < n-1-i  ; j++) {
            if (*(a + j) > *(a + (j + 1))) {
                swap((a + j), (a + (j + 1)));
                t=1;
            }
        }
        if(t==0){
            break;
        }
    }
}



int main() {
    FILE *f,*fp;
    int a[100000];
    f=fopen("nearly sorted.txt","r");
    for(int i=0;i<=100000;i++){
        fscanf(f,"%d ",&a[i]);
    }
    fp=fopen("s.txt","w");
    clock_t start=clock();
    bubble(a, 100000);
    clock_t end= clock();
    double execution_time = (double)(end - start) / CLOCKS_PER_SEC;
    for(int i=0;i<=100000;i++){
        fprintf(fp,"%d ",a[i]);
    }
    printf("execution time:%f seconds",execution_time);   
}

