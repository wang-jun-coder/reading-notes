//
//  ForeignCenter.h
//  adapter
//
//  Created by 王俊 on 2018/12/26.
//  Copyright © 2018 王俊. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ForeignCenter : NSObject

@property (nonatomic, copy) NSString *name;
- (void)jinGong;
- (void)fangShou;

@end

NS_ASSUME_NONNULL_END
