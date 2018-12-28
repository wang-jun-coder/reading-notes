//
//  ConcreteAggregate.m
//  iterator
//
//  Created by 王俊 on 2018/12/28.
//  Copyright © 2018 王俊. All rights reserved.
//

#import "ConcreteAggregate.h"
#import "ConcreteIterator.h"


@interface ConcreteAggregate ()

@property (nonatomic, strong) NSMutableArray *array;

@end


@implementation ConcreteAggregate

- (instancetype)init {
    self = [super init];
    if (self) {
        _array = [NSMutableArray array];
    }
    return self;
}

- (id<Iterator>)createIterator {
    ConcreteIterator *iterator = [[ConcreteIterator alloc] initWithAggregate:self];
    return iterator;
}

- (NSUInteger)count {
    return self.array.count;
}

- (id)firstObject {
    return self.array.firstObject;
}
- (void)addObject:(id)anObject {
    return [self.array addObject:anObject];
}
- (id)objectAtIndex:(NSUInteger)index {
    return [self.array objectAtIndex:index];
}




@end
