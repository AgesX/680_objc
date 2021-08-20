//
//  main.c
//  ccc
//
//  Created by Jz D on 2021/8/20.
//

#include <stdio.h>



struct Node{
    int val;
    struct Node *left;
    
    //  struct Node rhs;    //  Field has incomplete type 'struct Node'
    
    //  必须使用， Node *
    
    //  否则编译的时候，展开，又是他自己，这个结构体
    
    //  无限循环下去
}root;
// root 是实例变量





struct Tree{
    int val;
    struct Node left;
    
    //  Must use 'struct' tag to refer to type 'Node'
    // Node rhs;
}lemon;








typedef struct Wood{
    int val;
    struct Node left;
    
    //  Must use 'struct' tag to refer to type 'Node'
    struct Node * rhs;
   // Node * sibling;
}Forest;

//  Forest,  是别名



struct Flower{
    int val;
    
    // 使用别名，就可以不加 struct
    
    
    // 感觉 alias, 就是 struct Forest
    
    
    Forest front;
    
    Forest * back;
}tail;



int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    
    printf("%d  \n\n", root.val);
    
    struct Flower rose;
    
    rose.val = 50;
    
    printf("%d  \n\n", rose.val);
    
    
    return 0;
}
