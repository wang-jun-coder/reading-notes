//
//  main.m
//  proxy
//
//  Created by 王俊 on 2018/12/17.
//  Copyright © 2018 王俊. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "proxy/SchoolGirl.h"
#import "proxy/Proxy.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
//        NSLog(@"Hello, World!");
        
        SchoolGirl *jiaojiao = [[SchoolGirl alloc] initWithName:@"娇娇"];
        
        Proxy *daili = [[Proxy alloc] initWithSchoolGirl:jiaojiao];
        [daili giveDolls];
        [daili giveFlowers];
        [daili giveChocolate];
        
    }
    return 0;
}
