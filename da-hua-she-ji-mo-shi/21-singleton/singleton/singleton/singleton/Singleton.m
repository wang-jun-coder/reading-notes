//
//  Singleton.m
//  singleton
//
//  Created by 王俊 on 2018/12/28.
//  Copyright © 2018 王俊. All rights reserved.
//

#import "Singleton.h"

@implementation Singleton

+ (instancetype)shareInstance {
    static Singleton *singleton = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        singleton = [[super allocWithZone:NULL] init];
    });
    return singleton;
}

+ (instancetype)allocWithZone:(struct _NSZone *)zone {
    return [self shareInstance];
}

- (id)copyWithZone:(NSZone *)zone {
    return [[self class] shareInstance];
}

@end
