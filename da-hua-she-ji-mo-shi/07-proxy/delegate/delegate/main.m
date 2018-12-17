//
//  main.m
//  delegate
//
//  Created by 王俊 on 2018/12/17.
//  Copyright © 2018 王俊. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "delegate/Person.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
//        NSLog(@"Hello, World!");
        
        Person *jiaojiao = [[Person alloc] initWithName:@"娇娇"];
        Person *dali = [[Person alloc] initWithName:@"戴励"];
        Person *zhuojiayi = [[Person alloc] initWithName:@"卓贾易"];
        
        // 卓贾易与娇娇不熟, 委托戴励送礼给娇娇
        zhuojiayi.delegate = dali;
        [zhuojiayi giveDollsToPerson:jiaojiao];
        [zhuojiayi giveFlowersToPerson:jiaojiao];
        [zhuojiayi giveChocolateToPerson:jiaojiao];
        
    }
    return 0;
}
