//
//  GiveGift.h
//  proxy
//
//  Created by 王俊 on 2018/12/17.
//  Copyright © 2018 王俊. All rights reserved.
//

#ifndef GiveGift_h
#define GiveGift_h


@protocol GiveGift <NSObject>

@required
- (void)giveDolls;
- (void)giveFlowers;
- (void)giveChocolate;


@end

#endif /* GiveGift_h */
