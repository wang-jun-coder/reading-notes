//
//  String.c
//  string
//
//  Created by 王俊 on 2019/3/19.
//  Copyright © 2019 王俊. All rights reserved.
//

#include "String.h"
#include <string.h>
#include <stdlib.h>

#pragma mark - test
void StringTest(void) {
    printf("================ StringTest ================\n");
    
    char c1[] = {'a', 'b', 'c', 'd', 'a', 'b', 'c', '\0'};
    char c2[] = {'c', 'd', '\0'};
    
    String s1 = c1;
    String s2 = c2;
    
    printf("s1: %s\ns2: %s\n", s1, s2);
    
    int pos = Index(s1, s2, 0);
    printf("Index: s1: %s, s2: %s, pos: %d\n",s1, s2, pos);
    
    
}


#pragma mark - functions
int Index(String S, String T, int pos) {
    int n, m, i;

    String sub;
//    if (pos>0) {
    
        n = StrLength(S);
        m = StrLength(T);
        i = pos;
        
        while (i<=n-m+1) {
            SubString(sub, S, i, m);
            if (StrCompare(sub, T) != 0) {
                ++i;
            } else {
                return i;
            }
        }
//    }
    return 0;
}

Status SubString(String Sub, String S, int pos, int len) {
    int total_length = (int)strlen(S);//首先获取srcstr的长度
    //判断srcstr的长度减去需要截取的substr开始位置之后，剩下的长度
    //是否大于指定的长度length，如果大于，就可以取长度为length的子串
    //否则就把从开始位置剩下的字符串全部返回。
    int real_length = ((total_length - pos) >= len ? len : (total_length - pos)) + 1;
    
    String tmp;
    if (NULL == (tmp=(char*)malloc(real_length * sizeof(char)))) {
        printf("Memory overflow . \n");
        exit(0);
    }
    strncpy(tmp, S+pos, real_length - 1);
    tmp[real_length - 1] = '\0';
    
    strcpy(Sub, tmp);
    return OK;
}

int StrLength(String S) {
    return (int)strlen(S);
}

int StrCompare(String S, String T) {
    return strcmp(S, T);
}
