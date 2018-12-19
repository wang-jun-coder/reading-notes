//
//  Subject.h
//  observer
//
//  Created by 王俊 on 2018/12/19.
//  Copyright © 2018 王俊. All rights reserved.
//

#ifndef Subject_h
#define Subject_h

#import "Observer.h"

@protocol Subject <NSObject>

@required

@property (nonatomic, copy) NSString *state;

- (void)attach:(nonnull id<Observer>)observer;
- (void)detach:(nonnull id<Observer>)observer;
- (void)notify;


@end


#endif /* Subject_h */
