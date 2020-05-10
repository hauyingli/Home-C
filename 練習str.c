#include <stdio.h>//有printf and scanf函式
#include <math.h> //數學函式
#include <stdlib.h> //有srand 函式 隨機亂數
#include <time.h> //在srand 中使用讓亂數不固定
#include <string.h> //char 字串使用的函式
#include <stdbool.h>//布林值定義

// 28. 实现 strStr()

/*
给定一个 haystack 字符串和一个 needle 字符串，
在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。
如果不存在，则返回  -1。
*/


int strStr(char *, char *);
int ViolentMatch(char*, char*);
int main(){
    // Ex: input: haystack = "hello", needle = "ll"
    // ouput: should be return 2;
    char* haystack = "hello";
    char* needle = "ll";
    // printf("%d \n", strStr(haystack,needle));
    printf("%d \n",ViolentMatch(haystack,needle));
    return 0;
}

int strStr(char * haystack, char * needle){
    int len_haystack = strlen(haystack); 
    int len_needle = strlen(needle);
    printf("%d\n", len_haystack);
    for (int i = 0; i < len_haystack; i++){
        if (haystack[i] == needle[0]&&haystack[i+1] == needle[1]){
            printf("I:%d same \n",i);
        }
        
    }
    return 0;
}

int ViolentMatch(char* s, char* p)
{
	int sLen = strlen(s);//抓取 近來的字元大小
	int pLen = strlen(p);//抓取 近來的字元大小
	int i = 0;
	int j = 0;
	while (i < sLen && j < pLen){
		if (s[i] == p[j]){//①如果当前字符匹配成功（即S[i] == P[j]），则i++，j++    
			i++;
			j++;
		}
		else{//②如果失配（即S[i]! = P[j]），令i = i - (j - 1)，j = 0    
			i = i - j + 1;
			j = 0;
		}
	}
	//匹配成功，返回模式串p在文本串s中的位置，否则返回-1
	if (j == pLen)
		return i - j;
	else
		return -1;
}



// "a"
// ""
// // and
// ""
// "a"
// and
// "aaa"
// "a"