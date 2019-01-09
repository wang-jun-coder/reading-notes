//
//  HandsetBrand.h
//  bridge
//
//  Created by 王俊 on 2019/1/9.
//  Copyright © 2019 王俊. All rights reserved.
//
#import "./HandsetSoft.h"

#ifndef HandsetBrand_h
#define HandsetBrand_h

@protocol HandsetBrand <NSObject>

@required;
@property (nonatomic, strong) id<HandsetSoft> soft;

- (void)run;

@end


#endif /* HandsetBrand_h */
