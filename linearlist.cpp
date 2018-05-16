#include "linearlist.h"
/*线性表顺序存储函数实现
*Time:2018.2.14
*author : spade
*version : 1.0
--------Start----------*/

Status InitList_Sq(SqList &L)
{
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L.elem) exit(OVERFLOW);
    L.length = 0  ;
    L.listsize = LIST_INIT_SIZE;
    return OK;
}//InitList_Sq


Status ListInsert_Sq (SqList &L , int i , ElemType e )
{
    ElemType * newbase;
    ElemType * p ;
    ElemType *q ;
    //在顺序线性表L中第i个位置插入新的元素e
    if ( i < 1 || i > L.length+1 ) return ERROR; //i 合法性判断
    if (L.length >= L.listsize )//空间已满 分配空间
    {
        newbase = (ElemType * )realloc(L.elem , L.listsize + LISTINCREMENT );
        if(!newbase) return ERROR;
        L.elem = newbase; //新基址
        L.listsize+=LISTINCREMENT;
    }
    q = &(L.elem[i-1]); //存储插入位置
    for (p = &(L.elem[L.length-1]); p >= q ; --p )
    {
        *(p+1)=*p ;
    }
    *q=e;
    L.length++;
    return OK;
}//在第i个位置插入e

void ListUnion(SqList &La , SqList Lb)
{
    int i ;
    int La_len=La.length, Lb_len=Lb.length;
    for (i=0 ; i<Lb.length ; i++)
    {
        ListInsert_Sq( La , ++La_len , Lb.elem[i]);
    }
    La.length = La_len+Lb_len;
}//合并ab不去相同值

Status ListDelete_Sq(SqList &L , int i , ElemType &e )
{
    if(!(0<i<L.length)) return ERROR; //判断i的合法性
    e=L.elem[i-1];
    for(i ; i<=L.length; i++)
    {
        L.elem[i-1]=L.elem[i];
    }
    L.length--;
    return OK;
} //删除第i个元素并用e返回

Status compare(ElemType a ,ElemType b)
{
    if (a==b) return 1;
    else return 0 ;
} //比较两个数据是否相同


Status LocateElem_Sq (SqList L , ElemType e ,Status(*pf)(ElemType , ElemType) )
{
    int i = 1 ;
    ElemType * p ;
    p=L.elem;
    while(i<=L.length && !(*pf)(*p++,e))   i++;
    if (i<=L.length) return i ;
    else return 0;
}//获取e位置 算法2.6



/*线性表链式存储结构函数实现
*Time：
*author：spade
-----------Start------------*/
Status GetElem_L(LinkList L , int i , ElemType &e ) //取出第i个元素给e
{

    //L为带头结点的单链表的头指针。
    //当第i个元素存在时赋值给e ， 否则返回ERROR
    LinkList p ;
    p = L->next;
    int j = 1;
    while(p && j<i )
    {
        p=p->next;
        j++;
    }
	if (!p || j>i)
		return ERROR;
	else
	{
		e = p->data;
		return OK;
	}

}//算法2.8 

Status ListInsert_L(LinkList &L, int i, ElemType e)
{
	//带头结点的单向链表L中第i个位置之前插入元素e
	LinkList p;
	int j; 
	p = L; j = 0;
	while (p && j < i - 1)
	{
		p = p->next;
		j++;
	}//寻找i-1节点 循环后j=i-1 p->next = i
	
	if (!p || j >= i - 1)
		return ERROR;

	LinkList s; 
	s = (LinkList)sizeof(LNode);
	s->data = e; s->next = p->next; 
	p->next = s;
	return OK;
} // 2.9 ListInsert_L


/*
已知p的位置指针，有两种插入方式：
	1.前插法，利用while循环，找到p的前一个节点。时间复杂度为O（n）
	2.直接在p后面插入，然后交换数据域。O(1)
*/

Status ListInsert_HC(LinkList &L, LinkList p, ElemType e)
{
	LinkList s;
	s = (LinkList)malloc(sizeof(LNode));
//	/*先把s插在p的后面*/
	s->data = e; s->next = p->next;
	p->next = s;

//	/*交换数据域*/
	ElemType temp;
	temp = p->data;  p->data = s->data; s->data = temp;

	return OK;
}//一直p的指针，后插法，然后交换数据域。


