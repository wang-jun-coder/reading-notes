//
//  Observer.h
//  observer
//
//  Created by 王俊 on 2018/12/19.
//  Copyright © 2018 王俊. All rights reserved.
//

#ifndef Observer_h
#define Observer_h


@protocol Observer <NSObject>

@required

- (void)updateWithState:(NSString *)state;

@end


#endif /* Observer_h */
