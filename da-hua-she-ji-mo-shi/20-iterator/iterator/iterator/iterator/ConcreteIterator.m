//
//  Iterator.m
//  iterator
//
//  Created by 王俊 on 2018/12/28.
//  Copyright © 2018 王俊. All rights reserved.
//

#import "ConcreteIterator.h"
#import "Aggreagate.h"

@interface ConcreteIterator ()

@property (nonatomic, strong) id<Aggregate> aggregate;
@property (nonatomic, assign) NSInteger current;

@end

@implementation ConcreteIterator

- (instancetype)initWithAggregate:(id<Aggregate>)aggregate {
    self = [super init];
    if (self) {
        self.aggregate = aggregate;
        self.current = 0;
    }
    return self;
}

- (id)first {
    return [self.aggregate firstObject];
}

- (id)next {
    id ret = nil;
    self.current++;
    if(self.current < self.aggregate.count) {
        ret = [self.aggregate objectAtIndex:self.current];
    }
    return ret;
}

- (BOOL)isDone {
    if (!self.aggregate || [self.aggregate count] == 0) {
        return true;
    }
    return self.current >= self.aggregate.count ? true : false;
}

- (id)currentItem {
    return [self.aggregate objectAtIndex:self.current];
}

@end
