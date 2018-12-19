//
//  main.m
//  abstract-factory
//
//  Created by 王俊 on 2018/12/19.
//  Copyright © 2018 王俊. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "./abstract-factory/object/User.h"
#import "./abstract-factory/object/Department.h"
#import "abstract-factory/factory/SqlServerFactory.h"
#import "abstract-factory/factory/AccessFactory.h"
#import "./abstract-factory/runtime/DataAccess.h"
#import "./abstract-factory/sql/IUser.h"
#import "./abstract-factory/sql/IDepartment.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
//        NSLog(@"Hello, World!");
        
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
        // warning, 似乎命令行应用无法包含 plist 文件, 此处无效, 可查看 同级目录 abstract-factory-macos
        DataAccess *da = [[DataAccess alloc] init];
        id<IUser> daUser = [da createUser];
        id<IDepartment> daDept = [da createDepartment];
        
        [daUser insertUser:user];
        [daUser getUser:user.ID];
        
        [daDept insertDepartment:dept];
        [daDept getDepartment:dept.ID];
        
    }
    return 0;
}
