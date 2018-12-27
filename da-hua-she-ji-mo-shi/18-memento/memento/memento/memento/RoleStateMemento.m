//
//  RoleStateMemento.m
//  memento
//
//  Created by 王俊 on 2018/12/27.
//  Copyright © 2018 王俊. All rights reserved.
//

#import "RoleStateMemento.h"

@implementation RoleStateMemento
- (instancetype)initWithVitality:(NSInteger)vitality andAttack:(NSInteger)attack andDefense:(NSInteger)defense {
    self = [super init];
    if (self) {
        self.vitality = vitality;
        self.attack = attack;
        self.defense = defense;
    }
    return self;
}

@end
