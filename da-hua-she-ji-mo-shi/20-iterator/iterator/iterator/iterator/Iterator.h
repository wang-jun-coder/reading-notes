//
//  Iterator.h
//  iterator
//
//  Created by 王俊 on 2018/12/28.
//  Copyright © 2018 王俊. All rights reserved.
//

#ifndef Iterator_h
#define Iterator_h

@protocol Iterator <NSObject>

@required
- (id)first;
- (id)next;
- (BOOL)isDone;
- (id)currentItem;


@end


#endif /* Iterator_h */
