//
//  main.m
//  chain-of-responsibility
//
//  Created by 王俊 on 2019/1/9.
//  Copyright © 2019 王俊. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "./chain/Request.h"
#import "./chain/CommonManager.h"
#import "./chain/Majordomo.h"
#import "./chain/GeneralManager.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
//        NSLog(@"Hello, World!");
        CommonManager *jinli = [[CommonManager alloc] initWithName:@"金利"];
        Majordomo *zongjian = [[Majordomo alloc] initWithName:@"宗剑"];
        GeneralManager *zongjingli = [[GeneralManager alloc] initWithName:@"钟精励"];
        
        jinli.superior = zongjian;
        zongjian.superior = zongjingli;
        
        Request *req1 = [[Request alloc] initWithType:RequestTypeLeave
                                              content:@"小菜请假"
                                               number:1];
        [jinli requestApplications:req1];
        
        Request *req2 = [[Request alloc] initWithType:RequestTypeLeave
                                              content:@"小菜请假"
                                               number:4];
        [jinli requestApplications:req2];
        
        
        Request *req3 = [[Request alloc] initWithType:RequestTypeRaises
                                              content:@"小菜请求加薪"
                                               number:500];
        [jinli requestApplications:req3];
        
        Request *req4 = [[Request alloc] initWithType:RequestTypeRaises
                                              content:@"小菜请求加薪"
                                               number:1000];
        [jinli requestApplications:req4];
        
        
        
    }
    return 0;
}
