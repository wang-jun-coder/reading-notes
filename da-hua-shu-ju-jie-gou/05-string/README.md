# 串


## 串的定义
**串： 串（string）是由零个或多个字符组成的有限序列，又名叫字符串。一般记为： s = "a<sub>1</sub>a<sub>2</sub>...a<sub>n</sub>", 串中的字符数目 n 称为串的长度， 零个字符的串称为空串（null string）**

## 串的比较
给定两个串： **s = "a<sub>1</sub>a<sub>2</sub>...a<sub>n</sub>"， t="b<sub>1</sub>b<sub>2</sub>...b<sub>m</sub>", 当满足以下条件之一时，s < t**   
1. **n < m, 且 a<sub>i</sub> = b<sub>i</sub> (i=1,2, ..., n)**    如：s="hap", t="happy".  
2. **存在某个 k < min(m,n), 使得， a<sub>i</sub> = b<sub>i</sub> (i=1,2, ..., k-1), a<sub>k</sub> < b<sub>k</sub>**   如：s="happen", t="happy".  

## 串的抽象数据类型
```c
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
```
### 串的 Index 实现
```c
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
```
## 串的存储结构
### 串的顺序存储结构实现
```c
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
```
## KMP 模式匹配算法
### KMP 模式匹配算法实现
```c
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

```

### KMP 模式匹配算法的改进

```c
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

```
