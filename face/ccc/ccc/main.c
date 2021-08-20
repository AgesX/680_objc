//
//  main.c
//  ccc
//
//  Created by Jz D on 2021/8/20.
//






//    考虑，    编译的顺序






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







/*

struct tag {
    member-list
    member-list
    member-list
    ...
} variable-list ;

 

*/














/*
 
 
 
 tag 是结构体标签
 
 
 
 
 

 member-list 是标准的变量定义，比如 int i; 或者 float f，或者其他有效的变量定义。
 
 
 
 
 

 variable-list 结构变量，定义在结构的末尾，最后一个分号之前，您可以指定一个或多个结构变量


 */














/*
 


//此结构体的声明包含了指向自己类型的指针
struct NODE
{
    char string[100];
    struct NODE *next_node;
};


*/














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
