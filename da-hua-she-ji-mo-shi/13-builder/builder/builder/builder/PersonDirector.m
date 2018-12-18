//
//  PersonDirector.m
//  builder
//
//  Created by 王俊 on 2018/12/18.
//  Copyright © 2018 王俊. All rights reserved.
//

#import "PersonDirector.h"

@interface PersonDirector ()

@property (nonatomic, strong) id<PersonBuilder> builder;

@end

@implementation PersonDirector

- (instancetype)initWithBuilder:(id<PersonBuilder>)builder {
    self = [super init];
    if(self) {
        self.builder = builder;
    }
    return self;
}

- (void)buildPerson {
    [self.builder buildHead];
    [self.builder buildBody];
    [self.builder buildArmLeft];
    [self.builder buildArmRight];
    [self.builder buildLegLeft];
    [self.builder buildLegRight];
}



@end
