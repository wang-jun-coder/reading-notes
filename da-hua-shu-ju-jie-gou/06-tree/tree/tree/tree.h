//
//  tree.h
//  tree
//
//  Created by 王俊 on 2019/3/27.
//  Copyright © 2019 王俊. All rights reserved.
//

#ifndef tree_h
#define tree_h

/**
 ADT 树（Tree）
 Data
    树是由一个根节点和若干棵子树构成。树中结点具有相同数据类型及层次关系。
 Operation
     InitTree(*T); 构造空树 T。
     DestoryTree(*T); 销毁树 T。
     CreateTree(*T, definition); 按 definition 中给出树的定义来构造树。
     ClearTree(*T); 若树 T 存在，则将树 T 清空。
     TreeEmpty(T); 若 T 为空树，返回 true 否则返回 false。
     TreeDepth(T); 返回 T 的深度。
     Root(T); 返回 T 的根结点。
     Value(T, cur_e); cur_e 是树 T 中一个结点，返回此结点的值。
     Assign(T, cur_e, value); 给树 T 的结点 cur_e 赋值为 value。
     Parent(T, cur_e); 若 cur_e 是树 T 的非根结点，则返回它的双亲，否则返回空。
     LeftChild(T, cur_e); 若 cur_e 是树 T 的非叶节点，则返回它的最左孩子，否则返回空。
     RightSibling(T, cur_e); 若 cur_e 有右兄弟，则返回它的右兄弟，否则返回空。
     InsertChild(*T,*p, i, c); 其中 p 指向树 T 的某个结点，i 为所指结点 p 的度加上1，非空树 c 与 T 不相交，操作结果为插入 c 为树 T 中 p 所指结点的第 i 棵子树。
     DeleteChild(*T, *p, i); 其中 p 指向树 T 的某个结点，i 为所指结点的 p 的度，操作结果为删除 T 中 p 所指结点的第 i 棵子树。
 endADT
 */


/* 树的双亲表示法结点结构定义 */
#define MAX_TREE_SIZE 100
typedef int TElemType;              // 树结点的数据类型, 目前暂定为整型

typedef struct PTNode {             // 结点结构
    TElemType data;                 // 结点数据
    int parent;                     // 双亲位置
} PTNode;

typedef struct {                    // 树结构
    PTNode nodes[MAX_TREE_SIZE];    // 结点数组
    int r, n;                       // 根的位置和结点数据
} PTree;


/* 树的孩子表示法结构定义 */
typedef struct CTNode {             // 孩子结点
    int child;
    struct CTNode *next;
} *ChildPtr;

typedef struct {                    // 表头结构
    TElemType data;
    ChildPtr firstChild;
} CTBox;

typedef struct {
    CTBox nodes[MAX_TREE_SIZE];     // 结点数组
    int r, n;                       // 根的位置和结点树
} CTree;


/* 树的孩子兄弟表示法结构定义 */
typedef struct CSNode {
    TElemType data;
    struct CSNode, *firstChild, *rightsib;
} CSNode, *CSTree;


/* 二叉树的二叉链表结点结构定义*/
typedef struct BiTNode {
    TElemType data;                     // 结点数据
    struct BiTNode *lchild, *rchild;    // 左右孩子指针
} BiTNode, *BiTree;

#endif /* tree_h */
