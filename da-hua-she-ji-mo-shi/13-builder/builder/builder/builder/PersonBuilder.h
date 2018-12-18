//
//  PersonBuilder.h
//  builder
//
//  Created by 王俊 on 2018/12/17.
//  Copyright © 2018 王俊. All rights reserved.
//

#ifndef PersonBuilder_h
#define PersonBuilder_h

@protocol PersonBuilder <NSObject>

- (void)buildHead;
- (void)buildBody;
- (void)buildArmLeft;
- (void)buildArmRight;
- (void)buildLegLeft;
- (void)buildLegRight;

@end

#endif /* PersonBuilder_h */
