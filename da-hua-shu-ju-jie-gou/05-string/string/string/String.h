//
//  String.h
//  string
//
//  Created by 王俊 on 2019/3/19.
//  Copyright © 2019 王俊. All rights reserved.
//

#ifndef String_h
#define String_h

#include <stdio.h>

/**
 ADT 串（String）
 Data
    串中元素仅由一个字符组成，相邻元素具有前驱和后继关系。
 Operation
     StrAssign(T, *chars); 生成一个其值等于字符串常量 chars 的串 T。
     StrCopy(T, S); 串 S 存在，由串 S 复制得到串 T。
     ClearString(S); 串 S 存在，将串清空
     StringEmpty(S); 若串 S 为空，返回 true 否则返回 false
     StrLength(S); 返回串 S 的元素个数，即串的长度
     StrCompare(S, T); 若 S>T, 返回值>0， 若 S=T, 返回0，若 S < T
     Concat(T, S1, S2); 用 T 返回由 S1 和 S2 链接而成的新串
     SubString(Sub, s, pos, len); 串 S 存在，1 <= pos <= StrLength(S), 且 0<=len<=StrLength(S)-pos+1, 用 Sub 返回串 S 的第 pos 个字符起长度为 len 的子串。
     Index(S, T, pos); 若 S 和 T 存在，T 是非空串，1<=pos<=StrLength(S)。若主串 S 中存在和 T 值相同的子串，则返回它在主串中第 pos 个字符之后第一次出现的位置，否则返回0
     Replace(S, T, V); 串 S T 和 V 存在，T 是非空串，用 V 替换主串 S 中出现的所有与 T 相等的不重叠的子串。
     StrInsert(S, pos, T); 串 S 和 T 存在，1<=pos<=StrLength(S)+1。在串 S 的第 pos 个字符之前插入串 T
     StrDelete(S, pos, len); 串 S 存在，1<=pos<=StrLength(S)-len+1。从串 S 中删除第 pos 个字符起长度为 len 的字符串
 endADT
 */
// 相关操作状态定义
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int  Status;            // Status 是函数的类型,其值是函数结果状态码,如 OK 等
#define MAXSIZE 100

typedef char String[MAXSIZE+1]; // 串的顺序存储结构,第0位用于存储串的长度

#pragma mark - functions
Status StrAssign(String S, char *chars);
Status StrCopy(String T, String S);
Status ClearString(String S);
Status StringEmpty(String S);
int StrLength(String S);
int StrCompare(String S, String T);
Status Concat(String T, String S1, String S2);
Status SubString(String Sub, String S, int pos, int len);
int Index(String S, String T, int pos);
Status Replace(String S, String T, String V);
Status StrInsert(String S, int pos, String T);
Status StrDelete(String S, int pos, int len);

#pragma mark - test

void StringTest(void);

#endif /* String_h */
