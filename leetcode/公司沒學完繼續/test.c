#include <stdio.h>//有printf and scanf函式
#include <math.h> //數學函式
#include <stdlib.h> //有srand 函式 隨機亂數
#include <time.h> //在srand 中使用讓亂數不固定
#include <string.h> //char 字串使用的函式
#include <stdbool.h>//布林值定義


typedef struct {
    char *original; //原始字串
    char *sorted;    //排完續的字串
}Pair;

int cmpChar(const void* a, const void* b){  // qsort排序的函式
    return *(const char*)a - *(const char*)b;
}

int cmpPair (const void* a, const void* b){
    const Pair* pa = (const Pair*)a;
    const Pair* pb = (const Pair*)b;
    return strcmp(pa->sorted,pb->sorted);
}

char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    Pair* pairs = malloc(sizeof(Pair)*strsSize);

    for (int i = 0; i < strsSize; i++){
        char *sorted_str = malloc(sizeof(char)*(strlen(strs[i])+1));
        strcpy(sorted_str,strs[i]);
        qsort(sorted_str,strlen(strs[i]),sizeof(char),cmpChar);
        pairs[i].original = strs[i];
        pairs[i].sorted = sorted_str;        
    }

    qsort(pairs,strsSize,sizeof(Pair),cmpPair);
    
    char ***returnResult = NULL;//[]一開始要一個空的
    *returnSize = 0;
    *returnColumnSizes = NULL;
    for(int i = 0; i<strsSize; i++){

        if(i == 0 || strcmp(pairs[i].sorted , pairs[i-1].sorted) != 0)
        {
            //第一個字  case 1
            int lastGroupIndex = *returnSize;
            returnResult = realloc(returnResult, sizeof(char**)*(*returnSize+1));
            returnResult[lastGroupIndex] = malloc(sizeof(char*)*1);
            returnResult[lastGroupIndex][0] = pairs[i].original;
            
            (*returnSize)++;
            *returnColumnSizes = realloc(*returnColumnSizes,sizeof(int)*(*returnSize));
            (*returnColumnSizes)[lastGroupIndex] = 1;
        }
        else{
            //第三個字  case 2
            int lastGroupIndex = *returnSize -1;
            int lastGroupSize = (*returnColumnSizes)[lastGroupIndex];
            returnResult[lastGroupIndex] = realloc(returnResult[lastGroupIndex],sizeof(char*)*(lastGroupSize+1));
            returnResult[lastGroupIndex][lastGroupSize] = pairs[i].original;
            (*returnColumnSizes)[lastGroupIndex] = lastGroupSize+1;
        }
    }   
    return returnResult;
}

int main(void){
    char* strs[6] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    int strsSize = 6;
    int* returnSize =  0;
    int* returnColumnSizes[3] = {0,0,0};
    
    groupAnagrams(strs,strsSize,returnSize,returnColumnSizes);
    return 0;
}

