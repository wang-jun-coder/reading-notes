//
//  Person.h
//  delegate
//
//  Created by 王俊 on 2018/12/17.
//  Copyright © 2018 王俊. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class Person;
@protocol GiveGift <NSObject>

@required
// 帮助某人赠送礼物给某人
- (void)helperPerson:(Person *)giver giveDollsTo:(Person *)receiver;
- (void)helperPerson:(Person *)giver giveFlowersTo:(Person *)receiver;
- (void)helperPerson:(Person *)giver giveChocolateTo:(Person *)receiver;

@end

@interface Person : NSObject<GiveGift>

@property(nonatomic, assign) id<GiveGift>delegate;

- (instancetype)initWithName:(NSString *)name;


// 每个人都有赠送某人礼物的方法(此处不直接赠送, 而是委托代理人赠送)
- (void)giveDollsToPerson:(Person *)person;
- (void)giveFlowersToPerson:(Person *)person;
- (void)giveChocolateToPerson:(Person *)person;

@end

NS_ASSUME_NONNULL_END
