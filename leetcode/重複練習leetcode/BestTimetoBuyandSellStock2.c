#include <stdio.h>//有printf and scanf函式
#include <math.h> //數學函式
#include <stdlib.h> //有srand 函式 隨機亂數
#include <time.h> //在srand 中使用讓亂數不固定
#include <string.h> //char 字串使用的函式
#include <stdbool.h>//布林值定義


/*
Say you have an array prices for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
(i.e., buy one and sell one share of the stock multiple times).
Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
Example 1:
Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Example 2:
Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
Example 3:
Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/

//貪心算法(Greedy)
// int maxProfit(int* prices,int pricesSize){
//     int max = 0;
//     for (int i = 0; i < pricesSize-1; i++){
//         if(prices[i] < prices[i+1]){
//             max += prices[i+1] - prices[i];
//             // printf("%d \n",max);
//         }
//     }
//     // printf("%d \n",max);
//     return max;
// }

// DP解 動態規劃很重要！！！！！！！！！！！！   Dynamic Programming
// int maxProfit(int* prices,int pricesSize){//有錯代修改  動態規劃的思路 (版本一會產生效率問題 RUN TIME 過長)
//     if(pricesSize <= 1) return 0;
//     // int profits[pricesSize+1];
//     int profit;
//     int max = 0;
//     //決定要不要賣最後一天
//     profit = maxProfit(prices,pricesSize -1);
//     if (profit > max){
//         max = profit;
//     }
//     //決定要賣最後一天
//     for (int i = 1; i <= pricesSize-1; i++){
//         profit = maxProfit(prices, i) + prices[pricesSize-1] - prices[i-1];
//         if(profit > max){
//             max = profit;
//         }
//     }
//     // printf("%d \n",max);
//     return max;
// }
//版本二 優化run time 的異常
int maxProfit(int* prices,int pricesSize){//有錯代修改  動態規劃的思路 (版本一會產生效率問題 RUN TIME 過長)
    int profits[pricesSize+1];
    if(pricesSize <= 1) return 0;    
    for (int k = 2; k <= pricesSize; k++){
        int max = 0;
        int profit;
        profit = profits[k-1];
        if (profit > max){
            max = profit;
        }
        for (int i = 1; i <= k-1; i++){
            profit = profits[i] + prices[k-1] - prices[i-1];
            if(profit > max){
                max = profit;
            }
        }
        profits[k] = max;
        // printf("%d \n",max);
    }
    return profits[pricesSize];
}

int main(){
    int prices[6] = {7,1,5,3,6,4};
    int pricesSize = 6;
    printf("%d \n",maxProfit(prices,pricesSize));
    // maxProfit(prices,pricesSize);
    return 0;
}