#include <stdio.h>//有printf and scanf函式
#include <math.h> //數學函式
#include <stdlib.h> //有srand 函式 隨機亂數
#include <time.h> //在srand 中使用讓亂數不固定
#include <string.h> //char 字串使用的函式
#include <stdbool.h>//布林值定義
// 49. 字母异位词分组   難度  中上

/*给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
示例:
输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
输出:[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
说明：
所有输入均为小写字母。
不考虑答案输出的顺序。
*/
// https://www.youtube.com/watch?v=1zU77mcQJ-U&list=PLY_qIufNHc29OLToHki4t0Z5KIhUzdYxD&index=6
// 停在 20：59  // run2 : 55:20

//中等題目  在C語言中很難寫（指標的運用)(型別:Char ）上面版本為解析版
// Group Anagrams
//介紹為啥這麼多＊號   
// int cmpChar(const void* a, const void* b){  // qsort排序的函式
//     // printf("%d \n", *(const char*)a - *(const char*)b);
//     return *(const char*)a - *(const char*)b;
// }

// //寫結構前 printf:
// /*
// eat : aet
// tea : aet
// tan : ant
// ate : aet
// nat : ant
// bat : abt
// */
// //寫一個結構
// //把qsort 後的字串再重新編排一次(把一樣的排在一起)

// typedef struct {
//     char *origninal; //原始字串
//     char *sorted;    //排完續的字串
// }Pair;
// int cmpPair (const void* a, const void* b){
//     const Pair* pa = (const Pair*)a;
//     const Pair* pb = (const Pair*)b;
//     return strcmp(pa->sorted,pb->sorted);
// }


// char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
//     //第一個參數 strs : ["eat", "tea", "tan", "ate", "nat", "bat"]
//     //為啥是字元＊＊呢？
//     //第一個＊代表strs是一個陣列(*),陣列中每個元素都是一個字串（char＊）  
//     // ================== 
//     //結構開始使用
//     Pair* pairs = malloc(sizeof(Pair)*strsSize);
//     //這邊產生陣列
//     //pairs : [{origninal: "eat" , sorted: "aet"},{origninal: "tea" , sorted: "aet"},....]共有6個

//     //      把文字排序用 ===> qsort 函式 
//     for (int i = 0; i < strsSize; i++){
//         char *sorted_str = malloc(sizeof(char)*strlen(strs[i])+1);
//         strcpy(sorted_str,strs[i]);
//         qsort(sorted_str,strlen(strs[i]),sizeof(char),cmpChar);
//         //儲存 pairs內的值:
//         pairs[i].origninal = strs[i];
//         pairs[i].sorted = sorted_str;        
//     }

//     //重新編排 Pairs
//     //qsort(重新編排的內容, 總共有多少個, 一個有多大,)
//     qsort(pairs,strsSize,sizeof(Pair),cmpPair);
//     for (int i = 0; i < strsSize; i++){ //列印出目前的pairs
//         printf("%s : %s\n",pairs[i].origninal,pairs[i].sorted);
//     }
   
//     // 開始---->細節 Done!
//     char *** returnResult = malloc(sizeof(char**)*3);
//     returnResult[0] = malloc(sizeof(char*)*3);
//     returnResult[1] = malloc(sizeof(char*)*2);
//     returnResult[2] = malloc(sizeof(char*)*1);
    
//     returnResult[0][0] = malloc(sizeof(char)*strlen("eat")+1);//多的+1要存 '/0'做結尾;
//     strcpy(returnResult[0][0], "ate");//把字元複製進去 使用 strcpy 函式複製
    
//     returnResult[0][1] = malloc(sizeof(char)*strlen("tea")+1);
//     strcpy(returnResult[0][1], "tea");//把字元複製進去 使用 strcpy 函式複製

//     returnResult[0][2] = malloc(sizeof(char)*strlen("ate")+1);
//     strcpy(returnResult[0][2], "ate");//把字元複製進去 使用 strcpy 函式複製

//     returnResult[1][0] = malloc(sizeof(char)*strlen("tan")+1);
//     strcpy(returnResult[1][0], "tan");//把字元複製進去 使用 strcpy 函式複製

//     returnResult[1][1] = malloc(sizeof(char)*strlen("nat")+1);
//     strcpy(returnResult[1][1], "nat");//把字元複製進去 使用 strcpy 函式複製

//     returnResult[2][0] = malloc(sizeof(char)*strlen("bat")+1);
//     strcpy(returnResult[2][0], "bat");//把字元複製進去 使用 strcpy 函式複製


//     *returnSize = 3;
//     *returnColumnSizes = malloc(sizeof(int)*3);
//     (*returnColumnSizes)[0] = 3;
//     (*returnColumnSizes)[1] = 2;
//     (*returnColumnSizes)[2] = 1;
//     return NULL;
//     //====回傳的值為字元***
//     // return:[
//     //  ["ate","eat","tea"],
//     //  ["nat","tan"],
//     //  ["bat"]
//     // ]


//     //以下有舉例
//     //回傳 returnSize = 3 因為會回傳 3 個  
//     // *returnSize = 3; //共有三個群組 {{x},{x},{x}}
//     // *returnColumnSizes = {3,2,1};//每個群組共要幾格 {{3},{2},{1}}
//     //解釋 Ex: 
//     // char *** returnResult = {{"ate","eat","tea"}, {"nat","tan"}, {"bat"}};
    
//     // returnResult[0] 回傳值 ==> char** ==> {"ate","eat","tea"}
//     // returnResult[0][0] 回傳值 ==> char* ==> {"ate"}
//     // returnResult[0][0][0] 回傳值 ==> char ==> 'a'

// }


