//
//  SqlServerDepartment.m
//  abstract-factory
//
//  Created by 王俊 on 2018/12/19.
//  Copyright © 2018 王俊. All rights reserved.
//

#import "SqlServerDepartment.h"
#import "../object/Department.h"

@implementation SqlServerDepartment

#pragma mark - IDepartment
- (void)insertDepartment:(Department *)dept {
    NSLog(@"insert department by sql server");
}

- (Department *)getDepartment:(NSNumber *)ID {
    NSLog(@"get department by sql server");
    return [Department new];
}

@end
