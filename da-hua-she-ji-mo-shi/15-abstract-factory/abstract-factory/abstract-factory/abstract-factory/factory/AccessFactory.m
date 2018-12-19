//
//  AccessFactory.m
//  abstract-factory
//
//  Created by 王俊 on 2018/12/19.
//  Copyright © 2018 王俊. All rights reserved.
//

#import "AccessFactory.h"

#import "../sql/AccessUser.h"
#import "../sql/AccessDepartment.h"

@implementation AccessFactory

#pragma mark - IFactory

- (id<IUser>)createUser {
    return [AccessUser new];
}

- (id<IDepartment>)createDepartment {
    return [AccessDepartment new];
}


@end
