//
//  AccessDepartment.m
//  abstract-factory
//
//  Created by 王俊 on 2018/12/19.
//  Copyright © 2018 王俊. All rights reserved.
//

#import "AccessDepartment.h"
#import "../object/Department.h"

@implementation AccessDepartment

#pragma mark - IDepartment
- (void)insertDepartment:(Department *)dept {
    NSLog(@"insert department by access");
}

- (Department *)getDepartment:(NSNumber *)ID {
    NSLog(@"get department by access");
    return [Department new];
}


@end