// int main(void){
//     //基礎Char
//     // char basic[12] = "hello world";
//     // char *a = "Hello world";//直接把字串存在a的指標中
//     // const char *b = "Hello";//read only
//     // ============
//     char* strs[6] = {"eat", "tea", "tan", "ate", "nat", "bat"};
//     //陣列* 字串* 所以傳進去的是(char**)
//     // ============
//     int strsSize = 6;
//     //=====多大:6======
//     int* returnSize =  0;
//     int* returnColumnSizes[3] = {0,0,0};
    
//     groupAnagrams(strs,strsSize,returnSize,returnColumnSizes);
//     return 0;
// }


//舉例  1 使用函式 修改 INT

// void f(int* returnSize){//原本為 int retuenSize 不會改到原始值

//     //因為傳進來只是複製一份並不會改到原始值
//     // returnSize = 10;

//     //後來改成指標就可以修改了;
//     *returnSize = 10;
// }

// int main(void){
//     int returnSize = 0;
//     // f(returnSize); //改成傳入位置
//     f(&returnSize);
    
//     printf("%d \n", returnSize);
//     return 0;
// }

 
// 舉例二 函式修改 後 函式的生命週期
// int* f(){
//     // int returnResult[3] = {0,1,2};//使用<<<< 會有生命週期所以改用  malloc(動態配置)  函式
//     int* returnResult = malloc(sizeof(int)*3);
//     returnResult[0] = 10;
//     returnResult[1] = 20;
//     returnResult[2] = 30;
//     return returnResult;
// }
// int main(){
//     int* returnRESULT = f();
    
//     for (int i = 0; i < 3; i++){
//         printf("%d \n",returnRESULT[i]);
//     }

//     free(returnRESULT);// 產生出來的記憶體要歸還才不會占用記憶體
    
//     return 0;
// }




// 最後統整版本
// //寫結構前 printf:
// /*
// eat : aet
// tea : aet
// tan : ant
// ate : aet
// nat : ant
// bat : abt
// */
// //寫一個結構
// //把qsort 後的字串再重新編排一次(把一樣的排在一起)

// typedef struct {
//     char *origninal; //原始字串
//     char *sorted;    //排完續的字串
// }Pair;
// int cmpChar(const void* a, const void* b){  // qsort排序的函式
//     // printf("%d \n", *(const char*)a - *(const char*)b);
//     return *(const char*)a - *(const char*)b;
// }
// int cmpPair (const void* a, const void* b){
//     const Pair* pa = (const Pair*)a;
//     const Pair* pb = (const Pair*)b;
//     return strcmp(pa->sorted,pb->sorted);
// }


// char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
//     //第一個參數 strs : ["eat", "tea", "tan", "ate", "nat", "bat"]
//     //為啥是字元＊＊呢？
//     //第一個＊代表strs是一個陣列(*),陣列中每個元素都是一個字串（char＊）  
//     // ================== 
//     //結構開始使用
//     Pair* pairs = malloc(sizeof(Pair)*strsSize);
//     //這邊產生陣列
//     //pairs : [{origninal: "eat" , sorted: "aet"},{origninal: "tea" , sorted: "aet"},....]共有6個

//     //      把文字排序用 ===> qsort 函式 
//     for (int i = 0; i < strsSize; i++){
//         char *sorted_str = malloc(sizeof(char)*strlen(strs[i])+1);
//         strcpy(sorted_str,strs[i]);
//         qsort(sorted_str,strlen(strs[i]),sizeof(char),cmpChar);
//         //儲存 pairs內的值:
//         pairs[i].origninal = strs[i];
//         pairs[i].sorted = sorted_str;        
//     }

//     //重新編排 Pairs
//     //qsort(重新編排的內容, 總共有多少個, 一個有多大,)
//     qsort(pairs,strsSize,sizeof(Pair),cmpPair);
//     /*
//     orignina:sorted
//     ----------------
//         bat : abt
//         tea : aet
//         ate : aet
//         eat : aet
//         nat : ant
//         tan : ant
//     */ 
//     char ***returnResult = NULL;//[]一開始要一個空的
//     *returnSize = 0;
//     *returnColumnSizes = NULL;
//     // returnResult : [], *returnSize : 0, *returnColumnSizes : [];
   
//     //第一個字  case 1
//     returnResult = malloc(sizeof(char**)*1);
//     returnResult[0] = malloc(sizeof(char*)*1);
//     returnResult[0][0] = pairs[0].origninal;
    
//     *returnSize = 1;
//     *returnColumnSizes = malloc(sizeof(int)*1);
//     (*returnColumnSizes)[0] = 1;
//     // returnResult : [["bat"]], retuenSize : 1, returnColumsSizes:[1]
//     //第二個字   case 1
//     returnResult = realloc(returnResult,sizeof(char**)*2);
//     //returnResult : [["bat"],["eat"]];
//     returnResult[1] = malloc(sizeof(char*)*1);
//     returnResult[1][0] = pairs[1].origninal;
    
//     *returnSize = 2;
//     *returnColumnSizes = realloc(*returnColumnSizes,sizeof(int)*2);
//     (*returnColumnSizes)[1] = 1;
//     // returnResult : [["bat"]], retuenSize : 1, returnColumsSizes:[1]
    
//     //第三個字  case 2
//     returnResult[1] = realloc(returnResult[1],sizeof(char*)*2);
//     returnResult[1][1] = pairs[2].origninal;

//     (*returnColumnSizes)[1] = 2;
//     printf("test");
//     for (int i = 0; i < 6; i++){
//         printf("%s : %s \n",pairs[i].origninal,pairs[i].sorted);
//     }
//     printf("test");
//     return returnResult;
// }




//最終版
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