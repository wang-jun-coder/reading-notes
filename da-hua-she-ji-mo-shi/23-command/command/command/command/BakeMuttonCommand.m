//
//  BakeMuttonCommand.m
//  command
//
//  Created by 王俊 on 2019/1/9.
//  Copyright © 2019 王俊. All rights reserved.
//

#import "BakeMuttonCommand.h"
#import "./Barbecuer.h"

@interface BakeMuttonCommand ()
@property (nonatomic, strong) Barbecuer *barbecuer;

@end

@implementation BakeMuttonCommand

- (id<Command>)initWithBarbecuer:(Barbecuer *)barbecuer {
    self = [super init];
    if (self) {
        self.barbecuer = barbecuer;
    }
    return self;
}

- (void)excuteCommand {
    [self.barbecuer bakeMutton];
}

- (NSString *)description {
    return @"烤羊肉串";
}

@end
