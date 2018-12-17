//
//  Person.m
//  delegate
//
//  Created by 王俊 on 2018/12/17.
//  Copyright © 2018 王俊. All rights reserved.
//

#import "Person.h"

@interface Person ()
@property (nonatomic, copy) NSString *name;

@end

@implementation Person

#pragma mark - life cycle
- (instancetype)initWithName:(NSString *)name {
    self = [super init];
    if (self) {
        self.name = name;
    }
    return self;
}

- (void)giveDollsToPerson:(Person *)person {
    // 如果有代理就让代理帮忙
    if (self.delegate && [self.delegate respondsToSelector:@selector(helperPerson:giveDollsTo:)]) {
        [self.delegate helperPerson:self giveDollsTo:person];
        return;
    }
}

- (void)giveFlowersToPerson:(Person *)person {
    if (self.delegate && [self.delegate respondsToSelector:@selector(helperPerson:giveFlowersTo:)]) {
        [self.delegate helperPerson:self giveFlowersTo:person];
        return;
    }
}

- (void)giveChocolateToPerson:(Person *)person {
    if (self.delegate && [self.delegate respondsToSelector:@selector(helperPerson:giveChocolateTo:)]) {
        [self.delegate helperPerson:self giveChocolateTo:person];
        return;
    }
}

#pragma mark - GiveGift
- (void)helperPerson:(Person *)giver giveDollsTo:(Person *)receiver {
    NSLog(@"I'll give %@ a doll for someone %@", receiver.name, giver.name);
}
- (void)helperPerson:(Person *)giver giveFlowersTo:(Person *)receiver {
    NSLog(@"I'll give %@ flower for someone %@", receiver.name, giver.name);
}
- (void)helperPerson:(Person *)giver giveChocolateTo:(Person *)receiver {
    NSLog(@"I'll give %@ chocolate for someone %@", receiver.name, giver.name);
}



@end
