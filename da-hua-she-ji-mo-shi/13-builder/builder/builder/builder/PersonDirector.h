//
//  PersonDirector.h
//  builder
//
//  Created by 王俊 on 2018/12/18.
//  Copyright © 2018 王俊. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PersonBuilder.h"

NS_ASSUME_NONNULL_BEGIN

@interface PersonDirector : NSObject

- (instancetype)initWithBuilder:(id<PersonBuilder>)builder;

- (void)buildPerson;

@end

NS_ASSUME_NONNULL_END
