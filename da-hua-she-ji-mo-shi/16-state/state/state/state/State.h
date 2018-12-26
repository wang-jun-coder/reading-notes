//
//  State.h
//  state
//
//  Created by 王俊 on 2018/12/26.
//  Copyright © 2018 王俊. All rights reserved.
//

#ifndef State_h
#define State_h

@class Work;
@protocol State <NSObject>

@required
- (void)writeProgram:(Work *)work;

@end


#endif /* State_h */
