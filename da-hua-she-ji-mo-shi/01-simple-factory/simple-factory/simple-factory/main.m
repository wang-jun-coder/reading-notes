//
//  main.m
//  simple-factory
//
//  Created by 王俊 on 2018/12/15.
//  Copyright © 2018 王俊. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "operation/OperationFactory.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
//        NSLog(@"Hello, World!");
        
        NSLog(@"请输入数字 A, 并回车确认: ");
        double numA = 0;
        scanf("%lf", &numA);
        
        NSLog(@"请输入运算符(+、-、*、/), 并回车确认: ");
        char operChars[1] = {};
        scanf("%s",operChars);
        NSString *operStr = [NSString stringWithUTF8String:operChars];
        
        NSLog(@"请输入数字 B, 并回车确认: ");
        double numB = 0;
        scanf("%lf", &numB);
        
        Operation *operation = [OperationFactory createOperation:operStr];
        operation.numA = numA;
        operation.numB = numB;
        double result = operation.getResult;
        NSLog(@"运算结果为: %lf", result);

    }
    return 0;
}
