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
    int n, m, i;

    String sub;
//    if (pos>0) { // 暂未理解Index 的定义，若第0个字符就已重合如何处理，暂时注释
    
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
```
