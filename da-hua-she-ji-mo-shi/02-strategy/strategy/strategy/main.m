//
//  main.m
//  strategy
//
//  Created by 王俊 on 2018/12/15.
//  Copyright © 2018 王俊. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "strategy/CashContext.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
//        NSLog(@"Hello, World!");
        
    
        const double totalPrice = 985;
        
        // 正常收费
        CashContext *context = [[CashContext alloc] initWithType:@"正常收费"];
        NSLog(@"应付: %lf", [context getResultWithCash:totalPrice]);
        
        // 满300减100
        context = [[CashContext alloc] initWithType:@"满300返100"];
        NSLog(@"应付: %lf", [context getResultWithCash:totalPrice]);
        
        // 打8折
        context = [[CashContext alloc] initWithType:@"打8折"];
        NSLog(@"应付: %lf", [context getResultWithCash:totalPrice]);
        
        
        
    }
    return 0;
}
