//
//  Finery.h
//  decorator
//
//  Created by 王俊 on 2018/12/17.
//  Copyright © 2018 王俊. All rights reserved.
//

#import "Person.h"

NS_ASSUME_NONNULL_BEGIN

@interface Finery : Person

@property (nonatomic, strong, readonly) Person *person;

- (instancetype)initWithPerson:(Person *)person;

@end

NS_ASSUME_NONNULL_END
