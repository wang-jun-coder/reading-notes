//
//  User.h
//  abstract-factory
//
//  Created by 王俊 on 2018/12/19.
//  Copyright © 2018 王俊. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface User : NSObject

@property (nonatomic, strong) NSNumber *ID;
@property (nonatomic, copy) NSString *name;

@end

NS_ASSUME_NONNULL_END
