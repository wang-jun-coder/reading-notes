//
//  main.m
//  iterator
//
//  Created by 王俊 on 2018/12/28.
//  Copyright © 2018 王俊. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "./iterator/ConcreteIterator.h"
#import "./iterator/ConcreteAggregate.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
//        NSLog(@"Hello, World!");
        
        ConcreteAggregate *aggregate = [ConcreteAggregate new];
        
        [aggregate addObject:@"大鸟"];
        [aggregate addObject:@"小菜"];
        [aggregate addObject:@"行李"];
        [aggregate addObject:@"老外"];
        [aggregate addObject:@"公交内部员工"];
        [aggregate addObject:@"小偷"];
        
        id<Iterator> iterator = [aggregate createIterator];
        [iterator first];
        while (!iterator.isDone) {
            NSLog(@"%@ 请买车票", [iterator currentItem]);
            [iterator next];
        }
        
        
    }
    return 0;
}
