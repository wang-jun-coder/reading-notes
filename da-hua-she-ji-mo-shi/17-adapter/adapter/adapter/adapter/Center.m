//
//  Center.m
//  adapter
//
//  Created by 王俊 on 2018/12/26.
//  Copyright © 2018 王俊. All rights reserved.
//

#import "Center.h"

@implementation Center
@synthesize name;

- (id<Player>)initWithName:(NSString *)name {
    self = [super init];
    if (self) {
        self.name = name;
    }
    return self;
}

- (void)attack {
    NSLog(@"中锋 %@ 进攻", self.name);
}
- (void)defense {
    NSLog(@"中锋 %@ 防守", self.name);
}

@end
