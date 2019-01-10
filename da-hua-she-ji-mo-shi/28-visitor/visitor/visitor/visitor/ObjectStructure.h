//
//  ObjectStructure.h
//  visitor
//
//  Created by 王俊 on 2019/1/10.
//  Copyright © 2019 王俊. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Person.h"
#import "Action.h"

NS_ASSUME_NONNULL_BEGIN

@interface ObjectStructure : NSObject

- (void)attach:(id<Person>)person;
- (void)detach:(id<Person>)person;

- (void)display:(id<Action>)visitor;

@end

NS_ASSUME_NONNULL_END
