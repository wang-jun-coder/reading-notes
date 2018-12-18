//
//  main.m
//  builder
//
//  Created by 王俊 on 2018/12/17.
//  Copyright © 2018 王俊. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "builder/PersonDirector.h"
#import "builder/PersonThinBuilder.h"
#import "builder/PersonFatBuilder.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
//        NSLog(@"Hello, World!");
        
        PersonThinBuilder *thinBuilder = [[PersonThinBuilder alloc] init];
        PersonDirector *thinDirector = [[PersonDirector alloc] initWithBuilder:thinBuilder];
        [thinDirector buildPerson];
        
        
        PersonFatBuilder *fatBuilder = [[PersonFatBuilder alloc] init];
        PersonDirector *fatDirector = [[PersonDirector alloc] initWithBuilder:fatBuilder];
        [fatDirector buildPerson];
        
    }
    return 0;
}
