//
//  ConcreteWebsite.h
//  flyweight
//
//  Created by 王俊 on 2019/1/10.
//  Copyright © 2019 王俊. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "./WebSite.h"

NS_ASSUME_NONNULL_BEGIN

typedef NSString * ConcreteWebSiteKind NS_EXTENSIBLE_STRING_ENUM;
FOUNDATION_EXTERN ConcreteWebSiteKind ConcreteWebSiteKindProductDisplay;
FOUNDATION_EXTERN ConcreteWebSiteKind ConcreteWebSiteKindBlog;

@interface ConcreteWebSite : NSObject<WebSite>

@property (nonatomic, copy) NSString *kind;

- (instancetype)initWithKind:(ConcreteWebSiteKind)kind;

@end

NS_ASSUME_NONNULL_END
