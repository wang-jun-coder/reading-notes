//
//  Action.h
//  visitor
//
//  Created by 王俊 on 2019/1/10.
//  Copyright © 2019 王俊. All rights reserved.
//

#ifndef Action_h
#define Action_h

@class Man;
@class Woman;

@protocol Action <NSObject>

@required
- (void)getManConclusion:(Man *)man;
- (void)getWomanConclusion:(Woman *)woman;

@end


#endif /* Action_h */
