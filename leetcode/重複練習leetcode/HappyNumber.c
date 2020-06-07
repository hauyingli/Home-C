#include <stdio.h>//有printf and scanf函式
#include <math.h> //數學函式
#include <stdlib.h> //有srand 函式 隨機亂數
#include <time.h> //在srand 中使用讓亂數不固定
#include <string.h> //char 字串使用的函式
#include <stdbool.h>//布林值定義

/*
Write an algorithm to determine if a number n is "happy".
A happy number is a number defined by the following process: 
Starting with any positive integer, replace the number by the sum of the squares of its digits, 
and repeat the process until the number equals 1 (where it will stay), 
or it loops endlessly in a cycle which does not include 
1. Those numbers for which this process ends in 1 are happy numbers.

Return True if n is a happy number, and False if not.

Example: 
Input: 19
Output: true
Explanation: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
Write an algorithm to determine if a number n is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Return True if n is a happy number, and False if not.

Example: 
*/

int N_new(int n){//獲取新的INT(Ex: 19 變成 1的2次方 跟  9的二次方 兩個數字)==82
    int new_n = 0;
    int k = 0;
    while (n != 0){
        k = n % 10;
        n /= 10;
        new_n = new_n + (k * k);
    }
    // printf("%d \n",new_n);
    return new_n;
}
int IsHappy(int n){ //確認有沒有重複出現
    int slow = n;// 烏龜 一次走一次
    int fast = n;// 兔子 一次走兩格
    do{
        slow = N_new(slow);
        fast = N_new(N_new(fast));
    } while (slow != fast);
    return fast == 1;
}

int main(){
    int n = 19;
    printf("%d \n",IsHappy(n));
    return 0;
}



