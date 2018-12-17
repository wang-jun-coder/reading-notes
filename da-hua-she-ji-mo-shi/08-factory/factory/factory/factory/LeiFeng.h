//
//  LeiFeng.h
//  factory
//
//  Created by 王俊 on 2018/12/17.
//  Copyright © 2018 王俊. All rights reserved.
//

#ifndef LeiFeng_h
#define LeiFeng_h

@protocol LeiFeng <NSObject>

@required
- (void)sweep;
- (void)wash;
- (void)buyRice;

@end

#endif /* LeiFeng_h */
