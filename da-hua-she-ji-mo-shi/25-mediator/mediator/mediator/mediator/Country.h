//
//  Country.h
//  mediator
//
//  Created by 王俊 on 2019/1/9.
//  Copyright © 2019 王俊. All rights reserved.
//

#ifndef Country_h
#define Country_h

@protocol UnitedNations;
@protocol Country <NSObject>

@required
@property (nonatomic, strong) id<UnitedNations> mediator;
- (id<Country>)initWithUN:(id<UnitedNations>)mediator;

- (void)declare:(NSString *)message;
- (void)getMessage:(NSString *)message;

@end

#endif /* Country_h */
