//
//  Iterator.h
//  iterator
//
//  Created by 王俊 on 2018/12/28.
//  Copyright © 2018 王俊. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Iterator.h"

@protocol Aggregate;
NS_ASSUME_NONNULL_BEGIN

@interface ConcreteIterator : NSObject<Iterator>

- (instancetype)initWithAggregate:(id<Aggregate>)aggregate;

@end

NS_ASSUME_NONNULL_END
