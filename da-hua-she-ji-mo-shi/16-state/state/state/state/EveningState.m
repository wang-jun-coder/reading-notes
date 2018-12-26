//
//  EveningState.m
//  state
//
//  Created by 王俊 on 2018/12/26.
//  Copyright © 2018 王俊. All rights reserved.
//

#import "EveningState.h"
#import "Work.h"
#import "SleepingState.h"
#import "RestState.h"

@implementation EveningState

- (void)writeProgram:(Work *)work {
    
    if(work.taskFinished){
        work.state = [RestState new];
        [work writeProgram];
        return;
    }
    
    if (work.hour < 21) {
        NSLog(@"当前时间: %f点, 加班哦, 疲累至极", work.hour);
        
    } else {
        work.state = [SleepingState new];
        [work writeProgram];
    }
}
@end
