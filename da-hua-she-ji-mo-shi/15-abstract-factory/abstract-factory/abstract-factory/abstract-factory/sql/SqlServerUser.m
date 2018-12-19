//
//  SqlServerUser.m
//  abstract-factory
//
//  Created by 王俊 on 2018/12/19.
//  Copyright © 2018 王俊. All rights reserved.
//

#import "SqlServerUser.h"
#import "../object/User.h"

@implementation SqlServerUser

#pragma mark - IUser
- (void)insertUser:(User *)user {
    NSLog(@"insert user by sql server");
}

- (User *)getUser:(NSNumber *)ID {
    NSLog(@"get user by sql server");
    return [User new];
}

@end
