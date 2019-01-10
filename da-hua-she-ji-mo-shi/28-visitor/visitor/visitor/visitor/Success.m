//
//  Success.m
//  visitor
//
//  Created by 王俊 on 2019/1/10.
//  Copyright © 2019 王俊. All rights reserved.
//

#import "Success.h"
#import "Man.h"
#import "Woman.h"

@implementation Success

- (void)getManConclusion:(Man *)man {
    NSLog(@"男人成功时, 背后多半有一个伟大的女人");
}

- (void)getWomanConclusion:(Woman *)woman {
    NSLog(@"女人成功时, 背后多半有一个不成功的男人");
}

@end
