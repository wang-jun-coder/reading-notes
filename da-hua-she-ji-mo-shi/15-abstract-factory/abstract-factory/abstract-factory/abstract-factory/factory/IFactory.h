//
//  IFactory.h
//  abstract-factory
//
//  Created by 王俊 on 2018/12/19.
//  Copyright © 2018 王俊. All rights reserved.
//

#ifndef IFactory_h
#define IFactory_h

@protocol IUser, IDepartment;
@protocol IFactory <NSObject>

@required
- (id<IUser>)createUser;
- (id<IDepartment>)createDepartment;


@end


#endif /* IFactory_h */
