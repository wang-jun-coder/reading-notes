//
//  UndergraduateFactory.m
//  factory
//
//  Created by 王俊 on 2018/12/17.
//  Copyright © 2018 王俊. All rights reserved.
//

#import "UndergraduateFactory.h"
#import "Undergraduate.h"

@implementation UndergraduateFactory
- (id)createLeiFeng {
    id<LeiFeng> leifeng = [[Undergraduate alloc] init];
    return leifeng;
}
@end
