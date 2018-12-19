//
//  IDepartment.h
//  abstract-factory
//
//  Created by 王俊 on 2018/12/19.
//  Copyright © 2018 王俊. All rights reserved.
//

#ifndef IDepartment_h
#define IDepartment_h

@class Department;
@protocol IDepartment <NSObject>

@required
- (void)insertDepartment:(Department *)dept;
- (Department *)getDepartment:(NSNumber *)ID;

@end

#endif /* IDepartment_h */
