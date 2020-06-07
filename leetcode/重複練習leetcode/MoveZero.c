#include <stdio.h>//有printf and scanf函式
#include <math.h> //數學函式
#include <stdlib.h> //有srand 函式 隨機亂數
#include <time.h> //在srand 中使用讓亂數不固定
#include <string.h> //char 字串使用的函式
#include <stdbool.h>//布林值定義



/*  283. Move Zeroes
Given an array nums, write a function to move all 0's
to the end of it while maintaining the relative order of the non-zero elements.
Example:
Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:
You must do this in-place(直接修改當下的nums) without making a copy of the array.
Minimize the total number of operations.
*/
//自己完成 跟老師最終結果一樣
void moveZeroes(int* nums, int numsSize){
    int temp = 0;
    for (int i = 0; i < numsSize; i++){
        if(nums[i] != 0){
            nums[temp] = nums[i];
            temp++;
        }
    }
    for(int k = numsSize-1;k >= temp; k--){
        nums[k] = 0;
    }
    for (int j = 0; j < numsSize; j++){
        printf("%d ",nums[j]);
    }
    printf("\n");
}

//使用老師的方法1. 用最基礎的
// void moveZeroes(int* nums,int numsSize){
//     // 本版一本 會runtime 太久
//     // while (true){
//     //     int count = 0; //計次
//     //     //第一步先想如何檢查是否是對的答案
//     //     for (int i = 0; i < numsSize; i++){
//     //         if (nums[i] == 0 && nums[i++] != 0){//代表有錯誤 開始修正
//     //             int v = nums[i];
//     //             nums[i] = nums[i+1];
//     //             nums[i+1] = v;
//     //             count++; //代表有錯誤 
//     //             break;//結束迴圈 結束最近的迴圈
//     //         }
//     //     }
//     //     if (count == 0){
//     //         break;//結束的迴圈 while
//     //     }
//     // }
//     // 第二版本
//     while (true){
//         // int count = 0; //第一種計次確定在if中到底有沒有成立
//         bool isokay = true; //第二種方法
//         //第一步先想如何檢查是否是對的答案
//         for (int i = 0; i < numsSize; i++){
//             if (nums[i] == 0 && nums[i++] != 0){//代表有錯誤 開始修正
//                 int v = nums[i];
//                 nums[i] = nums[i+1];
//                 nums[i+1] = v;
//                 //count++; //1.代表有錯誤 
//                 isokay = false; //代表有錯誤
//                 //break;//結束迴圈 結束最近的迴圈 
//                 // 取消 break 因為只要找到一個問題就 結束又從頭開始看,所以會跑很久
//             }
//         }
//         if (isokay){// 如果isokay 是ture 就break
//             break;//結束的迴圈 while
//         }
//     }
//     return;
// }
int main(){
    int nums[5] = {0,1,0,3,12};
    int numsSize = 5;
    moveZeroes(nums,numsSize);
    return 0;
}