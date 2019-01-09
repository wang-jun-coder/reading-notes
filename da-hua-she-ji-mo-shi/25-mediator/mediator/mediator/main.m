//
//  main.m
//  mediator
//
//  Created by 王俊 on 2019/1/9.
//  Copyright © 2019 王俊. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "./mediator/UNSecurityCouncli.h"
#import "./mediator/USA.h"
#import "./mediator/Iraq.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
//        NSLog(@"Hello, World!");
        
        UNSecurityCouncli *UNSC = [UNSecurityCouncli new];
        
        USA *usa = [[USA alloc] initWithUN:UNSC];
        Iraq *iraq = [[Iraq alloc] initWithUN:UNSC];
        
        UNSC.usa = usa;
        UNSC.iraq = iraq;
        
        [usa declare:@"不准研制核武器, 否则发动战争!"];
        [iraq declare:@"我们没有核武器, 也不怕侵略."];
        
    }
    return 0;
}
