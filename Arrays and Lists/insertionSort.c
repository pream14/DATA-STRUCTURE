#include<stdio.h>
#include <stdlib.h>
#include<time.h>
int main(){
    int temp=0;
  FILE *f;
  f=fopen("nearly sorted.txt","r");
  int a[100000];
   for(int i=0;i<=1000;i++){
        fscanf(f,"%d ",&a[i]);
    }
    clock_t start=clock();
    for(int i=1;i<1000;i++){
        temp=a[i];
        int j;
        for( j=i-1;j>=0;j--){
            if(temp<a[j]){
                
               a[j+1]=a[j];
               
            }
            
            
        }
        a[j+1]=temp;
    }
      clock_t end= clock();
    double execution_time = (double)(end - start) / CLOCKS_PER_SEC;
    FILE *fp;
    fp=fopen("new.txt","w");
    for(int i=0;i<100000;i++){
    fprintf(fp,"%d ",a[i]);}
    fclose(f);
    fclose(fp);
    printf("execution time:%f seconds",execution_time);

}


