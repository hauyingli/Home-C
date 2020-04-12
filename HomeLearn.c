
// 【C 語言的 LeetCode 30 天挑戰】第十天 (Min Stack)
//堆疊(stack): LIFO (last in first out)
//佇列(queue): FIFO (First in first out)
void learn(stack){
    //push, pop ,top ,isEmpty
    //s : []// s 是個堆疊(stack)
    //push(s, 10) =>
    //s:[10]
    //push(s,20) =>
    //s:[10, 20]
    //push(s,30) =>
    //s:[10, 20, 30]
    //push(s,40) =>  加在尾巴
    //s:[10, 20, 30, 40]
    //pop(s) //把最一個丟出去
    //s:[10, 20, 30]
    //pop(s)
    //s:[10, 20]
    //pop(s)
    //isEmpty(s) == False
    //s:[10]
    //pop(s)
    //s:[]
    //isEmpty(s) == Ture
}


//自定義型態(type)
typedef struct{
    /* data */
    int data[100];
}; Stack;//這樣就能當一個明子來使用
void Push(Stack s, int x){
    s.data[0] = 10;
}
PrintStack(Stack s){
    printf("%d", s)
}

int main(){

    //希望有個s 用起來像堆疊
    Stack s;
    return 0;
}
