//
//  ConcreteCompany.m
//  composite
//
//  Created by 王俊 on 2018/12/27.
//  Copyright © 2018 王俊. All rights reserved.
//

#import "ConcreteCompany.h"

@interface ConcreteCompany ()
@property (nonatomic, strong) NSMutableArray<id<Company>> *children;
@end

@implementation ConcreteCompany
@synthesize name;

- (id<Company>)initWithName:(NSString *)name {
    self = [super init];
    if (self) {
        self.name = name;
        self.children = [NSMutableArray array];
    }
    return self;
}

- (void)addCompany:(id<Company>)company {
    [self.children addObject:company];
}
- (void)removeCompany:(id<Company>)company {
    [self.children removeObject:company];
}

- (void)display:(NSInteger)depth {
    NSMutableString *display = [NSMutableString string];
    NSInteger d = depth;
    while (d>0) {
        [display appendString:@"-"];
        d--;
    }
    [display appendString:self.name];
    NSLog(@"%@", display);
    for (id<Company> company in self.children) {
        [company display:depth+2];
    }
}

- (void)lineOfDuty {
    for (id<Company> company in self.children) {
        [company lineOfDuty];
    }
}


@end
