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
    
    index = SimplicityIndex(s3, s1, 2);
    printf("SimplicityIndex(%s, %s, 2) = %d\n", s3, s1, index);
    
    index = Index_KMP(s3, s1, 1);
    printf("Index_KMP(%s, %s, 2) = %d\n", s3, s1, index);
    
    String aabbaa;
    StrAssign(aabbaa, "aabbaa");
    int next[255];
    get_next(aabbaa, next);
    printf("get_next(%s, next)\n", aabbaa);
    for (int i=1; i<StrLength(aabbaa); i++) {
        printf("%d -- %d\n", i, next[i]);
    }
    
    int nextval[255];
    get_nextval(aabbaa, nextval);
    printf("get_nextval(%s, next)\n", aabbaa);
    for (int i=1; i<StrLength(aabbaa); i++) {
        printf("%d -- %d\n", i, next[i]);
    }
    
    String abccbaabccba;
    StrAssign(abccbaabccba, "abccbaabccba");
    int next2[255];
    get_next(abccbaabccba, next2);
    printf("get_next(%s, next2)\n", abccbaabccba);
    for (int i=1; i<StrLength(abccbaabccba); i++) {
        printf("%d -- %d\n", i, next2[i]);
    }
    int nextval2[255];
    get_nextval(abccbaabccba, nextval2);
    printf("get_nextval(%s, nextval2)\n", abccbaabccba);
    for (int i=1; i<StrLength(aabbaa); i++) {
        printf("%d -- %d\n", i, nextval2[i]);
    }
    
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
            return i;
        }
    }
    return 0;
}


/**
 朴素的模式匹配算法

 @param S 原字符串
 @param T 要查找的字符串
 @param pos 从原字符串的指定位置开始查找
 @return 要查找的字符串在原串中的位置, 若不存在则返回0
 */
int SimplicityIndex(String S, String T, int pos) {
    int i=pos;
    int j=1;
    
    int lenS = StrLength(S), lenT = StrLength(T);
    
    while (i<=lenS && j <= lenT) {
        if (S[i] == T[j]) {
            ++i;
            ++j;
        } else {
            i = i-j+2;
            j = 1;
        }
    }
    if (j > lenT) {
        return i-lenT;
    } else {
        return 0;
    }
}

/**
 克努特-莫斯里斯-普拉特算法(KMP 算法)

 @param S 原字符串
 @param T 要查找的字符串
 @param pos 开始查找的位置
 @return 查到的开始位置
 */
int Index_KMP(String S, String T, int pos) {
    int i=pos;
    int j = 1;
    
    int next[255];
    get_next(T, next);
    int lenS = StrLength(S);
    int lenT = StrLength(T);
    
    while (i<lenS && j <= lenT) {
        if (j == 0 || S[i] == T[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
    }
    
    if (j > lenT) {
        return i - T[0];
    }
    return 0;
};


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
    
    for(int i=len; i>0; i--) {
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

#pragma mark - private

/**
 计算字符串的 next[j] 的值, 用于 KMP 匹配算法

 @param T 要计算的字符串
 @param next 数组指针
 */
void get_next(String T, int *next) {
    int i, j;
    i = 1;
    j = 0;
    next[i]=0; // 第一位为0
    int len = StrLength(T);
    while (i<len) {
        if (j==0 || T[i] == T[j]) { // T[i] 表示后缀的单个字符, T[j] 表示前缀的单个字符
            ++i;
            ++j;
            next[i] = j;
        } else {
            j = next[j]; // 若字符不同, 则 j 值回溯
        }
    }
}

/**
 求模式串 T 的 next 函数修正值, 并存入数组nextval
 */
void get_nextval(String T, int *nextval) {
    int i, j;
    i = 1;
    j = 0;
    nextval[i] = 0;
    int len = StrLength(T);
    while (i < len) {
        if (j == 0 || T[i] == T[j]) {
            ++i;
            ++j;
            if (T[i] != T[j]) {
                nextval[i] = j;
            } else {
                nextval[i] = nextval[j];
            }
        } else {
            j = nextval[j];
        }
    }
    
}
