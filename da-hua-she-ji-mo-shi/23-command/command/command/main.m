//
//  main.m
//  command
//
//  Created by 王俊 on 2019/1/9.
//  Copyright © 2019 王俊. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "./command/Barbecuer.h"
#import "./command/Waiter.h"
#import "./command/BakeMuttonCommand.h"
#import "./command/BakeChickenWingCommand.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
//        NSLog(@"Hello, World!");
        
        Barbecuer *boy = [Barbecuer new];
        id<Command> bakeMuttonCmd1 = [[BakeMuttonCommand alloc] initWithBarbecuer:boy];
        id<Command> bakeMuttonCmd2 = [[BakeMuttonCommand alloc] initWithBarbecuer:boy];
        id<Command> bakeMuttonCmd3 = [[BakeMuttonCommand alloc] initWithBarbecuer:boy];
        id<Command> bakeChickenWing = [[BakeChickenWingCommand alloc] initWithBarbecuer:boy];
        
        Waiter *girl = [Waiter new];
        
        [girl setOrder:bakeMuttonCmd1];
        [girl setOrder:bakeMuttonCmd2];
        [girl setOrder:bakeMuttonCmd3];
        [girl setOrder:bakeChickenWing];
        
        [girl cancelOrder:bakeMuttonCmd3];
        [girl notify];
        
        
    }
    return 0;
}
