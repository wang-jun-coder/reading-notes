//
//  HRDepartment.m
//  composite
//
//  Created by 王俊 on 2018/12/27.
//  Copyright © 2018 王俊. All rights reserved.
//

#import "HRDepartment.h"

@implementation HRDepartment
@synthesize name;

- (id<Company>)initWithName:(NSString *)name {
    self = [super init];
    if (self) {
        self.name = name;
    }
    return self;
}

- (void)addCompany:(id<Company>)company {
    NSAssert(false, @"叶节点, 不能加子节点");
}
- (void)removeCompany:(id<Company>)company {
    NSAssert(false, @"叶节点, 不能移除子节点");
}

- (void)display:(NSInteger)depth {
    NSMutableString *display = [NSMutableString string];
    while (depth>0) {
        [display appendString:@"-"];
        depth--;
    }
    [display appendString:self.name];
    NSLog(@"%@", display);
}

- (void)lineOfDuty {
    NSLog(@"%@ 员工招聘培训管理", self.name);
}

@end
