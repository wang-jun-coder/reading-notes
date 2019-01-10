//
//  Person.h
//  visitor
//
//  Created by 王俊 on 2019/1/10.
//  Copyright © 2019 王俊. All rights reserved.
//

#ifndef Person_h
#define Person_h

@protocol Action;
@protocol Person <NSObject>

@required
- (void)accept:(id<Action>)visitor;

@end


#endif /* Person_h */
