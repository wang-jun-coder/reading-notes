//
//  SqlServerFactory.m
//  abstract-factory
//
//  Created by 王俊 on 2018/12/19.
//  Copyright © 2018 王俊. All rights reserved.
//

#import "SqlServerFactory.h"

#import "../sql/SqlServerUser.h"
#import "../sql/SqlServerDepartment.h"

@implementation SqlServerFactory

#pragma makr - IFactory
- (id<IUser>)createUser {
    return [SqlServerUser new];
}
- (id<IDepartment>)createDepartment {
    return [SqlServerDepartment new];
}

@end
