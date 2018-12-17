//
//  Proxy.m
//  proxy
//
//  Created by 王俊 on 2018/12/17.
//  Copyright © 2018 王俊. All rights reserved.
//

#import "Proxy.h"
#import "Pursuit.h"

@interface Proxy ()

@property (nonatomic, strong) Pursuit *pursuit;

@end

@implementation Proxy

#pragma mark - life cycle
- (instancetype)initWithSchoolGirl:(SchoolGirl *)girl {
    self = [super init];
    if (self) {
        self.pursuit = [[Pursuit alloc] initWithSchoolGirl:girl];
    }
    return self;
}

#pragma mark - GiveGift
- (void)giveDolls {
    [self.pursuit giveDolls];
}
- (void)giveFlowers {
    [self.pursuit giveFlowers];
}
- (void)giveChocolate {
    [self.pursuit giveChocolate];
}



@end
