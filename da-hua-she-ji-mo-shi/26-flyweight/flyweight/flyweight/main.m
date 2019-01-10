//
//  main.m
//  flyweight
//
//  Created by 王俊 on 2019/1/10.
//  Copyright © 2019 王俊. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "./flyweight/WebSiteFactory.h"
#import "./flyweight/User.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
//        NSLog(@"Hello, World!");
        WebSiteFactory *f = [WebSiteFactory new];
        
        id<WebSite> fx = [f getWebSiteCategory:ConcreteWebSiteKindProductDisplay];
        [fx use:[[User alloc] initWithName:@"小菜"]];
        
        id<WebSite> fy = [f getWebSiteCategory:ConcreteWebSiteKindProductDisplay];
        [fy use:[[User alloc] initWithName:@"大鸟"]];
        
        id<WebSite> fz = [f getWebSiteCategory:ConcreteWebSiteKindProductDisplay];
        [fz use:[[User alloc] initWithName:@"娇娇"]];
        
        
        id<WebSite> fl = [f getWebSiteCategory:ConcreteWebSiteKindBlog];
        [fl use:[[User alloc] initWithName:@"老顽童"]];
        
        id<WebSite> fm = [f getWebSiteCategory:ConcreteWebSiteKindBlog];
        [fm use:[[User alloc] initWithName:@"桃谷六仙"]];
        
        id<WebSite> fn = [f getWebSiteCategory:ConcreteWebSiteKindBlog];
        [fn use:[[User alloc] initWithName:@"南海鳄神"]];
        
        
        NSLog(@"得到网站分类总数为: %ld", [f getWebSiteCount]);
    }
    return 0;
}
