//
//  WebSiteFactory.h
//  flyweight
//
//  Created by 王俊 on 2019/1/10.
//  Copyright © 2019 王俊. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ConcreteWebSite.h"

NS_ASSUME_NONNULL_BEGIN

@interface WebSiteFactory : NSObject

- (id<WebSite>)getWebSiteCategory:(ConcreteWebSiteKind)kind;

- (NSInteger)getWebSiteCount;

@end

NS_ASSUME_NONNULL_END
