//
//  ExpressionFactory.m
//  interpreter
//
//  Created by 王俊 on 2019/1/10.
//  Copyright © 2019 王俊. All rights reserved.
//

#import "ExpressionFactory.h"
#import "Note.h"
#import "Scale.h"
#import "Speed.h"

ExpressionKey ExpressionKeyO = @"O";
ExpressionKey ExpressionKeyP = @"P";
ExpressionKey ExpressionKeyT = @"T";
ExpressionKey ExpressionKeyC = @"C";
ExpressionKey ExpressionKeyD = @"D";
ExpressionKey ExpressionKeyE = @"E";
ExpressionKey ExpressionKeyF = @"F";
ExpressionKey ExpressionKeyG = @"G";
ExpressionKey ExpressionKeyA = @"A";
ExpressionKey ExpressionKeyB = @"B";

@implementation ExpressionFactory

- (id<Expression>)createExpressionWithKey:(_Nonnull ExpressionKey)key {
    NSDictionary *expressKeyDic = @{ExpressionKeyO: [Scale class],
                                    ExpressionKeyT: [Speed class],
                                    ExpressionKeyC: [Note class],
                                    ExpressionKeyD: [Note class],
                                    ExpressionKeyE: [Note class],
                                    ExpressionKeyF: [Note class],
                                    ExpressionKeyG: [Note class],
                                    ExpressionKeyA: [Note class],
                                    ExpressionKeyB: [Note class],
                                    ExpressionKeyP: [Note class],
                                    };
    Class cls = [expressKeyDic objectForKey:key];
    if (!cls) return nil;
    return [cls new];
}

@end
