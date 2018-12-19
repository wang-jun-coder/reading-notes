//
//  StockObserver.m
//  observer
//
//  Created by 王俊 on 2018/12/19.
//  Copyright © 2018 王俊. All rights reserved.
//

#import "StockObserver.h"

@interface StockObserver ()

@property (nonatomic, copy) NSString *name;

@end

@implementation StockObserver

- (instancetype)initWithName:(NSString *)name {
    self = [super init];
    if (self) {
        self.name = name;
    }
    return self;
}

#pragma mark - Observer
- (void)updateWithState:(NSString *)state {
    NSLog(@"%@, %@ 关闭股票行情, 继续工作!", state, self.name);
}


#pragma mark - NSKeyValueObserving

- (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary<NSKeyValueChangeKey,id> *)change context:(void *)context {

    NSLog(@"%@ on OC observers\nkeyPath: %@ \nobject: %@ \nchange: %@",self.name, keyPath, object, change);
}

@end
