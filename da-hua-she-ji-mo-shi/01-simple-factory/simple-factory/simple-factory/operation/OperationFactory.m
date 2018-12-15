//
//  OperationFactory.m
//  simple-factory
//
//  Created by 王俊 on 2018/12/15.
//  Copyright © 2018 王俊. All rights reserved.
//

#import "OperationFactory.h"

// 抽象产品
#import "OperationAdd.h"
#import "OperationSub.h"
#import "OperationMul.h"
#import "OperationDiv.h"

@implementation OperationFactory

#pragma mark - Class methods
+ (Operation *)createOperation:(NSString *)operation {
    
    Operation *oper = nil;
    
    if([operation isEqualToString:@"+"]) {
        oper = [OperationAdd new];
    }
    if([operation isEqualToString:@"-"]) {
        oper = [OperationSub new];
    }
    if([operation isEqualToString:@"*"]) {
        oper = [OperationMul new];
    }
    if([operation isEqualToString:@"/"]) {
        oper = [OperationDiv new];
    }
    
    
    return oper;
}


@end
