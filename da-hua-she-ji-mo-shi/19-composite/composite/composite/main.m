//
//  main.m
//  composite
//
//  Created by 王俊 on 2018/12/27.
//  Copyright © 2018 王俊. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "composite/ConcreteCompany.h"
#import "composite/HRDepartment.h"
#import "composite/FinanceDepartment.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
//        NSLog(@"Hello, World!");
        ConcreteCompany *root = [[ConcreteCompany alloc] initWithName:@"北京总公司"];
        [root addCompany:[[HRDepartment alloc] initWithName:@"总公司人力资源部"]];
        [root addCompany:[[FinanceDepartment alloc] initWithName:@"总公司财务部"]];
        
        
        ConcreteCompany *shanghai = [[ConcreteCompany alloc] initWithName:@"上海华东分公司"];
        [shanghai addCompany:[[HRDepartment alloc] initWithName:@"华东分公司人力资源部"]];
        [shanghai addCompany:[[FinanceDepartment alloc] initWithName:@"华东分公司财务部"]];
        [root addCompany:shanghai];
        
        ConcreteCompany *nanjing = [[ConcreteCompany alloc] initWithName:@"南京办事处"];
        [nanjing addCompany:[[HRDepartment alloc] initWithName:@"南京办事处人力资源部"]];
        [nanjing addCompany:[[FinanceDepartment alloc] initWithName:@"南京办事处财务部"]];
        [root addCompany:nanjing];
        
        ConcreteCompany *hangzhou = [[ConcreteCompany alloc] initWithName:@"杭州办事处"];
        [hangzhou addCompany:[[HRDepartment alloc] initWithName:@"杭州办事处人力资源部"]];
        [hangzhou addCompany:[[FinanceDepartment alloc] initWithName:@"杭州办事处财务部"]];
        [root addCompany:hangzhou];
        
        NSLog(@"结构图:");
        [root display:1];
        
        NSLog(@"职责:");
        [root lineOfDuty];
        
        
        
    }
    return 0;
}
