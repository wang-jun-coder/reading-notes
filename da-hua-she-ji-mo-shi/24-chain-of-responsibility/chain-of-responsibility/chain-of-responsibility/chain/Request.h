//
//  Request.h
//  chain-of-responsibility
//
//  Created by 王俊 on 2019/1/9.
//  Copyright © 2019 王俊. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString * RequestType NS_STRING_ENUM;
FOUNDATION_EXTERN RequestType const RequestTypeLeave;
FOUNDATION_EXTERN RequestType const RequestTypeRaises;

@interface Request : NSObject

@property (nonatomic, copy) RequestType type;
@property (nonatomic, copy) NSString *content;
@property (nonatomic, assign) NSInteger number;

- (instancetype)initWithType:(RequestType)type content:(NSString *)content number:(NSInteger)number;

@end

NS_ASSUME_NONNULL_END
