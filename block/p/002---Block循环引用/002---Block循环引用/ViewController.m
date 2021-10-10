//
//  ViewController.m
//  002---Block循环引用
//
//  Created by Cooci on 2018/6/24.
//  Copyright © 2018年 Cooci. All rights reserved.
//

#import "ViewController.h"

typedef void(^KCBlock)(ViewController *);

typedef void(^BlockDeng)(void);


@interface ViewController ()
@property (nonatomic, copy) KCBlock block;

@property (nonatomic, copy) BlockDeng blockFirst;


@property (nonatomic, copy) BlockDeng blockSecond;


@property (nonatomic, copy) NSString *name;

@property (nonatomic, strong) UITableView *tableView;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // 循环引用
    self.name = @"666   ";

    
    // [self blockDemo];
  //  [self blockDemo_more_gg];
   // [self blockDemoTwo];
    [self demoFinal];
    
    
}



// 哈希表
- (void)blockDemo_more_gg{
    __weak typeof(self) weakSelf = self;
    
    // 使用 __weak 后， self 的引用计数，没有增长
    // 相当于 self 没有被 block 捕获， 不影响 self 的生命周期
    // self 该怎么释放，就怎么释放
    
    
    NSLog(@"raw %p, weak %p", &self, &weakSelf);
    self.blockFirst = ^(void){
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
            [weakSelf.navigationController popViewControllerAnimated: YES];
            // 配合操作，是马上返回
            dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
                
                // 配合操作，是马上返回
                
                NSLog(@"%@",  weakSelf.name);
            });
        });
    };
    self.blockFirst();

    //
    
    //
}


// 哈希表
- (void)blockDemo{
    __weak typeof(self) weakSelf = self;
    
    // 使用 __weak 后， self 的引用计数，没有增长
    // 相当于 self 没有被 block 捕获， 不影响 self 的生命周期
    // self 该怎么释放，就怎么释放
    
    
    NSLog(@"raw %p, weak %p", &self, &weakSelf);
    self.blockFirst = ^(void){
        
        
        // 异步操作
        
        // 消耗:    时间 - 精力
        
        
        
        
        // 需要保证:   self 的生命周期
        
       // NSLog(@"raw %p, weak %p", &self, &weakSelf);
        
        
        __strong __typeof(weakSelf)strongSelf = weakSelf; //  什么时候， when,    可以释放, self
        
        // strongSelf 的释放，导致 weakSelf 的释放
        // weakSelf 的释放，导致 self ( 控制器 ) 的释放
        
        
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(2 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
            
            [strongSelf.navigationController popViewControllerAnimated: YES];
            
            dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
                
                // 配合操作，是马上返回
                
                NSLog(@"%@",strongSelf.name);
            });
            
        });
    };
    self.blockFirst();

    //
    
    
    //
}





- (void)blockDemoTwo{
    
    
    // 虽然 vc 是一个临时变量，但是 vc 被捕获进去了
    
    // 这个捕获，block 对 vc 进行了， 三层拷贝
    
    // （ 值， 指针 ）
    
    __block ViewController *vc = self;
    self.blockSecond = ^(void){
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(2 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
            
            [vc.navigationController popViewControllerAnimated: YES];
            // 配合操作，是马上返回
            dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
                
                // 配合操作，是马上返回
                
                NSLog(@"%@",  vc.name);
                vc = nil;
            });
        });
    };
    
    
    // 建立循环引用
    // vc -> self -> blockSecond -> vc
    
    self.blockSecond();
    
    
}




- (void)dealloc{
    NSLog(@"dealloc 来了");
}





- (void)demoFinal{
    // self -> block -> vc = nil -> self
    // 弱引用表 是同一个指针地址
    // weakSelf 是否会对引用计数处理? 留给自己分析 1
    // 循环引用的解决方式
    // weak-strong-dance 强弱共舞
    
    // 中介者模式 自动 手动
    
    
    // 加了一层，间接
    
    
    
    
    
    
    
    
    // block -> vc - block 三层block
    // proxy 预习
    // self -> block -> self - 通讯
    self.block = ^(ViewController *vc){
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(2 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
            [vc.navigationController popViewControllerAnimated: YES];
            // 配合操作，是马上返回
            dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
                
                // 配合操作，是马上返回
                
                NSLog(@"%@",  vc.name);
            });
        });
    };
    self.block(self);
    
    // block
}


@end
