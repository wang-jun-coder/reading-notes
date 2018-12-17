//
//  Pursuit.m
//  proxy
//
//  Created by 王俊 on 2018/12/17.
//  Copyright © 2018 王俊. All rights reserved.
//

#import "Pursuit.h"

@interface Pursuit ()
@property (nonatomic, strong) SchoolGirl *girl;

@end

@implementation Pursuit

#pragma mark - life cycle
- (instancetype)initWithSchoolGirl:(SchoolGirl *)girl {
    self = [super init];
    if (self) {
        self.girl = girl;
    }
    return self;
}

#pragma mark - GiveGift
- (void)giveDolls {
    NSLog(@"give %@ dolls", self.girl.name);
}
- (void)giveFlowers {
    NSLog(@"give %@ flowers", self.girl.name);
}
- (void)giveChocolate {
    NSLog(@"give %@ chocolate", self.girl.name);
}

@end
