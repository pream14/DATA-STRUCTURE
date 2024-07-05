// #include<stdio.h>
// #include<stdlib.h>
// int findPeakElement(int* nums, int numsSize)
// {
//     if(numsSize==1)
//     {
//         return 0;
//     }
//     if(nums[0]>nums[1])
//     {
//         return 0;
//     }
//     if(nums[numsSize-1]>nums[numsSize-2])
//     {
//         return numsSize-1;
//     }
//     for(int i=1;i<numsSize-1;i++)
//     {
//         if(nums[i-1]<nums[i]&&nums[i]>nums[i+1])
//         {
//             return i;
//         }}
// return 0;
// }

// int main(){
//     int a[]={1,2,3,6,5,3};
//     int c=findPeakElement(a,6);
//     printf("%d",a[c]);
//     }


#include<stdio.h>
#include<stdlib.h>

int findPeakRecursive(int* nums, int low, int high, int numsSize) {
    int mid = low + (high - low) / 2;

    if ((mid == 0 || nums[mid - 1] <= nums[mid]) &&
        (mid == numsSize - 1 || nums[mid + 1] <= nums[mid])) {
        return mid;
    }

    if (mid > 0 && nums[mid - 1] > nums[mid]) {
        return findPeakRecursive(nums, low, mid - 1, numsSize);
    } else {
        return findPeakRecursive(nums, mid + 1, high, numsSize);
    }
}

int findPeakElement(int* nums, int numsSize) {
    return findPeakRecursive(nums, 0, numsSize - 1, numsSize);
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 3};
    int c = findPeakElement(a, 6);
    printf("Peak element: %d\n", a[c]);

    return 0;
}
