//
//  main.m
//  singleton
//
//  Created by 王俊 on 2018/12/28.
//  Copyright © 2018 王俊. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "./singleton/Singleton.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
//        NSLog(@"Hello, World!");
        
        Singleton *s1 = [Singleton shareInstance];
        Singleton *s2 = [Singleton shareInstance];
        
        Singleton *n1 = [Singleton new];
        Singleton *n2 = [[Singleton alloc] init];
        
        Singleton *c1 = [s1 copy];
        
        s1.name = @"[Singleton shareInstance]";
        NSLog(@"s1: %@ name: %@", s1, s1.name);
        NSLog(@"s2: %@ name: %@", s2, s2.name);
        NSLog(@"n1: %@ name: %@", n1, n1.name);
        NSLog(@"n2: %@ name: %@", n2, n2.name);
        NSLog(@"c1: %@ name: %@", c1, c1.name);
        
        n1.name = @"[Singleton new]";
        NSLog(@"s1: %@ name: %@", s1, s1.name);
        NSLog(@"s2: %@ name: %@", s2, s2.name);
        NSLog(@"n1: %@ name: %@", n1, n1.name);
        NSLog(@"n2: %@ name: %@", n2, n2.name);
        NSLog(@"c1: %@ name: %@", c1, c1.name);
        
    }
    return 0;
}
