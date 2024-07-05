#include<stdio.h>
#include <stdlib.h>
#include<time.h>
int main(){
    
    int n[100000],y,a;
    printf("enter the required element:");
    scanf("%d",&a);
    
    FILE *f;
    f=fopen("descending.txt","r");
    for(int i=0;i<=100000;i++){
        fscanf(f,"%d",&n[i]);
    }
    
    clock_t start=clock();
    for(int i=0;i<=100000;i++){
        
            if(a==n[i]){
            y=i;
            break;
            }
           
        }
    clock_t end= clock();
    double execution_time = (double)(end - start) / CLOCKS_PER_SEC;

    fclose(f);
    printf("the position of the number is:%d\n",y);
    printf("execution time:%f seconds",execution_time);

    
}


