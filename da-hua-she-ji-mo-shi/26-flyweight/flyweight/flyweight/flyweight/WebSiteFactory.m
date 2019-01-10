//
//  WebSiteFactory.m
//  flyweight
//
//  Created by 王俊 on 2019/1/10.
//  Copyright © 2019 王俊. All rights reserved.
//

#import "WebSiteFactory.h"

@interface WebSiteFactory ()

@property (nonatomic, strong) NSMutableDictionary<ConcreteWebSiteKind,ConcreteWebSite*> *flyweights;

@end

@implementation WebSiteFactory

- (id<WebSite>)getWebSiteCategory:(ConcreteWebSiteKind)kind {
    id<WebSite> ws = [self.flyweights objectForKey:kind];
    if (!ws) {
        ws = [[ConcreteWebSite alloc] initWithKind:kind];
        [self.flyweights setObject:ws forKey:kind];
    }
    return ws;
}

- (NSInteger)getWebSiteCount {
    return [self.flyweights allKeys].count;
}

#pragma mark - getters && setters
- (NSMutableDictionary<ConcreteWebSiteKind,ConcreteWebSite *> *)flyweights {
    if (!_flyweights) {
        _flyweights =  [NSMutableDictionary dictionary];
    }
    return _flyweights;
}

@end
