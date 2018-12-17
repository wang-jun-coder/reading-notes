//
//  SchoolGirl.m
//  proxy
//
//  Created by 王俊 on 2018/12/17.
//  Copyright © 2018 王俊. All rights reserved.
//

#import "SchoolGirl.h"

@interface SchoolGirl ()
@property (nonatomic, copy, readwrite) NSString *name;
@end

@implementation SchoolGirl

- (instancetype)initWithName:(NSString *)name {
    self = [super init];
    if (self) {
        self.name = name;
    }
    return self;
}

@end
