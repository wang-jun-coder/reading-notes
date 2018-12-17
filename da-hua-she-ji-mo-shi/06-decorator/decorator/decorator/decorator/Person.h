//
//  Person.h
//  decorator
//
//  Created by 王俊 on 2018/12/17.
//  Copyright © 2018 王俊. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Person : NSObject

- (instancetype)initWithName:(NSString *)name;

- (void)show;

@end

NS_ASSUME_NONNULL_END
