#include <stdio.h>//有printf and scanf函式
#include <math.h> //數學函式
#include <stdlib.h> //有srand 函式 隨機亂數
#include <time.h> //在srand 中使用讓亂數不固定
#include <string.h> //char 字串使用的函式
#include <stdbool.h>//布林值定義


//練習 删除排序数组中的重复项
int removeDuplicates(int*, int);
int main(){ 
    int nums[10] = {0,1,1,1,1,2,2,3,3,4};
    int nsize = 10;
    removeDuplicates(nums,nsize);
    return 0;
}

int removeDuplicates(int* nums, int numsSize){
    int lens = 0, k= 1, z = nums[0];
    if(numsSize == 0){
		return k = 0;    
	} //以上如果 size 為0直接回傳 0的長度
    for (int i = 1; i < numsSize; i++){
        if(z != nums[i]){               // if [ (z) nums[0]  != (nums[i]) nums[1] ]           拿 z = v[0] 和 v[i] = v[1] 比對
                                        //           nums[1++] == nums[1]  z = nums[1]        如果不一樣 v[1++] = v[1]; z = v[1]
            nums[k++] = nums[i];
            z = nums[i];
        }
    }
    return k;
}
