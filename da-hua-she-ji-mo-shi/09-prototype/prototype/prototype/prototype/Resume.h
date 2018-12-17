//
//  Resume.h
//  prototype
//
//  Created by 王俊 on 2018/12/17.
//  Copyright © 2018 王俊. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Resume : NSObject<NSCopying>

- (instancetype)initWithName:(NSString *)name;

- (void)setPersonalInfoWithSex:(NSString *)sex andAge:(NSUInteger)age;

- (void)setWorkExperienceWithTimeArea:(NSString *)timeArea andCompany:(NSString *)company;

- (void)display;

@end

NS_ASSUME_NONNULL_END
