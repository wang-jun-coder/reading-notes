//
//  Player.h
//  adapter
//
//  Created by 王俊 on 2018/12/26.
//  Copyright © 2018 王俊. All rights reserved.
//

#ifndef Player_h
#define Player_h

@protocol Player <NSObject>

@required

@property(nonatomic, copy) NSString *name;

- (id<Player>)initWithName:(NSString *)name;
- (void)attack;
- (void)defense;

@end

#endif /* Player_h */
