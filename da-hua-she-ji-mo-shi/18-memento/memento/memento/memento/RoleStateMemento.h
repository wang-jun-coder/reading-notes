//
//  RoleStateMemento.h
//  memento
//
//  Created by 王俊 on 2018/12/27.
//  Copyright © 2018 王俊. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RoleStateMemento : NSObject
@property (nonatomic, assign) NSInteger vitality;
@property (nonatomic, assign) NSInteger attack;
@property (nonatomic, assign) NSInteger defense;

- (instancetype)initWithVitality:(NSInteger)vitality andAttack:(NSInteger)attack andDefense:(NSInteger)defense;
@end

NS_ASSUME_NONNULL_END
