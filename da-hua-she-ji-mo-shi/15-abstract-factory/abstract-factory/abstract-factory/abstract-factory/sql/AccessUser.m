//
//  AccessUser.m
//  abstract-factory
//
//  Created by 王俊 on 2018/12/19.
//  Copyright © 2018 王俊. All rights reserved.
//

#import "AccessUser.h"
#import "../object/User.h"

@implementation AccessUser

#pragma mark - IUser
- (void)insertUser:(User *)user {
    NSLog(@"insert user with access");
}

- (User *)getUser:(NSNumber *)ID {
    NSLog(@"get user by access");
    return [User new];
}


@end
