//
//  Request.m
//  chain-of-responsibility
//
//  Created by 王俊 on 2019/1/9.
//  Copyright © 2019 王俊. All rights reserved.
//

#import "Request.h"

RequestType const RequestTypeLeave = @"请假";
RequestType const RequestTypeRaises = @"加薪";


@implementation Request

- (instancetype)initWithType:(RequestType)type content:(NSString *)content number:(NSInteger)number {
    self = [super init];
    if (self) {
        self.type = type;
        self.content = content;
        self.number = number;
    }
    return self;
}

@end
