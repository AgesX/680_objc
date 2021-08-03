
680_objc 版本的 runtime,

为了 `static void remethodizeClass(class_t *cls)`



[深入理解Objective-C：Category](https://tech.meituan.com/2015/03/03/diveintocategory.html)



<hr>

<hr>


<hr>



    // 这个地方，根本没有存在递归
    imp = cache_getImp(curClass, sel);



<hr>

<hr>


<hr>




<hr>

<hr>


<hr>



## 关联对象



```
void
objc_setAssociatedObject(id object, const void *key, id value, objc_AssociationPolicy policy)
{
    
    //  设置，关联对象
    
    
    _object_set_associative_reference(object, key, value, policy);
}
```
