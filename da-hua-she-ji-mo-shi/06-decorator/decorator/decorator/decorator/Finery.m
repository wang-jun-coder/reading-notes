//
//  Finery.m
//  decorator
//
//  Created by 王俊 on 2018/12/17.
//  Copyright © 2018 王俊. All rights reserved.
//

#import "Finery.h"

@interface Finery ()
@property (nonatomic, strong) Person *person;
@end

@implementation Finery

- (instancetype)initWithPerson:(Person *)person {
    self = [super init];
    if(self) {
        self.person = person;
    }
    return self;
}

- (void)show {
    [self.person show];
}


@end
