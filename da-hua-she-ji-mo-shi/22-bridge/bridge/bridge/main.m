//
//  main.m
//  bridge
//
//  Created by 王俊 on 2019/1/9.
//  Copyright © 2019 王俊. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "./bridge/HandsetGame.h"
#import "./bridge/HandsetAddressList.h"
#import "./bridge/HandsetMp3.h"

#import "./bridge/HandsetBrandN.h"
#import "./bridge/HandsetBrandM.h"
#import "./bridge/HandsetBrandS.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
//        NSLog(@"Hello, World!");
        
        id<HandsetBrand> ab;
        
        ab = [HandsetBrandN new];
        ab.soft = [HandsetGame new];
        [ab run];
        
        ab.soft = [HandsetAddressList new];
        [ab run];
        
        ab.soft = [HandsetMp3 new];
        [ab run];
        
        
        ab = [HandsetBrandM new];
        ab.soft = [HandsetGame new];
        [ab run];
        
        ab.soft = [HandsetAddressList new];
        [ab run];
        
        ab.soft = [HandsetMp3 new];
        [ab run];
        
        
        ab = [HandsetBrandS new];
        ab.soft = [HandsetGame new];
        [ab run];
        
        ab.soft = [HandsetAddressList new];
        [ab run];
        
        ab.soft = [HandsetMp3 new];
        [ab run];
        
    }
    return 0;
}
