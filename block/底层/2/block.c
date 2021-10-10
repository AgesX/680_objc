#include <stdio.h>

int main(){
    __block int a = 10;
    
    // 添加了 __block，
    
    // int a,
    
    // 就会编译成，结构体
    
    
    
    
    void(^block)(void) = ^{
        a += 100;
        printf(" 6 6  6  %d \n", a);
    };
    block();
    return 0;
}
