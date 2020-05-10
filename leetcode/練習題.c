#include<stdio.h>

// 买卖股票的最佳时机 II  leetcode 練習題

// puts("XOR運算：");
// printf("0 XOR 0\t\t%d\n", 0 ^ 0);
// printf("0 XOR 1\t\t%d\n", 0 ^ 1);
// printf("1 XOR 0\t\t%d\n", 1 ^ 0);
// printf("1 XOR 1\t\t%d\n\n", 1 ^ 1);




int maxProfit(int* ,int);



int main(){
    int prices[7] = {7,1,5,3,6,4};
    int pricesSize = 6;
    maxProfit(prices,pricesSize);
    return 0;
}

int maxProfit(int* prices, int pricesSize){
    int made = 0; //存最後能賺到的錢
    int t = prices[0];
    for (int i = 1; i < 3; i++){
        if(prices[i] < prices[i+1]){
            made = prices[i+1] - prices [i];
        }
    }
    printf("%d ", made);
    
    return 0;
}