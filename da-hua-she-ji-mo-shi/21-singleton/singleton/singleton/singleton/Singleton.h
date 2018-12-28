//
//  Singleton.h
//  singleton
//
//  Created by 王俊 on 2018/12/28.
//  Copyright © 2018 王俊. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Singleton : NSObject<NSCopying>

@property (nonatomic, copy) NSString *name;

+ (instancetype)shareInstance;

@end

NS_ASSUME_NONNULL_END
