//
//  TestPaper.h
//  template
//
//  Created by 王俊 on 2018/12/17.
//  Copyright © 2018 王俊. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TestPaper : NSObject

// 模板
- (void)testQuestion1;
- (void)testQuestion2;
- (void)testQuestion3;

// 子类重写
- (NSString *)anser1;
- (NSString *)anser2;
- (NSString *)anser3;


@end

NS_ASSUME_NONNULL_END
