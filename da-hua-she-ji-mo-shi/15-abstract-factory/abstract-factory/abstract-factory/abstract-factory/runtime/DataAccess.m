//
//  DataAccess.m
//  abstract-factory
//
//  Created by 王俊 on 2018/12/19.
//  Copyright © 2018 王俊. All rights reserved.
//

#import "DataAccess.h"

@interface DataAccess ()

@property (nonatomic, copy) NSString *db;

@end

@implementation DataAccess

- (instancetype)init {
    self = [super init];
    if (self) {
        NSString *path = [[NSBundle mainBundle] pathForResource:@"config.plist" ofType:nil];
        NSDictionary *config = [NSDictionary dictionaryWithContentsOfFile:path];
        _db = [config objectForKey:@"db"];
        if (!_db || [_db isEqualToString:@""]) {
            NSLog(@"配置文件有误, 请检查配置文件");
        }
    }
    return self;
}

#pragma makr - IFactory
- (id<IUser>)createUser {
    NSString *className = [self.db stringByAppendingString:@"User"];
    Class UserClass = NSClassFromString(className);
    if(!UserClass) {
        NSLog(@"配置项有误, 请检查配置文件");
    }
    return [UserClass new];
}
- (id<IDepartment>)createDepartment {
    NSString *className = [self.db stringByAppendingString:@"Department"];
    Class DepartmentClass = NSClassFromString(className);
    if(!DepartmentClass) {
        NSLog(@"配置项有误, 请检查配置文件");
    }
    return [DepartmentClass new];
}

@end
