//
//  VolunteerFactory.m
//  factory
//
//  Created by 王俊 on 2018/12/17.
//  Copyright © 2018 王俊. All rights reserved.
//

#import "VolunteerFactory.h"
#import "Volunteer.h"

@implementation VolunteerFactory

- (id<LeiFeng>)createLeiFeng {
    id<LeiFeng> leifeng = [[Volunteer alloc] init];
    return leifeng;
}

@end
