//
//  TestPaper.m
//  template
//
//  Created by 王俊 on 2018/12/17.
//  Copyright © 2018 王俊. All rights reserved.
//

#import "TestPaper.h"

@implementation TestPaper

- (void)testQuestion1 {
    NSLog(@"杨过得到, 后来给了郭靖,练成倚天剑、屠龙刀的玄铁可能是[]\nA. 球墨铸铁. \nB. 马口铁. \nC. 高速合金钢. \nD. 碳素纤维. \n答案: %@", [self anser1]);
}

- (void)testQuestion2 {
    NSLog(@"杨过,程英,k陆无双铲除了无情花,造成 []\nA. 这种植物不再害人. \nB. 一种珍稀物种灭绝. \nC. 破坏了那个生物圈的生态平衡. \nD. 该地区沙漠化. \n答案: %@", [self anser2]);
}

- (void)testQuestion3 {
    NSLog(@"蓝凤凰造成华山师徒,桃谷六仙呕吐不止,如果你是大夫,你会给他们开什么药?[]\nA. 阿司匹林. \nB. 牛黄解毒片. \nC. 让他们喝大量的生牛奶. \nD. 以上都不对. \n答案: %@", [self anser3]);
}


#pragma mark - for overwrite
- (NSString *)anser1 {
    NSAssert(NO, @"本方法应由子类重写");
    return nil;
}
- (NSString *)anser2 {
    NSAssert(NO, @"本方法应由子类重写");
    return nil;
}
- (NSString *)anser3 {
    NSAssert(NO, @"本方法应由子类重写");
    return nil;
}



@end
