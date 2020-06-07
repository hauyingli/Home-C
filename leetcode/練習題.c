#include<stdio.h>

// 买卖股票的最佳时机 II  leetcode 練習題

// puts("XOR運算：");
// printf("0 XOR 0\t\t%d\n", 0 ^ 0);
// printf("0 XOR 1\t\t%d\n", 0 ^ 1);
// printf("1 XOR 0\t\t%d\n", 1 ^ 0);
// printf("1 XOR 1\t\t%d\n\n", 1 ^ 1);




// int maxProfit(int* ,int);



// int main(){
//     int prices[7] = {7,1,5,3,6,4};
//     int pricesSize = 6;
//     maxProfit(prices,pricesSize);
//     return 0;
// }

// int maxProfit(int* prices, int pricesSize){
//     int made = 0; //存最後能賺到的錢
//     int t = prices[0];
//     for (int i = 1; i < 3; i++){
//         if(prices[i] < prices[i+1]){
//             made = prices[i+1] - prices [i];
//         }
//     }
//     printf("%d ", made);
    
//     return 0;
// }






//練習 在字串中找出最大連續的字串
//ex: int n[9] = {1,2,-1,3,4,-3,-1,-2} // 所以最大的字串是 n[0]-n[4] sum = 8
int main(){
    int nums[9] = {1,2,-1,3,4,-3,-1,-2};
    int numsSize = 9;
    int max = 0;
    // int sum = 0;
    for (int i = 0; i < numsSize; i++){// i = 0 ~ 9
        for (int j = i; j < numsSize; j++){// j = i ~ 9
            int sum = 0;
            for (int k = i; k <= j; k++){
                sum += nums[k];
            }
            printf("%d %d : %d \n",i,j,sum);
        }    
    }
    
}