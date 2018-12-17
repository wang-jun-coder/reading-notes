//
//  Resume.m
//  prototype
//
//  Created by 王俊 on 2018/12/17.
//  Copyright © 2018 王俊. All rights reserved.
//

#import "Resume.h"
#import "WorkExperience.h"

@interface Resume ()

@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *sex;
@property (nonatomic, assign) NSUInteger age;
@property (nonatomic, strong) WorkExperience *work;

@end

@implementation Resume

#pragma mark - life cycle
- (instancetype)initWithName:(NSString *)name {
    if (self = [super init]) {
        self.name = name;
    }
    return self;
}

- (void)setPersonalInfoWithSex:(NSString *)sex andAge:(NSUInteger)age {
    self.sex = sex;
    self.age = age;
}

- (void)setWorkExperienceWithTimeArea:(NSString *)timeArea andCompany:(NSString *)company {
    self.work.timeArea = timeArea;
    self.work.company = company;
}

- (void)display {
    NSLog(@"\n姓名:%@\n性别:%@\n年龄:%lu\n工作经历:%@ %@", self.name, self.sex, (unsigned long)self.age, self.work.timeArea, self.work.company);
}

- (id)copyWithZone:(NSZone *)zone {
    Resume *copy = [[[self class] allocWithZone:zone] initWithName:self.name];
    [copy setPersonalInfoWithSex:self.sex andAge:self.age];
    [copy setWorkExperienceWithTimeArea:self.work.timeArea andCompany:self.work.company];
    
    return copy;
}

#pragma mark - getters && setters
- (WorkExperience *)work {
    if (!_work) {
        _work = [[WorkExperience alloc] init];
    }
    return _work;
}
@end
