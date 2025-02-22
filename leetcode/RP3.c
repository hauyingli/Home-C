#include<stdio.h>

// 旋转数组
/*
给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
示例 1:
输入: [1,2,3,4,5,6,7] 和 k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右旋转 1 步: [7,1,2,3,4,5,6]
向右旋转 2 步: [6,7,1,2,3,4,5]
向右旋转 3 步: [5,6,7,1,2,3,4]
示例 2:
输入: [-1,-100,3,99] 和 k = 2
输出: [3,99,-1,-100]
解释: 
向右旋转 1 步: [99,-1,-100,3]
向右旋转 2 步: [3,99,-1,-100]
说明:
尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
要求使用空间复杂度为 O(1) 的 原地 算法。
*/


void reverse(int*, int, int);
void rotate(int*, int, int);
int main(){
    int nums[7] = {1,2,3,4,5,6,7};
    int numsSize = 7;
    int k = 3;
    rotate(nums,numsSize,k);
    return 0;
}

void rotate(int* nums, int numsSize, int k){
    // 用轉的 
    // 第一圈 把全部轉過來
    // nums = 1 2 3 4 5 6 7 .reverse
    //        0 1 2 3 4 5 6 
    reverse(nums, 0, numsSize-1);
    // nums = 7 6 5 4 3 2 1
    printf("R1: ");
    for (int i = 0; i < numsSize; i++){

        printf("%d ", nums[i]);
    }
    printf("\n");
    printf("R2: ");
    // 第二圈 轉第0號到第k號   k = 3
    // nums = 5 6 7 4 3 2 1
    reverse(nums, 0, k-1);
    // 第三圈 轉 Size - k 的位置// size 要記得-1因為array 從0開始數
    // nums = 5 6 7 1 2 3 4 // 最後答案
    for (int i = 0; i < numsSize; i++){
        printf("%d ", nums[i]);
    }
    printf("\n");
    printf("R3: ");
    reverse(nums,k,numsSize-1);
    for (int i = 0; i < numsSize; i++){
        printf("%d ", nums[i]);
    }
}
void reverse(int* nums, int start, int end){
    while (start < end){
        int t = nums[start];
        nums[start] = nums[end];
        nums[end] = t ;
        start++;
        end--;
    }

}






// other way

    // for (int i = 0; i < numsSize; i++){
    //     if(k >= 0){
    //         printf("1.not negative %d \n", k);

    //     }
    // }
    // printf("2.negative %d \n", k);