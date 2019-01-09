//
//  Waiter.m
//  command
//
//  Created by 王俊 on 2019/1/9.
//  Copyright © 2019 王俊. All rights reserved.
//

#import "Waiter.h"
#import "BakeChickenWingCommand.h"

@interface Waiter ()

@property (nonatomic, strong) NSMutableArray<id<Command>> *orders;

@end
@implementation Waiter

- (void)setOrder:(id<Command>)command {
    if ([command isKindOfClass:[BakeChickenWingCommand class]]) {
        NSLog(@"服务员: 鸡翅没了, 请点其他烧烤");
        return;
    }
    [self.orders addObject:command];
    NSLog(@"增加订单: %@ 时间: %@", command, [NSDate date]);
}

- (void)cancelOrder:(id<Command>)command {
    [self.orders removeObject:command];
    NSLog(@"取消订单: %@ 时间: %@", command, [NSDate date]);
}

- (void)notify {
    for (id<Command> cmd in self.orders) {
        [cmd excuteCommand];
    }
}

#pragma mark - getters && setters
- (NSMutableArray<id<Command>> *)orders {
    if (!_orders) {
        _orders = [NSMutableArray array];
    }
    return _orders;
}

@end
