//
//  BakeChickenWingCommand.m
//  command
//
//  Created by 王俊 on 2019/1/9.
//  Copyright © 2019 王俊. All rights reserved.
//

#import "BakeChickenWingCommand.h"
#import "./Barbecuer.h"

@interface BakeChickenWingCommand ()

@property (nonatomic, strong) Barbecuer *barbecuer;

@end

@implementation BakeChickenWingCommand
- (id<Command>)initWithBarbecuer:(Barbecuer *)barbecuer {
    self = [super init];
    if (self) {
        self.barbecuer = barbecuer;
    }
    return self;
}

- (void)excuteCommand {
    [self.barbecuer bakeChickenWing];
}

- (NSString *)description {
    return @"烤鸡翅";
}

@end
