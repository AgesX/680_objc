#include <stdio.h>

int main(){
    void(^block)(void) = ^{
        printf(" 6 6  6   \n");
    };
    block();
    return 0;
}
