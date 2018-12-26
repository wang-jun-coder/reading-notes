//
//  main.m
//  adapter
//
//  Created by 王俊 on 2018/12/26.
//  Copyright © 2018 王俊. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "./adapter/Forwards.h"
#import "./adapter/Center.h"
#import "./adapter/Guards.h"
#import "./adapter/ForeignCenter.h"
#import "./adapter/Translator.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
//        NSLog(@"Hello, World!");
        id<Player> b = [[Forwards alloc] initWithName:@"巴蒂尔"];
        [b attack];
        
        id<Player> m = [[Guards alloc] initWithName:@"麦克格雷迪"];
        [m attack];
        
        id<Player> ym = [[Translator alloc] initWithName:@"姚明"];
        [ym attack];
        [ym defense];
        
    }
    return 0;
}
