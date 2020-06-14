#include <stdio.h>//有printf and scanf函式
#include <math.h> //數學函式
#include <stdlib.h> //有srand 函式 隨機亂數
#include <time.h> //在srand 中使用讓亂數不固定
#include <string.h> //char 字串使用的函式
#include <stdbool.h>//布林值定義

char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    printf("test");
    return NULL;
}
int main(void){
    char* strs[6] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    int strsSize = 6;
    int* returnSize =  0;
    int* returnColumnSizes[3] = {0,0,0};

    groupAnagrams(strs,strsSize,returnSize,returnColumnSizes);
    return 0;
}