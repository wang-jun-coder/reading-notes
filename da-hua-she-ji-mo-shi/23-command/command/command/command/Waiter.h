//
//  Waiter.h
//  command
//
//  Created by 王俊 on 2019/1/9.
//  Copyright © 2019 王俊. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Command.h"

NS_ASSUME_NONNULL_BEGIN

@interface Waiter : NSObject

- (void)setOrder:(id<Command>)command;
- (void)cancelOrder:(id<Command>)command;

- (void)notify;


@end

NS_ASSUME_NONNULL_END
