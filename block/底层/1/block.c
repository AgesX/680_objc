#include <stdio.h>

int main(){
    int a = 10;
    void(^block)(void) = ^{
        printf(" 6 6  6  %d \n", a);
    };
    block();
    return 0;
}
