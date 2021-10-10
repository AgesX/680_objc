

struct __Block_byref_a_0 {
  void *__isa;
__Block_byref_a_0 *__forwarding;
 int __flags;
 int __size;
 int a;
};








//  关键代码，这里的 a 是 _a->__forwarding

//  a(_a->__forwarding)



struct __main_block_impl_0 {
  struct __block_impl impl;
  struct __main_block_desc_0* Desc;
  __Block_byref_a_0 *a; // by ref
  __main_block_impl_0(void *fp, struct __main_block_desc_0 *desc, __Block_byref_a_0 *_a, int flags=0) : a(_a->__forwarding) {
    impl.isa = &_NSConcreteStackBlock;
    impl.Flags = flags;
    impl.FuncPtr = fp;
    Desc = desc;
  }
};






static void __main_block_func_0(struct __main_block_impl_0 *__cself) {




        // 指针拷贝


        __Block_byref_a_0 *a = __cself->a; // bound by ref

        (a->__forwarding->a) += 100;
        printf(" 6 6  6  %d \n", (a->__forwarding->a));
    }





static void __main_block_copy_0(struct __main_block_impl_0*dst, struct __main_block_impl_0*src) {_Block_object_assign((void*)&dst->a, (void*)src->a, 8/*BLOCK_FIELD_IS_BYREF*/);}

static void __main_block_dispose_0(struct __main_block_impl_0*src) {_Block_object_dispose((void*)src->a, 8/*BLOCK_FIELD_IS_BYREF*/);}

static struct __main_block_desc_0 {
  size_t reserved;
  size_t Block_size;
  void (*copy)(struct __main_block_impl_0*, struct __main_block_impl_0*);
  void (*dispose)(struct __main_block_impl_0*);
} __main_block_desc_0_DATA = { 0, sizeof(struct __main_block_impl_0), __main_block_copy_0, __main_block_dispose_0};
int main(){


    
    //  __Block_byref_a_0


    //  结构体，初始化



    // 第一个参数， isa 为 0 ，
    // 因为没有当前的 isa 地址


    __attribute__((__blocks__(byref))) __Block_byref_a_0 a = {
                                                              (void*)0,
                                                              (__Block_byref_a_0 *)&a,
                                                              0, 
                                                              sizeof(__Block_byref_a_0),
                                                                10
                                                                };


    //  __Block_byref_a_0 a
    //  结构体， 对象


    // &a ，取地址，才能去修改

    void(*block)(void) = ((void (*)())&__main_block_impl_0((void *)__main_block_func_0, &__main_block_desc_0_DATA, (__Block_byref_a_0 *)&a, 570425344));
    ((void (*)(__block_impl *))((__block_impl *)block)->FuncPtr)((__block_impl *)block);
    return 0;
}
static struct IMAGE_INFO { unsigned version; unsigned flag; } _OBJC_IMAGE_INFO = { 0, 2 };






