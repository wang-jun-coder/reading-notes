//
//  StockObserver.h
//  observer
//
//  Created by 王俊 on 2018/12/19.
//  Copyright © 2018 王俊. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Observer.h"
#import "Subject.h"

NS_ASSUME_NONNULL_BEGIN

@interface StockObserver : NSObject <Observer>

- (instancetype)initWithName:(NSString *)name;

@end

NS_ASSUME_NONNULL_END
