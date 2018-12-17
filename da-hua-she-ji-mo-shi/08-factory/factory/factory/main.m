//
//  main.m
//  factory
//
//  Created by 王俊 on 2018/12/17.
//  Copyright © 2018 王俊. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "factory/UndergraduateFactory.h"
#import "factory/VolunteerFactory.h"
#import "factory/LeiFeng.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
//        NSLog(@"Hello, World!");
        
//        id<IFactory> factory = [[VolunteerFactory alloc] init];
        id<IFactory> factory = [[UndergraduateFactory alloc] init];
        id<LeiFeng> leifeng = (id)[factory createLeiFeng];
        [leifeng sweep];
        [leifeng wash];
        [leifeng buyRice];
        
    }
    return 0;
}
