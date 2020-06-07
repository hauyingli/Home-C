#include<stdio.h>
/*                                            數組 練習
1. 删除排序数组中的重复项

示例 1:
给定数组 nums = [1,1,2], 
函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。 
你不需要考虑数组中超出新长度后面的元素。
示例 2:
给定 nums = [0,0,1,1,1,2,2,3,3,4],
函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。
你不需要考虑数组中超出新长度后面的元素。
*/

// 靠自己學習中 第n次 2020/06/07 Done;

int singleNumber(int* nums,int numsSize){
    int n = nums[0];
    int temp = 1;
    for (int i = 1; i < numsSize; i++){
        if(n != nums[i]){
            nums[temp] = nums[i];
            n = nums[i];
            temp++;
        }
    }
    for (int j = 0; j < temp; j++){
        printf("%d ",nums[j]);
    }
    printf("\n");
    return temp;
}

int main(){
    int nums[10] = {0,0,1,1,1,2,2,3,3,4};
    int numsSize = 10;
    // singleNumber(nums,numsSize);
    printf("%d \n",singleNumber(nums,numsSize));
    return 0;
}