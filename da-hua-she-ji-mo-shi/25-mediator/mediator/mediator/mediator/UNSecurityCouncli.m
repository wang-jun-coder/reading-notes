//
//  UNSecurityCouncli.m
//  mediator
//
//  Created by 王俊 on 2019/1/9.
//  Copyright © 2019 王俊. All rights reserved.
//

#import "UNSecurityCouncli.h"

@implementation UNSecurityCouncli

- (void)declar:(NSString *)message country:(id<Country>)country {
    if (country == self.usa) {
        [self.iraq getMessage:message];
    } else {
        [self.usa getMessage:message];
    }
}

@end
