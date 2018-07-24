#ifndef __TREE_H
#define __TREE_H
#include "head_usr.h"
typedef int TElemType;

//Start
/* 二叉树顺序存储结构 */
#define MAX_TREE_SIZE 100 //二叉树的最大节点数
typedef TElemType SqBiTree[MAX_TREE_SIZE];  //0号单元存储根节点
//SqBiTree bt;  

/* 二叉树的链式存储结构 */
typedef struct BiTNode 
{
    TElemType data;
    struct BiTNode * lchild , *rchild  ; //左右孩子节点
}BiTNode,*BiTree;

/* 线索二叉树的存储格式 */
enum PointerTag{ Link , Thread};
typedef struct BiThrNode{
    TElemType data;
    struct BiThrNode * lchild , * rchild ;
    PointerTag  LTag , RTag ;
}BiThrNode ,* BiThrTree;


#endif

/* 二叉树的链式存储结构函数声明 */
Status CreateBiTree(BiTree &T);
Status Visit (TElemType);
