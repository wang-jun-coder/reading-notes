//
//  Majordomo.m
//  chain-of-responsibility
//
//  Created by 王俊 on 2019/1/9.
//  Copyright © 2019 王俊. All rights reserved.
//

#import "Majordomo.h"
#import "Request.h"

@implementation Majordomo
@synthesize name;
@synthesize superior;

- (id<Manager>)initWithName:(NSString *)name {
    self = [super init];
    if (self) {
        self.name = name;
    }
    return self;
}

- (void)requestApplications:(Request *)request {
    if (request.type == RequestTypeLeave && request.number <=5) {
        NSLog(@"%@: %@  数量%li 被批准", self.name, request.content, (long)request.number);
    } else {
        if (self.superior) 
        [self.superior requestApplications:request];
    }
}

@end
