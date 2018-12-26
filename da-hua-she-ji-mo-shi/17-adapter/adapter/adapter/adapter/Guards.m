//
//  Guards.m
//  adapter
//
//  Created by 王俊 on 2018/12/26.
//  Copyright © 2018 王俊. All rights reserved.
//

#import "Guards.h"

@implementation Guards
@synthesize name;

- (id<Player>)initWithName:(NSString *)name {
    self = [super init];
    if (self) {
        self.name = name;
    }
    return self;
}

- (void)attack {
    NSLog(@"后卫 %@ 进攻", self.name);
}
- (void)defense {
    NSLog(@"后卫 %@ 防守", self.name);
}
@end
