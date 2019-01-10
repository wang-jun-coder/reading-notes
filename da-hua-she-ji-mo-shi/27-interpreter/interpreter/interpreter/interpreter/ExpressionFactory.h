//
//  ExpressionFactory.h
//  interpreter
//
//  Created by 王俊 on 2019/1/10.
//  Copyright © 2019 王俊. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Expression.h"

NS_ASSUME_NONNULL_BEGIN

typedef NSString * ExpressionKey NS_EXTENSIBLE_STRING_ENUM;
FOUNDATION_EXTERN ExpressionKey ExpressionKeyO;
FOUNDATION_EXTERN ExpressionKey ExpressionKeyP;
FOUNDATION_EXTERN ExpressionKey ExpressionKeyT;
FOUNDATION_EXTERN ExpressionKey ExpressionKeyC;
FOUNDATION_EXTERN ExpressionKey ExpressionKeyD;
FOUNDATION_EXTERN ExpressionKey ExpressionKeyE;
FOUNDATION_EXTERN ExpressionKey ExpressionKeyF;
FOUNDATION_EXTERN ExpressionKey ExpressionKeyG;
FOUNDATION_EXTERN ExpressionKey ExpressionKeyA;
FOUNDATION_EXTERN ExpressionKey ExpressionKeyB;


@interface ExpressionFactory : NSObject

- (id<Expression>)createExpressionWithKey:(_Nonnull ExpressionKey)key;

@end

NS_ASSUME_NONNULL_END
