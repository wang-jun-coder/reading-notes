//
//  Boss.m
//  observer
//
//  Created by 王俊 on 2018/12/19.
//  Copyright © 2018 王俊. All rights reserved.
//

#import "Boss.h"

@interface Boss ()

@property (nonatomic, strong) NSMutableArray <id<Subject>>* observers;

@end

@implementation Boss
@synthesize state;

#pragma mark - Subject
- (void)attach:(nonnull id<Observer>)observer {
    [self.observers addObject:(id)observer];
}

- (void)detach:(nonnull id<Observer>)observer {
    [self.observers removeObject:(id)observer];
}

- (void)notify {
    for (id<Observer> observer in self.observers) {
        [observer updateWithState:self.state];
    }
}


#pragma mark - getters && setters
- (NSMutableArray<id<Subject>> *)observers {
    if (!_observers) {
        _observers = [NSMutableArray array];
    }
    return _observers;
}

@end
