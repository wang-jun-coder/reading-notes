//
//  main.m
//  visitor
//
//  Created by 王俊 on 2019/1/10.
//  Copyright © 2019 王俊. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "visitor/Success.h"
#import "visitor/Failing.h"
#import "visitor/Amativeness.h"

#import "visitor/Man.h"
#import "visitor/Woman.h"
#import "visitor/ObjectStructure.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
//        NSLog(@"Hello, World!");
        ObjectStructure *o = [ObjectStructure new];
        
        [o attach:[Man new]];
        [o attach:[Woman new]];
        
        Success *s = [Success new];
        [o display:s];
        
        Failing *f = [Failing new];
        [o display:f];
        
        Amativeness *a = [Amativeness new];
        [o display:a];
        
    }
    return 0;
}
