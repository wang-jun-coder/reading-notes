//
//  Aggreagate.h
//  iterator
//
//  Created by 王俊 on 2018/12/28.
//  Copyright © 2018 王俊. All rights reserved.
//

#ifndef Aggreagate_h
#define Aggreagate_h

@protocol Iterator;
@protocol Aggregate <NSObject>

@required
- (id<Iterator>)createIterator;

- (NSUInteger)count;
- (id)firstObject;
- (void)addObject:(id)anObject;
- (id)objectAtIndex:(NSUInteger)index;


@end


#endif /* Aggreagate_h */
