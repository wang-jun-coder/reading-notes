//
//  GameRole.m
//  memento
//
//  Created by 王俊 on 2018/12/27.
//  Copyright © 2018 王俊. All rights reserved.
//

#import "GameRole.h"
#import "RoleStateMemento.h"

@implementation GameRole

- (void)stateDisplay {
    NSLog(@"角色当前状态: ");
    NSLog(@"生命力: %ld", self.vitality);
    NSLog(@"攻击力: %ld", self.attack);
    NSLog(@"防御力: %ld", self.defense);
}

- (void)getInitState {
    self.vitality = 100;
    self.attack = 100;
    self.defense = 100;
}

- (void)fight {
    self.vitality = 0;
    self.attack = 0;
    self.defense = 0;
}

- (RoleStateMemento *)saveState {
    return [[RoleStateMemento alloc] initWithVitality:self.vitality andAttack:self.attack andDefense:self.defense];
}

- (void)recoveryState:(RoleStateMemento *)memento {
    self.vitality = memento.vitality;
    self.attack = memento.attack;
    self.defense = memento.defense;
}


@end
