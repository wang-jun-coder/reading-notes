//
//  Forwards.m
//  adapter
//
//  Created by 王俊 on 2018/12/26.
//  Copyright © 2018 王俊. All rights reserved.
//

#import "Forwards.h"

@implementation Forwards
@synthesize name;

- (id<Player>)initWithName:(NSString *)name {
    self = [super init];
    if (self) {
        self.name = name;
    }
    return self;
}

- (void)attack {
    NSLog(@"前锋 %@ 进攻", self.name);
}
- (void)defense {
    NSLog(@"前锋 %@ 防守", self.name);
}

@end
