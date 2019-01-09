//
//  UnitedNations.h
//  mediator
//
//  Created by 王俊 on 2019/1/9.
//  Copyright © 2019 王俊. All rights reserved.
//

#ifndef UnitedNations_h
#define UnitedNations_h
#import "./Country.h"

@protocol UnitedNations <NSObject>

@required
- (void)declar:(NSString *)message country:(id<Country>)country;

@end


#endif /* UnitedNations_h */
