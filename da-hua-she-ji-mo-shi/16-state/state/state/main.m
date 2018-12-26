//
//  main.m
//  state
//
//  Created by 王俊 on 2018/12/26.
//  Copyright © 2018 王俊. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "./state/Work.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
//        NSLog(@"Hello, World!");
        
        Work *emergencyProjects = [Work new];
        
        emergencyProjects.hour = 9;
        [emergencyProjects writeProgram];
        
        emergencyProjects.hour = 10;
        [emergencyProjects writeProgram];
        
        emergencyProjects.hour = 12;
        [emergencyProjects writeProgram];
        
        emergencyProjects.hour = 13;
        [emergencyProjects writeProgram];
        
        emergencyProjects.hour = 14;
        [emergencyProjects writeProgram];
        
        emergencyProjects.hour = 17;
        [emergencyProjects writeProgram];
        
//        emergencyProjects.taskFinished = true;
        emergencyProjects.taskFinished = false;
        
        emergencyProjects.hour = 19;
        [emergencyProjects writeProgram];
        
        emergencyProjects.hour = 22;
        [emergencyProjects writeProgram];
        
    }
    return 0;
}
