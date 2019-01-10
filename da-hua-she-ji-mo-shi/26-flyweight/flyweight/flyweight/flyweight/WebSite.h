//
//  Website.h
//  flyweight
//
//  Created by 王俊 on 2019/1/10.
//  Copyright © 2019 王俊. All rights reserved.
//

#ifndef Website_h
#define Website_h

@class User;

@protocol WebSite <NSObject>

@required
- (void)use:(User *)user;

@end

#endif /* Website_h */
