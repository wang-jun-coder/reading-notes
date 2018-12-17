//
//  Tie.m
//  decorator
//
//  Created by 王俊 on 2018/12/17.
//  Copyright © 2018 王俊. All rights reserved.
//

#import "Ties.h"

@implementation Ties

- (void)show {
    [self.person show];
    NSLog(@"wear ties");
}

@end
