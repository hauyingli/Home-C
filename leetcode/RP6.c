#include <stdio.h>
#include <stdlib.h>







int* intersect(int* , int, int*, int, int*);

int main(){
    int nums1[4] = {1,2,2,1};
    int nums1Size = 4;
    int nums2[2] = {2,2};
    int nums2Size = 2;
    int returnSize[2];

    intersect(nums1,nums1Size,nums2,nums2Size,returnSize);
    return 0;
}


int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int big, small;
    int temp = 0;
    if(nums1Size > nums2Size){
        big = nums1Size;
        small = nums2Size;
    }
    else{
        big = nums2Size;
        small = nums1Size;
    }
    int *ans = (int *)malloc(sizeof(int) * big);
    for(int i = 0; i < big; i++){
        for (int j = 0; j < small; j++){
            if(nums1[i] = nums2[j]){
                ans[temp] = nums2[j];
                temp++;
            }
        }
        
    }
    for (int i = 0; i < small; i++){
        printf("%d ", ans[i]);        
    }
    free(ans);
    return ans;
}

