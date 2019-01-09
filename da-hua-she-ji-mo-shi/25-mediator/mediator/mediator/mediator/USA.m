//
//  USA.m
//  mediator
//
//  Created by 王俊 on 2019/1/9.
//  Copyright © 2019 王俊. All rights reserved.
//

#import "USA.h"
#import "./UnitedNations.h"


@implementation USA
@synthesize mediator;

- (id<Country>)initWithUN:(id<UnitedNations>)mediator {
    self = [super init];
    if (self) {
        self.mediator = mediator;
    }
    return self;
}

- (void)declare:(NSString *)message {
    [self.mediator declar:message country:self];
}

- (void)getMessage:(NSString *)message {
    NSLog(@"美国获得对方消息: %@", message);
}

@end
