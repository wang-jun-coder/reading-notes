//
//  main.m
//  interpreter
//
//  Created by 王俊 on 2019/1/10.
//  Copyright © 2019 王俊. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "interpreter/PlayContext.h"
#import "interpreter/ExpressionFactory.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
//        NSLog(@"Hello, World!");
        
        PlayContext *context = [PlayContext new];
        context.playText = @"T 500 O 2 E 0.5 G 0.5 A 3 E 0.5 G 0.5 D 3 E 0.5 G 0.5 A 0.5 O 3 C 1 O 2 A 0.5 G 1 C 0.5 E 0.5 D 3 ";
        ExpressionFactory *f = [ExpressionFactory new];
        
        @try {
            while (context.playText && context.playText.length > 0) {
                NSString *str = [context.playText substringWithRange:NSMakeRange(0, 1)];
                id<Expression> e = [f createExpressionWithKey:str];
                if (e) [e interpreter:context];
            }
        } @catch (NSException *exception) {
            NSLog(@"exception: %@", exception);
        } @finally {
            
        }
    }
    return 0;
}
