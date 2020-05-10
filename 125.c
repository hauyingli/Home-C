#include <stdio.h>//有printf and scanf函式
#include <math.h> //數學函式
#include <stdlib.h> //有srand 函式 隨機亂數
#include <time.h> //在srand 中使用讓亂數不固定
#include <string.h> //char 字串使用的函式
#include <stdbool.h>//布林值定義
#include <ctype.h> // 檢查字母大小寫  ex: isupper(s[i]);
/*
125. 验证回文串  leetcode 練習

给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:
输入: "A m a n,a p l a n,a c a n a l: P a n a m a" 正
       a m a n a p l a n a c a n a l  p a n a m a  反
输出: true

示例 2:
输入: "race a car"
输出: false
*/
// A m a n,a p l a n,   a canal: Panam
// a m a n a p l a n  相反

int main(){
    const char* s = {"raCe a car"};
    int lens = strlen(s);
    char* var = (char*)malloc(sizeof(char) * lens);
    int top = -1, i;//top 要為 '-1'  讓後面變成  ++top 才正確。

    for (i = 0; i < lens; i++){ // 把全部的 字元做整理 存到char var[xxx] 裡面
                                // 指存取 小寫 字母 or 數字 and 大寫字母(轉成小寫) 
        if (isupper(s[i])){ // 檢查是否是大寫
            var[++top] = s[i] + 32 ; // 把讀取到的 大寫轉換成小寫 +32 , 存到 var[top]裡面.
        }
        else if (islower(s[i]) || isdigit(s[i])){
            var[++top] = s[i];  // 把讀取到的 小寫字母 或是  數字 存到新的var[top] 裡面
        }
    }  //轉換結束
    for (int i = 0; i < lens; i++){// 開始做比對 
        if (isupper(s[i])){
            char check = var[top];  
            if (s[i] + 32 != check){ // 確認 原始值 如果是大寫(轉乘小寫了) 對應到反過來是不是一樣
                return 0; // 回傳 false
            }
            top--;
        }
        else if(islower(s[i]) || isdigit(s[i])){
            char check = var[top];
            if(s[i] != check){
                return 0; // 回傳 false
            }
            //如果一樣 就 top--; 把var[top] 往前推再對一次
            top--;
        }
    }
    if (top >= 0){// top 沒有被全部對完 回傳 false;
        return 0; // 回傳 false
    }
    return 1;
}
void isPalindrome(char * s){ //本來是要回傳bool

}

