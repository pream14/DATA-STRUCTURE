
// #include <stdio.h>

// int* rotate(int (*m)[20],int a,int b);

// int main()
// {
//     int m[20][20],a,b;
//     printf("enter the numer of rows:\n");
//     scanf("%d",&a);
//     printf("enter the number of  coloumns:");
//     scanf("%d",&b);
//     for(int i=0;i<a;i++){
//         for(int j=0;j<b;j++){
//             scanf("%d",&m[i][j]);
//         }
//     }
//     for(int i=0;i<a;i++){
//         for(int j=0;j<b;j++){
//            printf("m[%d][%d]=%d\n",i,j,m[i][j]);
//         }
//     }
//     rotate(m,a,b);
// }
// int* rotate(int (*m)[20],int a,int b){
//     int trans[10][10];
    
//     for(int i=0;i<a;i++){
//         for(int j=0;j<b;j++){
//             trans[j][i]=m[i][j];
//         }
//     }
//      for(int i=0;i<b;i++){
//         for(int j=0;j<a;j++){
//             m[i][j]=trans[i][j];
            
//         }
//      }
//      for(int i=0;i<a;i++){
//          for(int j=0;j<b/2;j++){
//              int temp=m[i][j];
//              m[i][j]=m[i][b-j-1];
//              m[i][b-j-1]=temp;
//          }
//      }
//      printf("the rotated array:\n");
//       for(int i=0;i<a;i++){
//         for(int j=0;j<b;j++){
//             printf("m[%d][%d]=%d\n",i,j,m[i][j]);
//         }
//       }
    
// }


