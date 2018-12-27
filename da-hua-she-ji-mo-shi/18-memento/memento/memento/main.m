//
//  main.m
//  memento
//
//  Created by 王俊 on 2018/12/27.
//  Copyright © 2018 王俊. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "./memento/GameRole.h"
#import "./memento/RoleStateMemento.h"
#import "./memento/RoleStateCaretaker.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
//        NSLog(@"Hello, World!");
        
        // 战斗前
        GameRole *lixiaoyao = [GameRole new];
        [lixiaoyao getInitState];
        [lixiaoyao stateDisplay];
        
        // 保存进度
        RoleStateCaretaker *stateAdmin = [RoleStateCaretaker new];
        stateAdmin.memento = [lixiaoyao saveState];
        
        // 战斗后
        [lixiaoyao fight];
        [lixiaoyao stateDisplay];
        
        // 恢复状态
        [lixiaoyao recoveryState:stateAdmin.memento];
        [lixiaoyao stateDisplay];
        
        
    }
    return 0;
}
