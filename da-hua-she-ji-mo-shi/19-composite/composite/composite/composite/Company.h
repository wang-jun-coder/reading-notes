//
//  Company.h
//  composite
//
//  Created by 王俊 on 2018/12/27.
//  Copyright © 2018 王俊. All rights reserved.
//

#ifndef Company_h
#define Company_h

@protocol Company <NSObject>

@required

@property (nonatomic, copy) NSString *name;

- (id<Company>)initWithName:(NSString *)name;
- (void)addCompany:(id<Company>)company;
- (void)removeCompany:(id<Company>)company;
- (void)display:(NSInteger)depth;
- (void)lineOfDuty;

@end

#endif /* Company_h */
