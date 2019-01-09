//
//  Manager.h
//  chain-of-responsibility
//
//  Created by 王俊 on 2019/1/9.
//  Copyright © 2019 王俊. All rights reserved.
//

#ifndef Manager_h
#define Manager_h

@class Request;
@protocol Manager <NSObject>

@required
@property (nonatomic, copy) NSString *name;
@property (nonatomic, strong) id<Manager> superior;

- (id<Manager>)initWithName:(NSString *)name;
- (void)requestApplications:(Request *)request;

@end

#endif /* Manager_h */
