//
//  ObjectStructure.m
//  visitor
//
//  Created by 王俊 on 2019/1/10.
//  Copyright © 2019 王俊. All rights reserved.
//

#import "ObjectStructure.h"

@interface ObjectStructure ()

@property (nonatomic, strong) NSMutableArray <id<Person>>* persons;

@end
@implementation ObjectStructure

- (void)attach:(id<Person>)person {
    [self.persons addObject:person];
}
- (void)detach:(id<Person>)person {
    [self.persons removeObject:person];
}
- (void)display:(id<Action>)visitor {
    for (id<Person> p in self.persons) {
        [p accept:visitor];
    }
}

#pragma mark - getters && setters
- (NSMutableArray<id<Person>> *)persons {
    if (!_persons) {
        _persons = [NSMutableArray array];
    }
    return _persons;
}

@end
