//
//  main.m
//  observer
//
//  Created by 王俊 on 2018/12/19.
//  Copyright © 2018 王俊. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "observer/Boss.h"
#import "observer/StockObserver.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
//        NSLog(@"Hello, World!");
        
        Boss *huhansan = [Boss new];
        
        StockObserver *tongshi1 = [[StockObserver alloc] initWithName:@"魏关诧"];
        StockObserver *tongshi2 = [[StockObserver alloc] initWithName:@"易管查"];
        
        [huhansan attach:tongshi1];
        [huhansan attach:tongshi2];
        
        [huhansan detach:tongshi1];
        
        huhansan.state = @"我胡汉三回来了!";
        [huhansan notify];
        
        
        // OC 本身的观察者机制
        [huhansan addObserver:tongshi1 forKeyPath:@"state"
                      options:NSKeyValueObservingOptionNew | NSKeyValueObservingOptionOld
                      context: nil];
        [huhansan addObserver:tongshi2 forKeyPath:@"state"
                      options:NSKeyValueObservingOptionNew | NSKeyValueObservingOptionOld
                      context: nil];
        [huhansan removeObserver:tongshi1 forKeyPath:@"state"];
        
        huhansan.state = @"我胡汉三又回来了!";
        
        
    }
    return 0;
}
