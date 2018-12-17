//
//  IFactory.h
//  factory
//
//  Created by 王俊 on 2018/12/17.
//  Copyright © 2018 王俊. All rights reserved.
//

#ifndef IFactory_h
#define IFactory_h

@protocol IFactory <NSObject>

@required
- (nonnull id<IFactory>)createLeiFeng;

@end

#endif /* IFactory_h */
