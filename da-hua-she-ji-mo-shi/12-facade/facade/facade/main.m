//
//  main.m
//  facade
//
//  Created by 王俊 on 2018/12/17.
//  Copyright © 2018 王俊. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "facade/Fund.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
//        NSLog(@"Hello, World!");
        
        Fund *fund = [Fund new];
        
        [fund buyFund];
        [fund sellFund];
    }
    return 0;
}
