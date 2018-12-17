//
//  main.m
//  decorator
//
//  Created by 王俊 on 2018/12/17.
//  Copyright © 2018 王俊. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "decorator/Person.h"

#import "decorator/TShirts.h"
#import "decorator/BigTrousers.h"
#import "decorator/Sneakers.h"
#import "decorator/Suits.h"
#import "decorator/Ties.h"
#import "decorator/LeatherShoes.h"


int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
//        NSLog(@"Hello, World!");
        
        Person *person = [[Person alloc] initWithName:@"小明"];
        
        // 装饰
        TShirts *shirt = [[TShirts alloc] initWithPerson:person];
        Ties *tie = [[Ties alloc] initWithPerson:shirt];
        BigTrousers *trouser = [[BigTrousers alloc] initWithPerson:tie];
        LeatherShoes *shose = [[LeatherShoes alloc] initWithPerson:trouser];
        
        [shose show];
        
        
        
    }
    return 0;
}
