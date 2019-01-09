//
//  GeneralManager.m
//  chain-of-responsibility
//
//  Created by 王俊 on 2019/1/9.
//  Copyright © 2019 王俊. All rights reserved.
//

#import "GeneralManager.h"
#import "Request.h"

@implementation GeneralManager
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
    if (request.type == RequestTypeLeave) {
        NSLog(@"%@: %@  数量%li 被批准", self.name, request.content, (long)request.number);
    } else if (request.type == RequestTypeRaises && request.number <= 500){
        NSLog(@"%@: %@  数量%li 被批准", self.name, request.content, (long)request.number);
    } else if (request.type == RequestTypeRaises && request.number > 500) {
        NSLog(@"%@: %@  数量%li 再说吧", self.name, request.content, (long)request.number);
    }
}
@end
