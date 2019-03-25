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
#include <math.h>

#pragma mark - test
void StringTest(void) {
    printf("================ StringTest ================\n");
    
    String s1;
    StrAssign(s1, "happend");
    
    printf("StrLength(%s): %d\n", s1, StrLength(s1));
    
    String s2;
    StrAssign(s2, "happy");
    printf("StrLength(%s): %d\n", s2, StrLength(s2));
    
    int result = StrCompare(s1, s2);
    printf("StrCompare(%s, %s): %d\n", s1, s2, result);
    
    String s3;
    Status status = Concat(s3, s1, s2);
    printf("Concat(%s, %s, %s): status: %d\n", s3, s1, s2, status);
    
    String s4;
    status = SubString(s4, s3, 1, 7);
    printf("SubString(%s, %s, %d, %d): status: %d\n", s4, s3, 1, 7, status);
    
    int index = Index(s3, s2, 1);
    printf("SubString(%s, %s, %d): index: %d\n", s3, s2, 1, index);
    
    status = StrDelete(s3, 8, 5);
    printf("StrDelete(%s, 8, 5)\n", s3);
    
    status = StrInsert(s3, 8, s2);
    printf("StrInsert(%s, 8, %s)\n", s3, s2);
    
    status = Replace(s3, s2, s1);
    printf("Replace(%s, %s, %s)\n", s3, s2, s1);
}


#pragma mark - functions
Status StrAssign(String S, char *chars) {
    for (int i=1; i<MAXSIZE; i++) {
        S[i] = *(chars+i-1);
        if(S[i] == '\0') {
            S[0] = i-1;
            break;
        }
    }
    return OK;
}
Status StrCopy(String T, String S) {
    for(int i=0;i<=S[0]; i++) {
        T[i] = S[i];
    }
    return OK;
}
Status ClearString(String S) {
    for(int i=0;i<=S[0]; i++) {
        S[i] = 0;
    }
    S[0] = 0;
    return OK;
}
Status StringEmpty(String S) {
    return S[0] == 0 ? TRUE : FALSE;
}
int StrLength(String S) {
    return S[0];
}
int StrCompare(String S, String T) {

    int len = fmin(StrLength(S), StrLength(T));
    
    // 循环对比每一个字符
    for (int i=0; i<len; i++) {
        char s = S[i+1];
        char t = T[i+1];
        if (s<t) {
            return -1; // S<T
        }
        if (s>t) {
            return 1; // S>T
        }
    }
    
    if (StrLength(S) == StrLength(T)) {
        return 0; // S==T
    } else if (StrLength(S)<StrLength(T)) {
        // S<T
        return -1;
    } else if (StrLength(S)>StrLength(T)) {
        // S>T
        return 1;
    }
    return OK;
}
Status Concat(String T, String S1, String S2) {
    int len1 = StrLength(S1);
    int len2 = StrLength(S2);
    if ( len1 + len2 > MAXSIZE) {
        return ERROR;
    }
    
    for (int i=1; i<=len1; i++) {
        T[i]=S1[i];
    }
    for (int i=1; i<=len2; i++) {
        T[len1+i] = S2[i];
    }
    T[0] = len1+len2;
    return OK;
}
Status SubString(String Sub, String S, int pos, int len) {
    if (pos<1||pos>MAXSIZE||pos>StrLength(S) || pos + len > StrLength(S)+1) {
        return ERROR;
    }
    for (int i=1; i<=len; i++) {
        Sub[i] = S[pos+i-1];
    }
    Sub[0] = len;
    return OK;
}
int Index(String S, String T, int pos) {
    int lenS = StrLength(S);
    int lenT = StrLength(T);
    int i=0;
    if (pos<1||pos>MAXSIZE||pos>lenS || pos + lenT > lenS+1) {
        return ERROR;
    }
    for (i=1; i<=lenS-lenT+1; i++) {
        String sub;
        SubString(sub, S, i, lenT);
        if (StrCompare(sub, T) == 0) {
            break;
        }
    }
    return i;
}
Status Replace(String S, String T, String V) {
    int pos = Index(S, T, 1);
    int len = StrLength(T);
    if (pos) {
        StrDelete(S, pos, len);
    }
    StrInsert(S, pos, V);
    return OK;
}
Status StrInsert(String S, int pos, String T) {
    int len = StrLength(T);
    int strLen = StrLength(S);
    
    for(int i=len; i>=0; i--) {
        int index = pos+i;
        if (index>strLen) {
            S[index] = T[i];
            continue;
        }
        S[index+len] = S[index];
        S[index] = T[i];
    }
    
    S[0] = strLen+len;
    return OK;
}
Status StrDelete(String S, int pos, int len) {
    int strLen = StrLength(S);
    
    for(int i=0; i<len; i++) {
        S[pos+i] = S[pos+len+i];
    }
    S[0] = strLen - len;
    return OK;
}
