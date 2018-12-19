//
//  IUser.h
//  abstract-factory
//
//  Created by 王俊 on 2018/12/19.
//  Copyright © 2018 王俊. All rights reserved.
//

#ifndef IUser_h
#define IUser_h

@class User;
@protocol IUser <NSObject>

@required
- (void)insertUser:(User *)user;
- (User *)getUser:(NSNumber *)ID;

@end

#endif /* IUser_h */
