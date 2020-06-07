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
int dele(int* ,int );
int main(){
    int num[10] = {0,0,1,1,1,2,2,3,3,4};
    int numsize = 10;

    printf("new lens : %d \n",dele(num, numsize));
    return 0;
}

int dele(int* num, int size){
    int x = 1;
    int v = num[0];
    for (int i = 1; i < size; i++){
        if(v != num[i]){
            num[x++] = num[i];
            v = num[i];
        }
    }
    for (int i = 0; i < size; i++){
        printf("%d \n", num[i]);
    }
    printf("%d \n", x);
    return x;

}