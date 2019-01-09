//
//  UNSecurityCouncli.h
//  mediator
//
//  Created by 王俊 on 2019/1/9.
//  Copyright © 2019 王俊. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UnitedNations.h"
#import "USA.h"
#import "Iraq.h"

NS_ASSUME_NONNULL_BEGIN

@interface UNSecurityCouncli : NSObject<UnitedNations>

@property (nonatomic, weak) USA *usa;
@property (nonatomic, weak) Iraq *iraq;

@end

NS_ASSUME_NONNULL_END
