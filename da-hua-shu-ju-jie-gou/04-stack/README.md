# 栈与队列
栈是限定仅在表尾进行插入和删除操作的线性表  
队列是只允许在一端进行插入、而在另一端进行删除操作的线性表


##  栈的定义
**栈（stack）是限定仅在表尾进行插入和删除操作的线性表**

## 栈的抽象数据类型

```c
ADT 栈（stack）
Data 
	同线性表。元素具有相同的类型，相邻元素具有前驱和后继关系。
Operation
	InitStact(*S)	: 初始化操作，建立一个线性表 S。
	DestroyStack(*S): 若栈存在，则销毁它。
	ClearStack(*S): 将栈清空。
	StackEmpty(S): 若栈为空，返回 true，否则返回 false。
	GetTop(*S, *e): 若栈存在且非空，用 e 返回 S 的栈顶元素。
	Push(*S, e): 若栈 S 存在，插入新元素 e 到栈 S 中并成为栈顶元素。
	Pop(*S, *e): 删除栈 S 中栈顶元素，并用 e 返回其值。
	StackLength(S): 返回栈 S 的元素个数
endADT	
```
## 栈的顺序存储结构及实现
### 栈的顺序存储结构
```c
typedef struct {
    SElemType data[MAXSIZE];
    int top;    // 用于栈顶指针
} SqStack;
```
### 栈的顺序存储结构 -- 进栈操作
```c
Status SqStackPush(SqStack *S, SElemType e) {
    if (S->top == MAXSIZE-1) {
        return ERROR;
    }
    S->top++;
    S->data[S->top]=e;
    return OK;
}

```

### 栈的顺序存储结构 -- 出栈操作
```c
Status SqStackPop(SqStack *S, SElemType *e) {
    if (S->top <= -1) {
        return ERROR;
    }
    *e = S->data[S->top];
    S->top--;
    return OK;
}
```

## 两栈共享空间

### 两栈共享空间结构
```c
typedef struct {
    SElemType data[MAXSIZE];
    int top1;    // 栈1的栈顶指针
    int top2;    // 栈2的栈顶指针
} SqDoubleStack;
```
### 两栈共享空间结构的进栈操作
```c
Status SqDoubleStackPush(SqDoubleStack *S, SElemType e, int stackNumber) {
    // 栈满
    if (S->top1+1==S->top2) {
        return ERROR;
    }
    if(stackNumber==1){
        S->data[++S->top1] = e;
    }
    if (stackNumber==2) {
        S->data[--S->top2] = e;
    }
    return OK;
}
```
### 两栈共享空间结构的出栈操作
```c
Status SqDoubleStackPop(SqDoubleStack *S, SElemType *e, int stackNumber) {
    if(stackNumber==1) {
        if (S->top1 <= -1) {
            return ERROR;
        }
        *e = S->data[S->top1--];
    }
    if (stackNumber==2) {
        if (S->top2 >= MAXSIZE) {
            return ERROR;
        }
        *e = S->data[S->top2++];
    }
    return OK;
}
```

## 栈的链式存储结构及实现

### 栈的链式存储结构
```c
typedef struct {
    SElemType data;
    struct StackNode *next;
} StackNode, *LinkStackPtr;

typedef struct {
    LinkStackPtr top;
    int count;
} LinkStack;
```

### 栈的链式存储结构 -- 进栈
```c
Status LinkStackPush(LinkStack *S, SElemType e) {
    LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
    s->data = e;
    s->next = S->top;
    S->top = s;
    S->count ++;
    return OK;
}
```

### 栈的链式存储结构 -- 出栈
```c
Status LinkStackPop(LinkStack *S, SElemType *e) {
    LinkStackPtr p;
    if (LinkStackEmpty(*S)) {
        return ERROR;
    }
    *e = S->top->data;
    p = S->top;
    S->top = (StackNode *)S->top->next;
    free(p);
    S->count--;
    
    return OK;
}
```

## 栈的应用 -- 递归
### 裴波那契数列实现  

|1|2|3|4|5|6|7|8|9|10|11|12|
|:--|:--|:--|:--|:--|:--|:--|:--|:--|:--|:--|:--|
|1|1|2|3|5|8|13|21|34|55|89|144

```c
int Fibonacci(int i) {
    if (i<2) {
        return i==0?0:1;
    }
    return Fibonacci(i-1)+Fibonacci(i-2);
}

void FibonacciTest(void) {
    printf("========= FibonacciTest =========\n");
    for (int i=0; i<40; i++) {
        printf("i: %d -- fib: %d\n", i, Fibonacci(i));
    }
}
```
### 递归定义
**把一个直接调用自己或通过一系列的调用语句间接的调用自己的函数，称为递归函数**
**每个递归定义必须至少有一个条件，满足时递归不再进行，即不再引用自身而是返回值退出**

<!--## 栈的应用 -- 四则运算表达式求值-->
<!--### 后缀（逆波兰）表示法定义-->

