#ifndef __LINEARLIST_H
#define __LINEARLIST_H
#include <stdio.h>
#include "head_usr.h"
#endif // __LINEARLIST_
#define _CRT_NONSTDC_NO_WARNINGS
#define LIST_INIT_SIZE 100  //线性表存储空间初始分配
#define LISTINCREMENT 10 //线性表增量
/*线性表的顺序存储结构声明 start
* data :2018.2.13
* author : spad
---------start-------------*/
typedef struct SqList_tag{
    ElemType * elem; //存储空址（存储ElemType性）
    int     length;
    int     listsize;
}SqList;


/*线性表的链式存储结构声明 start
* data :2018.2.13
* author : spade
---------start-------------*/
typedef struct LNode_tag{
    ElemType data ;
    struct LNode_tag * next ;
}LNode, *LinkList;



/*线性表链式静态存储结构声明
* date 2018.3.16
* author ：spade 
---------start----------*/
#define MAXSIZE 1000
typedef struct SLNode_tag {
	ElemType data;
	int cur; 
}component,SLinkList[MAXSIZE] ;



/*线性表顺序存储函数说明*/
Status InitList_Sq(SqList &L); //初始化列表
Status ListInsert_Sq (SqList &L , int i , ElemType e ); //插入e
void ListUnion(SqList &La , SqList Lb); // ab 联合
Status ListDelete_Sq(SqList &L , int i , ElemType &e ); //删除i个元素  用e返回 
Status LocateElem_Sq (SqList L , ElemType e ,Status(*pf)(ElemType , ElemType) );  //获取e的位置
Status compare(ElemType,ElemType); // 


/*线性表链式存储函数说明*/
Status GetElem_L(LinkList L, int i, ElemType &e);
Status ListInsert_L(LinkList &L, int i, ElemType e);
Status ListInsert_HC(LinkList &L, LinkList p, ElemType e);
Status ListDelete_L(LinkList &L, int i, ElemType e);
void CreateList_L(LinkList &L,int n );
void MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc);

/*

没有指针的静态链表

*/
int LocateElem_SL(SLinkList S, ElemType e);
void InitSpace_SL(SLinkList &space);
int Malloc_SL(SLinkList & space);
void InitSpace_SL(SLinkList &space);
int Malloc_SL(SLinkList & space);
void Free_SL(SLinkList & space, int k);
void difference(SLinkList & space, int &S);

