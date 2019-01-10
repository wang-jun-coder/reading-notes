//
//  Expression.h
//  interpreter
//
//  Created by 王俊 on 2019/1/10.
//  Copyright © 2019 王俊. All rights reserved.
//

#ifndef Expression_h
#define Expression_h

@class PlayContext;
@protocol Expression <NSObject>

@required
- (void)interpreter:(PlayContext *)context;
- (void)excuteWithKey:(NSString *)key andValue:(CGFloat)value;
@end

#endif /* Expression_h */