Status ListDelete_L(LinkList &L, int i, ElemType e)
{
	//在带头结点的单链表删除i个元素
	LinkList p;
	int j;
	p = L;j = 0;
	while (p && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (!p || j>=i)
	{
		return ERROR;
	}
	e = p->data;
	LinkList q;
	q = p->next;
	p->next = q->next;
	free(q);
	return OK;	
}//ListDelete_L 2.10


void CreateList_L(LinkList &L, int n)
{
	//逆序输入n个元素的值，建立带头结点的单链线性表L。
	LinkList p; 
	int i;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;// 先建立一个带有头结点的的单链表
	for (i = n;i > 0;--i)
	{
		p = (LinkList)malloc(sizeof(LNode));
		//scanf("%d",&p->data);
		p ->next = L->next;
		L->next = p;
	}
}//CreateList_L 2.11

void MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc)
{
	//已知单链线性表按照La Lb按值非递减排列
	//归并La和Lb得到新的单链线性表Lc，Lc的值也按照非递减排列 
	LinkList pa , pb , pc  ; 
	pa = La->next ; pb = Lb->next ;
	Lc=pc = La ;//以La的头结点作为Lc的头结点
	while(pa && pb)
	{
		if (pa->data <= pb->data)
		{
			pc->next = pa ; pc = pa ; pa = pa->next;
		}
		else 
		{
			pc->next = pb ; pc = pb ; pc=pc->next;
		}
	}
	pc->next = pa ? pa : pb; //echos if (pa) pc->next=pa ; else pc->next=pb
	free(Lb);
}//MergeList_L 2.12

/*

没有指针的静态链表

*/

int LocateElem_SL(SLinkList S , ElemType e)
{
	//静态单链线性表L中查找第1个值为e的元素。
	//若找到，则返回它在L中的位序，否则返回0
	int i;
	i=S[0].cur;
	while (i && S[i].data!=e) i=S[i].cur;
	return i; 
}//2.13

/*-----------------------例题2-3----------------------------------*/
/*
 *space相当于一个存储集合（没有数据的链表），初始化后，里面有排序号的存储单位
 *S是新建的一个链表的头结点，这个头结点是从space里面拿出来的
 *通过S这个头结点，就可以将新拿出来的spade[i]数据块重新链接成一个新的链表
 * Free操作相当于把S的链表space[i]块重新放到space备用链表中。
 * */

void InitSpace_SL(SLinkList &space)
{
	//讲一位数组space中各分量链成一个备用链表，space[0].cur 作为头指针
	//“0”表示空指针
	int i ; 
	for (i=0;i<MAXSIZE-1; ++i) space[i].cur = i+1;
	space[MAXSIZE-1].cur = 0 ;
}//InitSpace_SL 2.14

int Malloc_SL(SLinkList & space)
{
	//分配空间函数，如果索要空间为非空，则分配空间
	int i=space[0].cur ; //头结点下一个节点 
	if (space[0].cur) //头结点下一个节点非空
		space[0].cur = space[i].cur ; //将头结点指向 下 下 个节点，摘取标号i
	return i ;
}//索要空间2.15

void Free_SL(SLinkList & space,int k )
{
	//Free节点
	space[k].cur=space[0].cur;
	space[0].cur=k;
}//2.16

void difference (SLinkList & space , int &S)
{
	//依次输入A和B的元素，在一位数组space中建立表示集合（A-B）并（B-A）的
	//静态链表，S为其头指针，假设备用空间足够大，space[0].cur为其头指针
	int j , i ,m , n , r ;
	InitSpace_SL(space);//初始化备用空间
	S=Malloc_SL(space);//生成S头结点i=1
	r=S; //r=1
	printf("请输入：pelase Input\n");
	scanf("%d %d", &m, &n); //输入A和B的数据个数

	for(j = 1 ; j<= m; ++j)
	{
		i=Malloc_SL(space);
		scanf("%d",&space[i].data); //i=2
		space[r].cur=i; //i=3
		r=i;
	}
	space[r].cur = 0;

	for (j = 1;j <= n;j++)
	{
		ElemType b;
		scanf("%d",&b);
		int k,p;
		k = space[S].cur;//k等于头结点

		while (space[k].data != b && k!=space[r].cur)//判断是否存在
		{
			p = k; //保存k的上一个节点信息
			k = space[k].cur;
		}
		
		if (k == space[r].cur)//b不存在，插入A中
		{
			i = Malloc_SL(space); //申请内存序号
			space[i].data = b;
			space[i].cur = space[r].cur; //连接到标尾
			space[r].cur = i;
			r = i;
			//space[r].cur = i ; //这里结束后space[i]变成表尾了！！！！！！
		}//if
		else {//A中存在输的b ,删除位置为k的数据块
			space[p].cur = space[k].cur;
			Free_SL(space, k);
			if (r == k) r = p; 
		}//else
	}//for
}//different 2.17

/*-----------------------例题2-3-finish-----------------------------*/


