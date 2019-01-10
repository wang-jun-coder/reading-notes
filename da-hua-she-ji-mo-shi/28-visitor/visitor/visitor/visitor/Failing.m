//
//  Fail.m
//  visitor
//
//  Created by 王俊 on 2019/1/10.
//  Copyright © 2019 王俊. All rights reserved.
//

#import "Failing.h"

@implementation Failing


- (void)getManConclusion:(Man *)man {
    NSLog(@"男人失败时, 闷头喝酒, 谁也不用劝");
}

- (void)getWomanConclusion:(Woman *)woman {
    NSLog(@"女人失败时, 眼泪汪汪, 谁也劝不了");
}

@end
