#include <stdio.h>//有printf and scanf函式
#include <math.h> //數學函式
#include <stdlib.h> //有srand 函式 隨機亂數
#include <time.h> //在srand 中使用讓亂數不固定
#include <string.h> //char 字串使用的函式
#include <stdbool.h>//布林值定義

// int isValid(char * s){
//     if (*s == 0){
//         return 1;
//     }
//     int len = strlen(s);
//     if(len & 1) {
//         return 0;
//     }
//     char stack[len];
//     int top = -1;
//     for(int i = 0; i<len;i++){
//         if( s[i] == '[' || s[i] == '{' || s[i] == '('){//第一關先確定是不是左邊的符號
//             stack[++top] = s[i];
//             //如果是就回頭到第二圈,不是就繼續往下看
//         }
//         else if (top == -1){//因為都不是左邊符號不可能合成一個正確的括弧
//             return 0;
//         }
//         //以下開始看左邊:  ']' or '}'  or ')'
//         else if(s[i] == stack[top]+1 || s[i] == stack[top]+2){
// //ex: input = " { [ ] } "
// //              0 1 2 3 
// //前面走兩圈記入 右邊的符號 i=0 跟 i=1的時候
// //現在i = 2 ,top == 1,stack[top]目前存的是"{["
// //run1 =  if s[2] == stack[1]+1 或是 s[2] == stack[1]+2 一樣就把top 減少往前推去確認
// //            ']' ==  '[' +1 or +2 會等於另外一半 ']'
// //             所以i = 2的時候 正確了 top = top -1 = 0;
// //run2 =  if  s[3] == stack[0]+1 or + 2
// //              如果是另外一半的括號    結束 top再次-- 所以top =  -1;
//             // printf("%d: %d == %d+1  top: %d\n", i,s[i],stack[top]+1,top);
//             // printf("%d: %d == %d+2\n", i,s[i],stack[top]+2);
//             stack[top--] = 0;
//         }
//         else {
//             return 0;
//         }
//     }
//     // printf("out : %d \n",top);
//     // 兩次都確認正卻 top 值 為-1
//     // 符合  top == -1; 所以retuen true;
//     return top == -1;
// }







// int isValid(char * s){
// 	if (*s == 0){
// 		return 1;
// 	}
// 	int len = strlen(s);
// 	if(len & 1){
// 		return 0;
// 	}
// 	char stack[len];
// 	int temp = -1;

// 	// strs = [{ }];
// 	for (int i = 0; i < len; i++){
// 		if(s[i] == '{' || s[i] == '[' || s[i] == '('){
// 			stack[++temp] = s[i];		
// 		}
// 		else if(temp == -1){
// 			return 0;
// 		}
// 		else if (s[i] == stack[temp]+1 || s[i] == stack[temp] +2){
// 			stack[temp--] = 0;
// 			// temp --; //這兩個很像一樣的功能
// 		}
// 		else{
// 			return 0;
// 		}
// 	}
// 	return temp == -1;
// }

// int isValid(char *s) {

//     char *q=s;
    
//     for (char *p=s; *p; p++) 
//         switch(*p) {
//             case '(': *q++ = ')'; continue;
//             case '{': *q++ = '}'; continue;
//             case '[': *q++ = ']'; continue;
//             default: if (q==s || *p != *--q) return 0;
//         }
    
//     return q==s;
// }



// int main(){
// 	printf("hello\n");
// 	const char *text1 = "[{}]";  // 沒有加上 const complier 會顯示錯誤但可以跑
// 	printf("%c \n", isValid(text1)==1 ? 'Y' : 'N');
// 	return 0;
// }




// int main(){
//     int nums = 12345;
//     int copy = nums;
//     int news = 0;
//     while(copy != 0){
//         news = news * 10 + copy % 10;
//         copy /= 10;
//     }   
//     printf("%d", news);
//     return 0; 
// }


// 27. Remove Element
// 移除指定的數字
// int main(){
//     // int nums[9] = {0,1,2,2,3,0,4,2};
//     int nums[5] = {3,2,2,3};
//     int lens = 0, numsSize = 4, val = 3, y = 0;
//     for(int i = 0; i < numsSize; i++){
//         if(nums[i] == val){
//             continue;
//         }
//         else{
//             nums[y++] = nums[i];
//             printf("%d", nums[i]);
//             lens++;
//         }
//     }
// }


//快樂數字
int main(){
    // int n = 19;

    // int d = 0,v = 0;
    // while (n != 0){
    //     v = n % 10;
    //     n /= 10;
    //     d += v*v;
    // }
    // printf("%d \n", d);
    int numsSize = 10;
    int returnN0ums = (int) malloc( 1 * numsSize);
    printf("%d",sizeof(returnN0ums));
    
    return 0;

}