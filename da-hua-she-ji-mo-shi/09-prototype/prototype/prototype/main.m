//
//  main.m
//  prototype
//
//  Created by 王俊 on 2018/12/17.
//  Copyright © 2018 王俊. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "prototype/Resume.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
//        NSLog(@"Hello, World!");
        
        Resume *resumeA = [[Resume alloc] initWithName:@"大鸟"];
        [resumeA setPersonalInfoWithSex:@"男" andAge:29];
        [resumeA setWorkExperienceWithTimeArea:@"2010-2018" andCompany:@"xxx公司"];
        
        
        Resume *resumeB = [resumeA copy];
        [resumeB setPersonalInfoWithSex:@"男" andAge:24];
        
        
        Resume *resumeC = [resumeB copy];
        [resumeC setWorkExperienceWithTimeArea:@"2010-2018" andCompany:@"YYY公司"];
        
        
        [resumeA display];
        [resumeB display];
        [resumeC display];
        
    }
    return 0;
}
