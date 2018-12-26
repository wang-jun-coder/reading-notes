//
//  Work.h
//  state
//
//  Created by 王俊 on 2018/12/26.
//  Copyright © 2018 王俊. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "State.h"

NS_ASSUME_NONNULL_BEGIN


@interface Work : NSObject

@property (nonatomic, strong) id<State>state;
@property (nonatomic, assign) double hour;
@property (nonatomic, assign) BOOL taskFinished;

- (void)writeProgram;
@end

NS_ASSUME_NONNULL_END
