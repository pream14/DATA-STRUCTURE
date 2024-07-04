// #include<stdio.h>
// int main(){
//     int a;
//     printf("enter the number of element in array:\n");
//     scanf("%d",&a);
//     int b[a];
//     printf("enter the element in array:\n");
//     for(int i=0;i<a;i++){
//         scanf("%d",&b[i]);
//     }
//     int c,mid;
//     printf("enter the target:");
//     scanf("%d",&c);
//     int left=0,right=a-1,flag=0;
//     while(left<=right){
//         mid=(left+right)/2;
//         if(b[mid]==c){
            
//             flag=1;
//             break;
//         }
//         if(b[mid]>c){
//             right=mid-1;
//         }
//         else{
//             left=mid+1;
//         }
//     }
//     if(flag==1){
//         printf("the position is:%d",mid);
//     }
//     else{
//         printf("element not found");
//     }
// }


#include<stdio.h>

int binarySearch(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] > target) {
            return binarySearch(arr, left, mid - 1, target);
        }

        return binarySearch(arr, mid + 1, right, target);
    }

    return -1; // Not found
}

int main() {
    int a;
    printf("Enter the number of elements in the array:\n");
    scanf("%d", &a);

    int b[a];
    printf("Enter the elements in the array:\n");
    for (int i = 0; i < a; i++) {
        scanf("%d", &b[i]);
    }

    int c;
    printf("Enter the target:");
    scanf("%d", &c);

    int result = binarySearch(b, 0, a - 1, c);

    if (result != -1) {
        printf("The position is: %d", result);
    } else {
        printf("Element not found");
    }

    return 0;
}
