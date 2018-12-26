//
//  Translator.m
//  adapter
//
//  Created by 王俊 on 2018/12/26.
//  Copyright © 2018 王俊. All rights reserved.
//

#import "Translator.h"
#import "ForeignCenter.h"

@interface Translator ()

@property(nonatomic, strong) ForeignCenter *wjzf;

@end

@implementation Translator
@synthesize name;

- (instancetype)init {
    self = [super init];
    if (self) {
        _wjzf = [ForeignCenter new];
    }
    return self;
}

- (id<Player>)initWithName:(NSString *)name {
    self = [self init];
    if (self) {
        self.wjzf.name = name;
    }
    return self;
}

- (void)attack {
    [self.wjzf jinGong];
}
- (void)defense {
    [self.wjzf fangShou];
}



@end
