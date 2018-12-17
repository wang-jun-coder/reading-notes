//
//  Person.m
//  decorator
//
//  Created by 王俊 on 2018/12/17.
//  Copyright © 2018 王俊. All rights reserved.
//

#import "Person.h"

@interface Person ()

@property (nonatomic, copy) NSString *name;

@end


@implementation Person

- (instancetype)initWithName:(NSString *)name {
    self = [super init];
    if (self) {
        self.name = name;
    }
    return self;
}

- (void)show {
    NSLog(@"my name is %@", self.name);
}

@end
