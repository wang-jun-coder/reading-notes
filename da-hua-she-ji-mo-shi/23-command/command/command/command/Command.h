//
//  Command.h
//  command
//
//  Created by 王俊 on 2019/1/9.
//  Copyright © 2019 王俊. All rights reserved.
//

#ifndef Command_h
#define Command_h

@class Barbecuer;
@protocol Command <NSObject>

@required;
- (id<Command>)initWithBarbecuer:(Barbecuer *)barbecuer;

- (void)excuteCommand;

@end

#endif /* Command_h */
