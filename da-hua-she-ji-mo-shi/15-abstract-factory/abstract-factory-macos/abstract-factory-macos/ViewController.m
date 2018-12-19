//
//  ViewController.m
//  abstract-factory-macos
//
//  Created by 王俊 on 2018/12/19.
//  Copyright © 2018 王俊. All rights reserved.
//

#import "ViewController.h"

#import "User.h"
#import "Department.h"
#import "SqlServerFactory.h"
#import "AccessFactory.h"
#import "DataAccess.h"
#import "IUser.h"
#import "IDepartment.h"

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    // Do any additional setup after loading the view.
    // 抽象工厂模式
    User *user = [User new];
    Department *dept = [Department new];
    
    // sqlserver 工厂
    SqlServerFactory *ssFactory = [[SqlServerFactory alloc] init];
    id<IUser> sqlIUser = [ssFactory createUser];
    id<IDepartment> sqlDept = [ssFactory createDepartment];
    
    [sqlIUser insertUser:user];
    [sqlIUser getUser:user.ID];
    
    [sqlDept insertDepartment:dept];
    [sqlDept getDepartment:dept.ID];
    
    // access 工厂
    AccessFactory *accFactory = [[AccessFactory alloc] init];
    id<IUser> accUser = [accFactory createUser];
    id<IDepartment> accDept = [accFactory createDepartment];
    
    [accUser insertUser:user];
    [accUser getUser:user.ID];
    
    [accDept insertDepartment:dept];
    [accDept getDepartment:dept.ID];
    

    // 利用 oc 语言特性模拟反射, 使用通过 ./abstract-factory/runtime/config.plist db 属性配置, 可选 SqlServer 或 Access
    DataAccess *da = [[DataAccess alloc] init];
    id<IUser> daUser = [da createUser];
    id<IDepartment> daDept = [da createDepartment];
    
    [daUser insertUser:user];
    [daUser getUser:user.ID];
    
    [daDept insertDepartment:dept];
    [daDept getDepartment:dept.ID];
    
    
}


- (void)setRepresentedObject:(id)representedObject {
    [super setRepresentedObject:representedObject];

    // Update the view, if already loaded.
}


@end
