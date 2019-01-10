//
//  ConcreteWebsite.m
//  flyweight
//
//  Created by 王俊 on 2019/1/10.
//  Copyright © 2019 王俊. All rights reserved.
//

#import "ConcreteWebSite.h"
#import "User.h"

ConcreteWebSiteKind ConcreteWebSiteKindProductDisplay = @"产品展示";
ConcreteWebSiteKind ConcreteWebSiteKindBlog = @"博客";

@implementation ConcreteWebSite

- (instancetype)initWithKind:(ConcreteWebSiteKind)kind {
    self = [super init];
    if (self) {
        self.kind = kind;
    }
    return self;
}

- (void)use:(User *)user {
    NSLog(@"网站分类: %@ 用户: %@", self.kind, user.name);
    
}


@end
