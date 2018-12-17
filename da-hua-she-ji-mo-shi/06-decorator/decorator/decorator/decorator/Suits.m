//
//  Suit.m
//  decorator
//
//  Created by 王俊 on 2018/12/17.
//  Copyright © 2018 王俊. All rights reserved.
//

#import "Suits.h"

@implementation Suits

- (void)show {
    [self.person show];
    NSLog(@"wear suits");
}

@end
