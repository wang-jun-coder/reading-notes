//
//  Pursuit.h
//  proxy
//
//  Created by 王俊 on 2018/12/17.
//  Copyright © 2018 王俊. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GiveGift.h"
#import "SchoolGirl.h"

NS_ASSUME_NONNULL_BEGIN

@interface Pursuit : NSObject<GiveGift>

- (instancetype)initWithSchoolGirl:(SchoolGirl *)girl;

@end

NS_ASSUME_NONNULL_END
