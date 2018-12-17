//
//  main.m
//  template
//
//  Created by 王俊 on 2018/12/17.
//  Copyright © 2018 王俊. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "template/TestPaperA.h"
#import "template/TestPaperB.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
//        NSLog(@"Hello, World!");
        
        TestPaperA *a = [TestPaperA new];
        TestPaperB *b = [TestPaperB new];
        
        NSLog(@"========= A 试卷 =========");
        [a testQuestion1];
        [a testQuestion2];
        [a testQuestion3];
        
        NSLog(@"========= B 试卷 =========");
        [b testQuestion1];
        [b testQuestion2];
        [b testQuestion3];
    }
    return 0;
}
